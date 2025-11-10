# C - More malloc, free

## 📚 Project Description

This project focuses on advanced dynamic memory allocation in C, exploring the `exit()` function and implementing custom versions of standard library functions like `calloc` and `realloc`. The emphasis is on proper memory management, error handling, and understanding heap allocation patterns.

---

## 🎯 Learning Objectives

At the end of this project, you should be able to explain **without Google**:

### **General Concepts**

1. **How to use the exit function**
   - Terminates program execution with a status code
   - `exit(0)` - Indicates successful termination
   - `exit(98)` - Convention for malloc failure in this project
   - Non-zero exit codes indicate errors

2. **What are calloc and realloc from the standard library**
   
   **calloc** (Contiguous Allocation):
   ```c
   void *calloc(size_t nmemb, size_t size);

