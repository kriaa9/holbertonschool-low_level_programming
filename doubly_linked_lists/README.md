# 🔗 C - Doubly Linked Lists

## 📚 Table of Contents
1. [Description](#description)
2. [What is a Doubly Linked List?](#what-is-a-doubly-linked-list)
3. [Data Structure](#data-structure)
4. [Beautiful ASCII Diagrams](#beautiful-ascii-diagrams)
5. [Task 0: Print List](#task-0-print-list)
6. [Task 1: List Length](#task-1-list-length)
7. [Task 2: Add Node at Beginning](#task-2-add-node-at-beginning)
8. [Task 3: Add Node at End](#task-3-add-node-at-end)
9. [Task 4: Free List](#task-4-free-list)
10. [Task 5: Get Node at Index](#task-5-get-node-at-index)
11. [Task 6: Sum List](#task-6-sum-list)
12. [Task 7: Insert at Index](#task-7-insert-at-index)
13. [Task 8: Delete at Index](#task-8-delete-at-index)
14. [Compilation](#compilation)
15. [Requirements](#requirements)
16. [Files Summary](#files-summary)
17. [Author](#author)

---

## Description

This project implements **doubly linked lists** in C.

Unlike singly linked lists, each node in a doubly linked list contains **two pointers**:
- One pointing to the **next** node
- One pointing to the **previous** node

This allows traversal in **both directions** and makes insertion/deletion in the middle of the list easier.

---

## What is a Doubly Linked List?

A **doubly linked list** is a linear data structure where:

- Each element (node) contains:
  - An integer value (`n`)
  - A pointer to the **previous** node (`prev`)
  - A pointer to the **next** node (`next`)
- The first node’s `prev` pointer is `NULL`
- The last node’s `next` pointer is `NULL`

### ✔ Advantages over Singly Linked Lists

- Can traverse in **both directions** (forward and backward)
- Easier to delete a node (you already have `prev`)
- Easier to insert **before** a given node

### ❌ Disadvantages

- Extra memory (one more pointer per node)
- Slightly more complex implementation

---

## Data Structure

```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

### Node Layout

```text
+------------------+
|       prev       | --> Points to previous node (or NULL if first)
+------------------+
|        n         | --> Data (integer)
+------------------+
|       next       | --> Points to next node (or NULL if last)
+------------------+
```

### Example List with values [1, 2, 3]

```text
NULL <-- [NULL|1|next] <--> [prev|2|next] <--> [prev|3|NULL] --> NULL
          ^                                      ^
         HEAD                                   TAIL
```

---

## Beautiful ASCII Diagrams

### Full List View

```text
NULL <-- [prev|n|next] <--> [prev|n|next] <--> [prev|n|next] --> NULL
              |                  |                  |
            HEAD               MIDDLE              TAIL
```

---

# Task 0: Print List

**File:** `0-print_dlistint.c`  
**Prototype:** `size_t print_dlistint(const dlistint_t *h);`  

**Description:**  
Prints all the elements of a `dlistint_t` list and returns the number of nodes.

```c
#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        count++;
        h = h->next;
    }

    return (count);
}
```

### Flowchart (ASCII)

```text
+---------------------+
|  print_dlistint(h)  |
+----------+----------+
           |
           v
+---------------------+
|    count = 0        |
+----------+----------+
           |
           v
+---------------------+
|   h != NULL ?       |<-----------+
+----------+----------+            |
           |                       |
   +-------+-------+               |
   |               |               |
  YES             NO               |
   |               |               |
   v               v               |
+---------------+  +-------------+ |
| printf(h->n)  |  | return count| |
| count++       |  +-------------+ |
| h = h->next   |                  |
+-------+-------+                  |
        |                          |
        +--------------------------+
```

---

# Task 1: List Length

**File:** `1-dlistint_len.c`  
**Prototype:** `size_t dlistint_len(const dlistint_t *h);`  

**Description:**  
Returns the number of elements in a `dlistint_t` list.

```c
#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        count++;
        h = h->next;
    }

    return (count);
}
```

### Flowchart (ASCII)

```text
+---------------------+
|   dlistint_len(h)   |
+----------+----------+
           |
           v
+---------------------+
|    count = 0        |
+----------+----------+
           |
           v
+---------------------+
|   h != NULL ?       |<-----------+
+----------+----------+            |
           |                       |
   +-------+-------+               |
   |               |               |
  YES             NO               |
   |               |               |
   v               v               |
+---------------+  +-------------+ |
|   count++     |  | return count| |
| h = h->next   |  +-------------+ |
+-------+-------+                  |
        |                          |
        +--------------------------+
```

### Example (GIF-style steps)

```text
Input:  [9] <--> [8] --> NULL

Step 1: count = 0, node = [9]
Step 2: count = 1, node = [8]
Step 3: count = 2, node = NULL

Output: 2
```

---

# Task 2: Add Node at Beginning

**File:** `2-add_dnodeint.c`  
**Prototype:** `dlistint_t *add_dnodeint(dlistint_t **head, const int n);`  

**Description:**  
Adds a new node at the **BEGINNING** of a `dlistint_t` list.

```c
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to pointer to the head of the list
 * @n: integer value for the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;

    return (new_node);
}
```

### Flowchart (ASCII)

```text
+---------------------------+
| add_dnodeint(head, n)     |
+-------------+-------------+
              |
              v
+---------------------------+
| new_node = malloc(...)    |
+-------------+-------------+
              |
              v
+---------------------------+
| new_node == NULL ?        |
+-------------+-------------+
              |
      +-------+-------+
      |               |
     YES             NO
      |               |
      v               v
+-----------+   +---------------------------+
|return NULL|   | new_node->n = n           |
+-----------+   | new_node->prev = NULL     |
                | new_node->next = *head    |
                +-------------+-------------+
                              |
                              v
                +---------------------------+
                |  *head != NULL ?          |
                +-------------+-------------+
                              |
                     +--------+--------+
                     |                 |
                    YES               NO
                     |                 |
                     v                 |
             +---------------+         |
             | (*head)->prev |         |
             |  = new_node   |         |
             +-------+-------+         |
                     |                 |
                     +--------+--------+
                              |
                              v
                +---------------------------+
                |   *head = new_node        |
                +-------------+-------------+
                              |
                              v
                +---------------------------+
                |     return new_node       |
                +---------------------------+
```

### Example (GIF-style)

```text
BEFORE:
*head --> [prev|1|next] <--> [prev|2|next] --> NULL
           NULL

add_dnodeint(&head, 0)

AFTER:
*head --> [prev|0|next] <--> [prev|1|next] <--> [prev|2|next] --> NULL
           NULL
```

---

# Task 3: Add Node at End

**File:** `3-add_dnodeint_end.c`  
**Prototype:** `dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);`  

**Description:**  
Adds a new node at the **END** of a `dlistint_t` list.

```c
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to pointer to the head of the list
 * @n: integer value for the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node;
    dlistint_t *temp;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;

    return (new_node);
}
```

### Flowchart (ASCII)

```text
+------------------------------+
| add_dnodeint_end(head, n)    |
+---------------+--------------+
                |
                v
+------------------------------+
| new_node = malloc(...)       |
| new_node->n = n              |
| new_node->next = NULL        |
+---------------+--------------+
                |
                v
+------------------------------+
| *head == NULL ?              |
+---------------+--------------+
                |
        +-------+-------+
        |               |
       YES             NO
        |               |
        v               v
+---------------+   +---------------------+
|new_node->prev |   | temp = *head        |
|   = NULL      |   +----------+----------+
|*head=new_node |              |
|return new_node|              v
+---------------+   +---------------------+
                    | temp->next != NULL ?|<----+
                    +----------+----------+     |
                               |                |
                      +--------+--------+       |
                      |                 |       |
                     YES               NO       |
                      |                 |       |
                      v                 |       |
              +---------------+         |       |
              |temp=temp->next|---------+-------+
              +---------------+         |
                                        v
                             +---------------------+
                             | temp->next = new    |
                             | new->prev = temp    |
                             | return new_node     |
                             +---------------------+
```

### Example (GIF-style)

```text
BEFORE:
*head --> [prev|0|next] <--> [prev|1|next] --> NULL

add_dnodeint_end(&head, 2)

AFTER:
*head --> [prev|0|next] <--> [prev|1|next] <--> [prev|2|next] --> NULL
```

### Comparison: Beginning vs End

```text
+---------------------------+---------------------------+
|     add_dnodeint          |    add_dnodeint_end       |
|     (beginning)           |        (end)              |
+---------------------------+---------------------------+
| *head --> [NEW] --> [OLD] | [OLD] --> [...] --> [NEW] |
| Time: O(1)                | Time: O(n)                |
| No traversal needed       | Must traverse to last     |
+---------------------------+---------------------------+
```

---

# Task 4: Free List

**File:** `4-free_dlistint.c`  
**Prototype:** `void free_dlistint(dlistint_t *head);`  

**Description:**  
Frees all nodes of a `dlistint_t` list.

```c
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
```

### Flowchart (ASCII)

```text
+---------------------+
|  free_dlistint(head)|
+----------+----------+
           |
           v
+---------------------+
|  head != NULL ?     |<-----------+
+----------+----------+            |
           |                       |
   +-------+-------+               |
   |               |               |
  YES             NO               |
   |               |               |
   v               v               |
+---------------+  +-------------+ |
| temp = head   |  |    DONE     | |
| head=head->next| +-------------+ |
| free(temp)    |                  |
+-------+-------+                  |
        |                          |
        +--------------------------+
```

### GIF-style Steps (VERY IMPORTANT ORDER)

```text
STEP 1:
head --> [0] <--> [1] <--> [2] --> NULL
temp = head ([0])

STEP 2:
head = head->next  => head --> [1] <--> [2] --> NULL
free([0]) ✓

STEP 3:
temp = head ([1])
head = head->next  => head --> [2] --> NULL
free([1]) ✓

STEP 4:
temp = head ([2])
head = head->next  => head --> NULL
free([2]) ✓

DONE: All memory freed!
```

#### Correct vs Wrong Order

```text
CORRECT ORDER:
1. temp = head
2. head = head->next
3. free(temp)

WRONG ORDER:
1. free(head)      (❌ You lose access to head->next)
```

---

# Task 5: Get Node at Index

**File:** `5-get_dnodeint.c`  
**Prototype:** `dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);`  

**Description:**  
Returns the **nth node** of a `dlistint_t` linked list (index starts at 0).  
Returns `NULL` if the node does not exist.

```c
#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t list
 * @head: pointer to the head of the list
 * @index: index of the node to return, starting from 0
 *
 * Return: pointer to the nth node, or NULL if node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i = 0;

    while (head != NULL)
    {
        if (i == index)
            return (head);
        head = head->next;
        i++;
    }

    return (NULL);
}
```

### Flowchart (ASCII)

```text
+--------------------------------+
| get_dnodeint_at_index(head,idx)|
+---------------+----------------+
                |
                v
+------------------------------+
|         i = 0                |
+---------------+--------------+
                |
                v
+------------------------------+
|     head != NULL ?           |<--------+
+---------------+--------------+         |
                |                        |
        +-------+-------+                |
        |               |                |
       YES             NO                |
        |               |                |
        v               v                |
+---------------+  +-------------+       |
| i == index ?  |  | return NULL |       |
+-------+-------+  +-------------+       |
        |                                |
 +------+-------+                        |
 |              |                        |
YES            NO                        |
 |              |                        |
 v              v                        |
+---------+  +----------------+          |
|return  |  | head=head->next |----------+
| head   |  | i++             |
+---------+  +----------------+
```

### Example

```text
Index:  0     1     2     3     4     5
List:  [0] <--> [1] <--> [2] <--> [3] <--> [4] <--> [98]

get_dnodeint_at_index(head, 5)  --> pointer to [98]
get_dnodeint_at_index(head, 10) --> NULL (does not exist)
```

---

# Task 6: Sum List

**File:** `6-sum_dlistint.c`  
**Prototype:** `int sum_dlistint(dlistint_t *head);`  

**Description:**  
Returns the sum of all `n` values in a `dlistint_t` linked list.

```c
#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: sum of all data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}
```

### Flowchart (ASCII)

```text
+---------------------+
|  sum_dlistint(head) |
+----------+----------+
           |
           v
+---------------------+
|     sum = 0         |
+----------+----------+
           |
           v
+---------------------+
|  head != NULL ?     |<-----------+
+----------+----------+            |
           |                       |
   +-------+-------+               |
   |               |               |
  YES             NO               |
   |               |               |
   v               v               |
+---------------+  +-------------+ |
| sum += head->n|  | return sum  | |
| head=head->next| +-------------+ |
+-------+-------+                  |
        |                          |
        +--------------------------+
```

### GIF-style Sum Example

```text
List:
[0] <--> [1] <--> [2] <--> [3] <--> [4] <--> [98] <--> [402] <--> [1024]

Calculation:
sum = 0
sum = 0 +   0 =   0
sum = 0 +   1 =   1
sum = 1 +   2 =   3
sum = 3 +   3 =   6
sum = 6 +   4 =  10
sum = 10 + 98 = 108
sum = 108 + 402 = 510
sum = 510 + 1024 = 1534

Output: sum = 1534
```

---

# Task 7: Insert at Index

**File:** `7-insert_dnodeint.c`  
**Prototype:**  
`dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);`  

**Description:**  
Inserts a new node at a **given position** `idx`.

```c
#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to the head of the list
 * @idx: index where the new node should be added, starting from 0
 * @n: integer value for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node;
    dlistint_t *temp;
    unsigned int i;

    if (h == NULL)
        return (NULL);

    if (idx == 0)
        return (add_dnodeint(h, n));

    temp = *h;
    for (i = 0; i < idx - 1; i++)
    {
        if (temp == NULL)
            return (NULL);
        temp = temp->next;
    }

    if (temp == NULL)
        return (NULL);

    if (temp->next == NULL)
        return (add_dnodeint_end(h, n));

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;

    return (new_node);
}
```

### Flowchart (ASCII)

```text
+----------------------------------+
| insert_dnodeint_at_index(h,idx,n)|
+----------------+-----------------+
                 |
                 v
+----------------------------------+
|          idx == 0 ?              |
+----------------+-----------------+
                 |
       +---------+---------+
       |                   |
      YES                 NO
       |                   |
       v                   v
+---------------+   +---------------------------+
|return         |   | temp = *h                |
|add_dnodeint() |   | Traverse to (idx - 1)    |
+---------------+   +-------------+-------------+
                                  |
                                  v
                      +---------------------------+
                      | temp == NULL ?            |
                      +-------------+-------------+
                                  |
                        +---------+---------+
                        |                   |
                       YES                 NO
                        |                   |
                        v                   v
                +---------------+   +---------------------------+
                |   return NULL |   | temp->next == NULL ?      |
                +---------------+   +-------------+-------------+
                                                  |
                                        +---------+---------+
                                        |                   |
                                       YES                 NO
                                        |                   |
                                        v                   v
                                +---------------+   +-----------------------+
                                |return         |   | new_node = malloc(...)|
                                |add_dnodeint   |   | ... link node ...     |
                                |_end()         |   | return new_node       |
                                +---------------+   +-----------------------+
```

### GIF-style Example: Insert at Index 5

```text
BEFORE (idx = 5, n = 4096):

Index:  0     1     2     3     4     5      6      7
List:  [0] <--> [1] <--> [2] <--> [3] <--> [4] <--> [98] <--> [402] <--> [1024]

AFTER:

Index:  0     1     2     3     4      5      6      7      8
List:  [0] <--> [1] <--> [2] <--> [3] <--> [4] <--> [4096] <--> [98] <--> [402] <--> [1024]
                                           ^
                                        INSERTED NODE
```

### Case Summary

```text
+----------------------------------------------------------+
| CASE 1: idx == 0                                         |
|         -> Use add_dnodeint() (insert at beginning)      |
+----------------------------------------------------------+
| CASE 2: idx at end (temp->next == NULL)                  |
|         -> Use add_dnodeint_end()                        |
+----------------------------------------------------------+
| CASE 3: idx in the middle                                |
|         1. new_node->prev  = temp                        |
|         2. new_node->next  = temp->next                  |
|         3. temp->next->prev = new_node                   |
|         4. temp->next      = new_node                    |
+----------------------------------------------------------+
```

---

# Task 8: Delete at Index

**File:** `8-delete_dnodeint.c`  
**Prototype:** `int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);`  

**Description:**  
Deletes the node at a given `index` in a `dlistint_t` list.  
Returns:
- `1` if it succeeded
- `-1` if it failed

```c
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to pointer to the head of the list
 * @index: index of the node to delete, starting from 0
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    temp = *head;

    if (index == 0)
    {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    for (i = 0; i < index; i++)
    {
        if (temp == NULL)
            return (-1);
        temp = temp->next;
    }

    if (temp == NULL)
        return (-1);

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return (1);
}
```

### Flowchart (ASCII)

```text
+----------------------------------+
| delete_dnodeint_at_index(head,idx)|
+----------------+-----------------+
                 |
                 v
+----------------------------------+
| head==NULL || *head==NULL ?      |
+----------------+-----------------+
                 |
       +---------+---------+
       |                   |
      YES                 NO
       |                   |
       v                   v
+---------------+   +---------------------+
|   return -1   |   |   temp = *head      |
+---------------+   +----------+----------+
                                |
                                v
                     +---------------------+
                     |   index == 0 ?      |
                     +----------+----------+
                                |
                       +--------+--------+
                       |                 |
                      YES               NO
                       |                 |
                       v                 v
            +----------------------+  +-------------------+
            | *head = temp->next   |  | Traverse to index |
            | if (*head)           |  +---------+---------+
            |   (*head)->prev=NULL |            |
            | free(temp)           |            v
            | return 1             |   +--------------------------+
            +----------------------+   | Relink prev/next, free   |
                                       | return 1 or -1           |
                                       +--------------------------+
```

### GIF-style Cases

#### Case 1: Delete at index 0 (head)

```text
BEFORE:
*head --> [0] <--> [1] <--> [2]
           ^
         DELETE

Step:
*head = [1]
[1]->prev = NULL
free([0])

AFTER:
*head --> [1] <--> [2]
           prev = NULL
```

#### Case 2: Delete in middle (e.g. index 5)

```text
BEFORE:
[4] <--> [98] <--> [402]
          ^
        DELETE [98]

Links update:
[4].next   = [402]
[402].prev = [4]
free([98])

AFTER:
[4] <----------------> [402]
```

#### Case 3: Delete at end

```text
BEFORE:
[402] <--> [1024] --> NULL
           ^
        DELETE [1024]

Links update:
[402].next = NULL
free([1024])

AFTER:
[402] --> NULL
```

---

## Compilation

Compile your files with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

---

## Requirements

- OS: **Ubuntu 20.04 LTS**
- Compiler: `gcc` with flags:
  - `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Betty** style compliant
- Allowed functions:
  - `malloc`
  - `free`
  - `printf`
  - `exit`
- **No global variables**
- Maximum **5 functions per file**

---

## Files Summary

| File                    | Function                    | Description                     |
|-------------------------|----------------------------|---------------------------------|
| `lists.h`               | -                          | Struct `dlistint_t` + prototypes|
| `0-print_dlistint.c`    | `print_dlistint`           | Print all elements              |
| `1-dlistint_len.c`      | `dlistint_len`             | Return number of elements       |
| `2-add_dnodeint.c`      | `add_dnodeint`             | Add node at beginning           |
| `3-add_dnodeint_end.c`  | `add_dnodeint_end`         | Add node at end                 |
| `4-free_dlistint.c`     | `free_dlistint`            | Free entire list                |
| `5-get_dnodeint.c`      | `get_dnodeint_at_index`    | Get node at index               |
| `6-sum_dlistint.c`      | `sum_dlistint`             | Sum all data in list            |
| `7-insert_dnodeint.c`   | `insert_dnodeint_at_index` | Insert node at index            |
| `8-delete_dnodeint.c`   | `delete_dnodeint_at_index` | Delete node at index            |

---

## Author

**Ons Kriaa**  
Holberton School – Low Level Programming  
Doubly Linked Lists Project 🧠🔗
