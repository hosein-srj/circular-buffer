#include "CircularBuffer.h"

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size)
{
    setUp(size);
}

template <typename T>
void CircularBuffer<T>::setUp(size_t size)
{
    std::lock_guard<std::mutex> lock(ch_lock);
    buffer_size = size;
    writed_size = 0;
    head = 0;
    tail = 0;
    buffer.assign(size, T());  // Initialize with default value of T
}

template <typename T>
void CircularBuffer<T>::write(const T* data, size_t len)
{
    std::lock_guard<std::mutex> lock(ch_lock);
    if (len > buffer_size - writed_size) {
        std::cerr << "Overflow: Not enough space in buffer\n";
        return;
    }

    size_t first_part = std::min(len, buffer_size - head);
    size_t second_part = len - first_part;

    std::copy(data, data + first_part, buffer.begin() + head);
    std::copy(data + first_part, data + len, buffer.begin());

    head = (head + len) % buffer_size;
    writed_size += len;
}

template <typename T>
std::vector<T> CircularBuffer<T>::read(size_t len)
{
    std::lock_guard<std::mutex> lock(ch_lock);
    std::vector<T> out;

    if (len > writed_size) {
        std::cerr << "Not enough data available\n";
        return out;
    }

    out.resize(len);
    size_t first_part = std::min(len, buffer_size - tail);
    size_t second_part = len - first_part;

    std::copy(buffer.begin() + tail, buffer.begin() + tail + first_part, out.begin());
    std::copy(buffer.begin(), buffer.begin() + second_part, out.begin() + first_part);

    tail = (tail + len) % buffer_size;
    writed_size -= len;

    return out;
}

template <typename T>
bool CircularBuffer<T>::isFull(size_t len) const
{
    std::lock_guard<std::mutex> lock(ch_lock);
    return writed_size + len > buffer_size;
}

template <typename T>
bool CircularBuffer<T>::hasEnoughData(size_t len) const
{
    std::lock_guard<std::mutex> lock(ch_lock);
    return writed_size >= len;
}

template <typename T>
void CircularBuffer<T>::reset()
{
    std::lock_guard<std::mutex> lock(ch_lock);
    writed_size = 0;
    head = 0;
    tail = 0;
}
