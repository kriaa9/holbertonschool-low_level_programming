# C - Variadic Functions

## 📚 Project Description

This project explores variadic functions in C - functions that can accept a variable number of arguments. You'll learn to use the `stdarg.h` macros (`va_start`, `va_arg`, `va_end`) and understand the `const` type qualifier.

---

## 🎯 Learning Objectives

At the end of this project, you should be able to explain **without Google**:

### **What are variadic functions?**

Variadic functions are functions that can accept a variable number of arguments. The most famous example is `printf()`.

**Key characteristics:**
- Can accept any number of arguments
- Must have at least one fixed parameter
- Use ellipsis (`...`) in prototype
- Arguments accessed using `stdarg.h` macros

**Syntax:**
```c
return_type function_name(fixed_params, ...);
