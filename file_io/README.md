# C - File I/O

## Description
This project covers file input/output operations in C using system calls.

## Learning Objectives
- How to create, open, close, read and write files
- What are file descriptors
- What are the 3 standard file descriptors (STDIN, STDOUT, STDERR)
- How to use the I/O system calls: open, close, read, write
- File permissions and flags (O_RDONLY, O_WRONLY, O_RDWR)

## Files
| File | Description |
|------|-------------|
| main.h | Header file with prototypes |
| 0-read_textfile.c | Read and print text file |
| 1-create_file.c | Create a file |
| 2-append_text_to_file.c | Append text to file |
| 3-cp.c | Copy file content |

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o output EOF
