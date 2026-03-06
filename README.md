# 📦 Project Name

> OOP C++ Demos.

---

## 📚 Table of Contents

- [📦 Project Name](#-project-name)
  - [📚 Table of Contents](#-table-of-contents)
  - [📝 About](#-about)
  - [✨ Features](#-features)
  - [🚀 Getting Started](#-getting-started)
    - [Prerequisites](#prerequisites)
    - [Source](#source)
    - [Usage](#usage)
    - [Reference](#reference)

---

## 📝 About

> Demos about OOP C++ concepts.

---

## ✨ Features

- ✅ Use Cmake as workspace
- ✅ Class - Declaration and Definition
  - Account: basic class
  - Student: apply this pointer
  - Account2: constructor overloading
  - Point: apply default arguments in methods
  - Date: copy constructor
  - Dollard: conversion constructor
  - Dollard2: explicit in conversion constructor
  - Article: static member, destructor, getter/setter
  - SalesPerson: helper function
  - Account3: inline function
  - Node: non-member friend
  - friend: member friend
  - Time: const object
  - Person: static method
- ✅ Operator overloading
  - Complex: Unary operators (-, ++prefix, postfix++, <<), binary operators (+, +=)
  - Time: typecast
  - Number: bool overloading
  - Vector: binary operators, commutative; insertion/extraction operators
  - DoubleVector: subscript operator [], assignment operator
  - Word: functor
  - X_ptr: operator->, operator*
  - Point3D: new, delete, new[], delete[]
- ✅ Pointers and References
- ✅ Classes with Dynamically Allocated Data Members
- ✅ Composed class - Embedded class
- ✅ Polymorphism
  - Instrument: upcasting
  - Student: static binding
  - Shape: vitual func, dynamic binding, abstract class
  - Base: virtual destructor
  - Car: static_cast, dynamic_cast
  - ClientData: reinterpret_cast
- ✅ Inheritance
- ✅ Stream
- ✅ Practice
  - Matrix: multiplication matrix...
  - Element: I/O data...
  - Triangle classification...
  - Account: interface for banking transaction...
  - Clock: extract string to tokens...
  - Date manipulation...
  - Fraction: operator overloading (+, -, *, /, compare...)
  - Mystring: allocate dynamic data, concat, compare, substring, I/O...
  - List: composition class, insert/remove node, linked-list implementation
  - Product: inheritance, abstraction, I/O function
  - Bank: inheritance, Polymorphism, I/O function

---

## 🚀 Getting Started

### Prerequisites

- List software dependencies or system requirements here:
  - C++
  - Cmake
  - VSCode (Cmake extension)

### Source

- build/
- out/
- main.cpp: main app (paste code to this file to run as default)
- CMakeLists.txt: config workspace
- CMakePresets.json: config compiler
- */*.cpp: source code
- */*.txt, */*.bin: test files

### Usage

- Install Cmake extension to VSCode
- (Ctrl + Shift + P) -> Cmake: Select configure preset
- Add a new preset -> Create from compilers -> Scan recursively for compilers... in your PC-> enter preset name
- Add **"generator": "MinGW Makefiles",** as default preset
- (Ctrl + Shift + P) -> Cmake: Select configure preset -> select your added new preset
- (Ctrl + Shift + P) -> Cmake: set build target -> OOP_Cpp
- Paste source code to **main.cpp** OR modify navigation to source in **CMakeLists.txt**
- Run

### Reference

- Dương Thiên Tứ - **OOP**, 2015