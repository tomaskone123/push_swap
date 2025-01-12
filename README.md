# push_swap

push_swap is a project that involves creating an efficient sorting algorithm that sorts a list of integers with the least amount of operations. The challenge lies in sorting the list using a limited set of operations and optimizing the number of moves.

## Overview

The goal of the push_swap project is to sort a stack of integers using only two stacks and a set of operations. The challenge is to sort the numbers with as few operations as possible. It is a test of both algorithmic design and efficiency, helping to build a deeper understanding of sorting algorithms and stack manipulation.

## How It Works

- The program works by manipulating two stacks (`a` and `b`).
- It uses a limited set of operations such as `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, and `rrb` to move and sort the numbers.
- The main objective is to implement an algorithm that sorts the stack in the fewest moves possible.

### Operations

The program is designed to execute the following operations:

- **`sa`**: Swap the first two elements of stack `a`.
- **`sb`**: Swap the first two elements of stack `b`.
- **`pa`**: Push the first element of stack `b` onto stack `a`.
- **`pb`**: Push the first element of stack `a` onto stack `b`.
- **`ra`**: Rotate stack `a` (move the first element to the last position).
- **`rb`**: Rotate stack `b` (move the first element to the last position).
- **`rra`**: Reverse rotate stack `a` (move the last element to the first position).
- **`rrb`**: Reverse rotate stack `b` (move the last element to the first position).
- **`rr`**: Apply `ra` and `rb` simultaneously.
- **`rrr`**: Apply `rra` and `rrb` simultaneously.

## Requirements

- A C compiler (e.g., GCC)
- A basic understanding of stacks and sorting algorithms
- Linux-based operating system

## Usage

### Compilation

To compile the project, run the following command:

```bash
make
```

This will generate the `push_swap` executable.

### Running the Program

To run the program, simply execute:

```bash
./push_swap <list_of_integers>
```

Where `<list_of_integers>` is a space-separated list of integers to be sorted. For example:

```bash
./push_swap 3 2 5 1 4
```

The program will output the sequence of operations required to sort the list in ascending order.
