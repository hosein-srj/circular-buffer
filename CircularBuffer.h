#include <vector>
#include <iostream>
#include <mutex>

template <typename T>
class CircularBuffer
{
public:
    explicit CircularBuffer(size_t size = 0);
    ~CircularBuffer() = default;

    void setUp(size_t size);
    void write(const T* data, size_t len);
    std::vector<T> read(size_t len);

    bool isFull(size_t len) const;
    bool hasEnoughData(size_t len) const;
    void reset();

private:
    size_t buffer_size = 0;
    size_t writed_size = 0;
    size_t head = 0;
    size_t tail = 0;

    std::vector<T> buffer;
    mutable std::mutex ch_lock;
};

