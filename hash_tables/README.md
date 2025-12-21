# C - Hash Tables

This project implements a Hash Table data structure in C. Hash tables are efficient data structures that map keys to values, allowing for fast data retrieval. This implementation uses **chaining** (linked lists) to handle collisions.

## Data Structures
The project uses the following data structures:

```c
/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;
