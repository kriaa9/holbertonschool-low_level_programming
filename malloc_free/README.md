# C - malloc, free

This project explores dynamic memory allocation in C programming.

## Learning Objectives

### General
- **Automatic vs Dynamic Allocation**: Understanding stack vs heap memory
- **malloc and free**: How to allocate and free memory dynamically
- **When to use malloc**: Runtime-sized data structures, persistent memory
- **Valgrind**: Memory leak detection and validation

## Key Concepts

### Automatic Allocation
```c
int arr[10];  // Stack - automatically freed when scope ends
```

### Dynamic Allocation
```c
int *arr = malloc(sizeof(int) * 10);  // Heap - must manually free
free(arr);
```

## Requirements

- Editors: vi, vim, emacs
- Compilation: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style compliant
- No global variables
- Max 5 functions per file
- Only `malloc` and `free` allowed from standard library
- `_putchar` allowed
- All files end with newline

## Files

| Task | File | Description |
|------|------|-------------|
| 0 | `0-create_array.c` | Create and initialize char array |
| 1 | `1-strdup.c` | Duplicate a string |
| 2 | `2-str_concat.c` | Concatenate two strings |
| 3 | `3-alloc_grid.c` | Allocate 2D integer array |
| 4 | `4-free_grid.c` | Free 2D array |

## Memory Management Rules

1. Always check malloc return value
2. Always free what you malloc
3. Don't access freed memory
4. Don't double free
5. Use valgrind to verify no leaks

## Author
Holberton School Student
