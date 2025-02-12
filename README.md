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

