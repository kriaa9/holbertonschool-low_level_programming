# C - Singly Linked Lists

## Table of Contents
1. [Description](#description)
2. [Data Structure](#data-structure)
3. [Task 0: Print List](#task-0-print-list)
4. [Task 1: List Length](#task-1-list-length)
5. [Task 2: Add Node](#task-2-add-node)
6. [Task 3: Add Node End](#task-3-add-node-end)
7. [Task 4: Free List](#task-4-free-list)
8. [Compilation](#compilation)
9. [Author](#author)

---

## Description

This project implements **singly linked lists** in C. A linked list is a dynamic data structure where elements (nodes) are connected through pointers.

### Linked Lists vs Arrays

| Operation | Array | Linked List |
|-----------|-------|-------------|
| Access by index | O(1) - Fast | O(n) - Slow |
| Insert at start | O(n) - Slow | O(1) - Fast |
| Insert at end | O(1) or O(n) | O(n) - Slow |
| Memory | Fixed/Contiguous | Dynamic/Scattered |

---

## Data Structure

```c
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
```

### Visual Representation

```
+------------------SINGLY LINKED LIST------------------+
|                                                      |
|  HEAD                                                |
|   |                                                  |
|   v                                                  |
| +-------+    +-------+    +-------+    +-------+     |
| |str    |    |str    |    |str    |    |str    |     |
| |"Hello"|    |"World"|    |"Test" |    |"End"  |     |
| +-------+    +-------+    +-------+    +-------+     |
| |len: 5 |    |len: 5 |    |len: 4 |    |len: 3 |     |
| +-------+    +-------+    +-------+    +-------+     |
| |next---|--->|next---|--->|next---|--->|next=NULL    |
| +-------+    +-------+    +-------+    +-------+     |
+------------------------------------------------------+
```

---

## Task 0: Print List

**File:** `0-print_list.c`

**Prototype:** `size_t print_list(const list_t *h);`

**Description:** Prints all elements of a linked list.

### Flowchart

```
                    +------------------+
                    |      START       |
                    +------------------+
                             |
                             v
                    +------------------+
                    |   count = 0      |
                    +------------------+
                             |
                             v
                    +------------------+
                    |   Is h != NULL?  |
                    +------------------+
                           /    \
                         YES     NO
                         /        \
                        v          v
          +-------------------+   +------------------+
          | Is h->str NULL?   |   |  return count    |
          +-------------------+   +------------------+
                 /    \                    |
               YES     NO                  v
               /        \          +------------------+
              v          v         |       END        |
    +--------------+  +--------------+  +--------------+
    |Print:        |  |Print:        |
    |"[0] (nil)"   |  |"[len] str"   |
    +--------------+  +--------------+
              \        /
               \      /
                v    v
          +------------------+
          |    count++       |
          +------------------+
                   |
                   v
          +------------------+
          |   h = h->next    |
          +------------------+
                   |
                   +-----> (back to "Is h != NULL?")
```

### How It Works

1. **Initialize** counter to 0
2. **Loop** through each node
3. **Check** if string is NULL → print `[0] (nil)`
4. **Otherwise** → print `[length] string`
5. **Increment** counter and move to next node
6. **Return** total count

---

## Task 1: List Length

**File:** `1-list_len.c`

**Prototype:** `size_t list_len(const list_t *h);`

**Description:** Returns the number of elements in a linked list.

### Flowchart

```
                    +------------------+
                    |      START       |
                    +------------------+
                             |
                             v
                    +------------------+
                    |   count = 0      |
                    +------------------+
                             |
                             v
               +------------------------+
               |     Is h != NULL?      |<----+
               +------------------------+     |
                      /        \              |
                    YES         NO            |
                    /            \            |
                   v              v           |
          +----------------+  +----------------+
          |   count++      |  | return count   |
          +----------------+  +----------------+
                   |                   |
                   v                   v
          +----------------+   +----------------+
          |  h = h->next   |   |      END       |
          +----------------+   +----------------+
                   |
                   +----------------------+
```

### How It Works

1. **Initialize** counter to 0
2. **While** current node is not NULL:
   - Increment counter
   - Move to next node
3. **Return** final count

---

## Task 2: Add Node

**File:** `2-add_node.c`

**Prototype:** `list_t *add_node(list_t **head, const char *str);`

**Description:** Adds a new node at the **beginning** of a linked list.

### Flowchart

```
                    +------------------+
                    |      START       |
                    +------------------+
                             |
                             v
                    +------------------+
                    | malloc new node  |
                    +------------------+
                             |
                             v
                    +------------------+
                    | malloc failed?   |
                    +------------------+
                           /    \
                         YES     NO
                         /        \
                        v          v
              +-------------+  +------------------+
              | return NULL |  | strdup(str)      |
              +-------------+  +------------------+
                                       |
                                       v
                               +------------------+
                               | strdup failed?   |
                               +------------------+
                                      /    \
                                    YES     NO
                                    /        \
                                   v          v
                        +-------------+  +------------------+
                        | free node   |  | Set node->str    |
                        | return NULL |  | Set node->len    |
                        +-------------+  +------------------+
                                                 |
                                                 v
                                         +------------------+
                                         | node->next=*head |
                                         +------------------+
                                                 |
                                                 v
                                         +------------------+
                                         | *head = node     |
                                         +------------------+
                                                 |
                                                 v
                                         +------------------+
                                         | return node      |
                                         +------------------+
                                                 |
                                                 v
                                         +------------------+
                                         |       END        |
                                         +------------------+
```

### Before and After

```
BEFORE:                          AFTER add_node("New"):
                                 
HEAD -> [A] -> [B] -> NULL       HEAD -> [New] -> [A] -> [B] -> NULL
```

---

## Task 3: Add Node End

**File:** `3-add_node_end.c`

**Prototype:** `list_t *add_node_end(list_t **head, const char *str);`

**Description:** Adds a new node at the **end** of a linked list.

### Flowchart

```
                    +------------------+
                    |      START       |
                    +------------------+
                             |
                             v
                    +------------------+
                    | malloc new node  |
                    +------------------+
                             |
                             v
                    +------------------+
                    | malloc failed?   |
                    +------------------+
                           /    \
                         YES     NO
                         /        \
                        v          v
              +-------------+  +------------------+
              | return NULL |  | strdup(str)      |
              +-------------+  | set len, next    |
                               +------------------+
                                       |
                                       v
                               +------------------+
                               | Is *head NULL?   |
                               +------------------+
                                      /    \
                                    YES     NO
                                    /        \
                                   v          v
                        +-------------+  +------------------+
                        |*head = node |  | temp = *head     |
                        +-------------+  +------------------+
                               |                 |
                               |                 v
                               |         +------------------+
                               |         | temp->next NULL? |<--+
                               |         +------------------+   |
                               |                /    \          |
                               |              YES     NO        |
                               |              /        \        |
                               |             v          v       |
                               |   +---------------+ +-------+  |
                               |   |temp->next=node| |temp=  |  |
                               |   +---------------+ |temp-> |  |
                               |          |          |next   |--+
                               |          |          +-------+
                               |          |
                               v          v
                        +------------------+
                        |   return node    |
                        +------------------+
                                 |
                                 v
                        +------------------+
                        |       END        |
                        +------------------+
```

### Before and After

```
BEFORE:                          AFTER add_node_end("New"):
                                 
HEAD -> [A] -> [B] -> NULL       HEAD -> [A] -> [B] -> [New] -> NULL
```

---

## Task 4: Free List

**File:** `4-free_list.c`

**Prototype:** `void free_list(list_t *head);`

**Description:** Frees all nodes of a linked list.

### Flowchart

```
                    +------------------+
                    |      START       |
                    +------------------+
                             |
                             v
               +------------------------+
               |    Is head != NULL?    |<----+
               +------------------------+     |
                      /        \              |
                    YES         NO            |
                    /            \            |
                   v              v           |
          +----------------+  +----------------+
          | temp = head    |  |      END       |
          +----------------+  +----------------+
                   |
                   v
          +----------------+
          | head=head->next|
          +----------------+
                   |
                   v
          +----------------+
          | free(temp->str)|
          +----------------+
                   |
                   v
          +----------------+
          |   free(temp)   |
          +----------------+
                   |
                   +----------------------+
```

### Memory Cleanup Process

```
Step 1: Save current       Step 2: Move head         Step 3: Free saved
        
temp = head                head = head->next         free(temp->str)
    |                          |                     free(temp)
    v                          v                     
  [A]->[B]->[C]->NULL        [B]->[C]->NULL         [B]->[C]->NULL
   ^                          ^
 temp                       head
```

---

## Compilation

All files are compiled on Ubuntu 20.04 LTS using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o output
```

### Example Test

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-print_list.c -o print_list
./print_list
```

---

## Comparison: add_node vs add_node_end

| Feature | add_node | add_node_end |
|---------|----------|--------------|
| Position | Beginning | End |
| Time | O(1) | O(n) |
| Traversal | No | Yes |
| Updates | head pointer | last node's next |

---

## Author

Holberton School Student
