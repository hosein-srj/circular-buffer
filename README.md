# CircularBuffer - A Generic Thread-Safe Circular Buffer in C++

## Overview

This is a **thread-safe, templated circular buffer** implemented in C++ that supports **any data type**. It efficiently manages data in a fixed-size buffer, allowing seamless writing and reading operations without reallocations.

Key Features:
- **Generic Support**: Works with `int`, `float`, `std::string`, or any user-defined type.
- **Thread-Safe**: Uses `std::mutex` to ensure concurrent access safety.
- **Efficient Memory Usage**: Uses `std::vector<T>` internally to manage data efficiently.
- **Automatic Wrap-Around**: Handles buffer overflow naturally without extra copying.

---

## Installation

Simply clone this repository and include the **`CircularBuffer.h`** file in your project.


# CircularBuffer - A Generic Thread-Safe Circular Buffer in C++

## Overview

This is a **thread-safe, templated circular buffer** implemented in C++ that supports **any data type**. It efficiently manages data in a fixed-size buffer, allowing seamless writing and reading operations without reallocations.

### **Key Features**
- ✅ **Generic Support**: Works with `int`, `float`, `std::string`, or any user-defined type.
- ✅ **Thread-Safe**: Uses `std::mutex` to ensure concurrent access safety.
- ✅ **Efficient Memory Usage**: Uses `std::vector<T>` internally to manage data efficiently.
- ✅ **Automatic Wrap-Around**: Handles buffer overflow naturally without extra copying.

---

## Installation

Simply clone this repository and include the **`CircularBuffer.h`** file in your project.

```sh
git clone https://github.com/YOUR_GITHUB_USERNAME/CircularBuffer.git
```

Include the header file in your C++ project:
```cpp
#include "CircularBuffer.h"
```

---

## Usage

### **1. Creating a Circular Buffer**
Instantiate a buffer of any data type:
```cpp
#include "CircularBuffer.h"

int main() {
    CircularBuffer<int16_t> buffer(100);  // Buffer for int16_t with size 100
    return 0;
}
```

### **2. Writing Data**
```cpp
int16_t data[] = {1, 2, 3, 4, 5};
buffer.write(data, 5);
```

### **3. Reading Data**
```cpp
auto result = buffer.read(3);
for (auto val : result) {
    std::cout << val << " ";
}
```
📌 **Output:** `1 2 3`

### **4. Checking Buffer State**
```cpp
if (buffer.isFull(10)) {
    std::cout << "Buffer is full!";
}

if (buffer.hasEnoughData(5)) {
    std::cout << "Enough data available!";
}
```

### **5. Resetting the Buffer**
```cpp
buffer.reset();  // Clears all stored data
```

---

## Thread-Safety

- All functions use **`std::mutex` (`std::lock_guard`)** to **prevent race conditions**.
- Safe to use in **multithreaded** environments.
- Locks are applied **only where necessary**, minimizing performance overhead.

---

## Performance Considerations

- **`std::copy` instead of `memcpy`** for type safety and generality.
- **No dynamic allocations during operations**, except when resizing in `setUp()`.
- **Optimized wrap-around handling** using modular arithmetic.
- **Avoids expensive copies**, using `std::vector<T>` efficiently.

---

## License

This project is licensed under the **MIT License**. Feel free to use and modify.

---

## Contributing

If you’d like to contribute:
1. Fork the repo 🍴
2. Create a new branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m "Add feature X"`
4. Push to your branch: `git push origin feature-name`
5. Open a **Pull Request** 🚀

---

## Author

Developed by **[Your Name]**  
📧 Email: [hosein.seraj11@gmail.com]  
🔗 GitHub: [https://github.com/YOUR_GITHUB_USERNAME](https://github.com/hosein-srj)

---

### **What This README Covers:**
✔️ **Project Overview**  
✔️ **Installation Guide**  
✔️ **Code Usage with Examples**  
✔️ **Thread-Safety Explanation**  
✔️ **Performance Considerations**  
✔️ **License & Contribution Guide**  




