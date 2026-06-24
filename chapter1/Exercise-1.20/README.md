# -KnR-C-Exercise-1.20

Solution to exercise 1.20 from "The C Programming Language" by Kernighan & Ritchie.
Replaces tab characters in the input with the proper number of spaces to the next tab stop.
Written in C (C11), compiled with GCC / MSVC.

## Example
Input:
hello	world
a	b	c

Output:
hello   world
a       b       c

## Memory Safety & Architecture
Unlike basic implementations that are vulnerable to Buffer Overflow, this version uses strict boundaries validation:
* **State Tracking:** Tracks both the buffer index (`i`) and virtual screen column (`col`) independently.
* **Overflow Protection:** Dynamically checks `if (i + spaces >= lim - 1)` before writing to prevent memory corruption.
