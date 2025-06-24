# 🌀 Push\_swap

`push_swap` is an algorithmic sorting project from the 42 curriculum where the goal is to sort a stack of integers using the least number of operations and only a limited set of stack instructions. It involves deep algorithmic thinking, data structure manipulation, and optimization.

## 📚 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [File Structure](#-file-structure)
- [Subject Breakdown](#-subject-breakdown)
- [License](#-license)

## 📖 Overview

You are given a list of integers and must sort them using two stacks (`a` and `b`) with a limited set of operations:

- `sa`, `sb`, `ss`: swap operations
- `pa`, `pb`: push between stacks
- `ra`, `rb`, `rr`: rotate stacks
- `rra`, `rrb`, `rrr`: reverse rotate

The goal is to implement the most efficient sorting algorithm in terms of the number of operations.

## ✨ Features

- ✅ Input parsing and error handling
- ✅ Stack data structure with singly linked lists
- ✅ Efficient sorting for small inputs (2–5 numbers)
- ✅ Advanced sorting for large inputs using chunking or radix/markup strategies
- ✅ Optimized instructions printing

### 🧩 Bonus

- ✅ A `checker` program to verify correctness of instruction sequences
- ✅ Colored output for better visibility (optional)
- ✅ Support for reading commands from standard input (`get_next_line`)

## ⚙️ Installation

```bash
git clone https://github.com/adil-ech/push_swap
cd push_swap
make
```

This will generate the `push_swap` and `checker` executables.

## 🚀 Usage

To sort a list:

```bash
./push_swap 3 2 1
```

To check a sequence of operations:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG
```

## 📁 File Structure

```
push_swap/
├── src/
│   ├── main.c
│   ├── sort_small.c
│   ├── sort_big.c
│   ├── actions.c
│   ├── utils.c
│   └── checker.c (bonus)
├── include/
│   └── push_swap.h
├── libft/               # Custom libft
├── Makefile
```

## 📄 Subject Breakdown

### ✅ Mandatory Part

- Parse input and build stacks
- Implement all operations (`sa`, `pb`, etc.)
- Sort stacks with minimal moves
- Error handling: non-integers, duplicates, overflow

### 🎉 Bonus Part

- Implement a `checker` program that reads from stdin and applies operations
- Colored and verbose modes (optional)
- Memory and leak-free operation

## 📬 License

This project is part of the 42 Network curriculum and is intended for educational and academic use.

## 📄 Subject PDF

You can read the official 42 Push_swap subject here:
👉 [Push_swap Subject PDF](./en.subject.pdf)
