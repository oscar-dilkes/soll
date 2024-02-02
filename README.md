# SOLL

This repository contains the source code and utilities for a self-organising linked list ADT.

- [Directory Structure](#directory-structure)
- [Building and Testing](#building-and-testing)
- [Using the ADT](#using-the-adt)
  - [Initialisation](#initialisation)
  - [Add](#add)
  - [Remove](#remove)
  - [Find Element](#find-element)
  - [Frequency](#frequency)
  - [Size](#size)
  - [Retrieve String Representation](#retrieve-string-representation)
  - [Free Memory](#free-memory)
                                           
## Directory Structure

The project directory is organized as follows:

- **src**: Contains the source code files.
  - `soll_util.h`: Header file with utility functions and testing.
  - `soll.c`: Implementation of the linked list functions.
  - `test_soll.c`: Test file for the linked list functions.
- `soll.h`: Header file for ADT exposing available functions.
- `Makefile`

## Building and Testing

To build the project and run tests, follow these steps:

Clone the repository
```bash
git clone https://github.com/oscardilkes/soll.git
```
Navigate to the project directory
```bash
cd soll/src
```
Build the test executable
```bash
make
```
Run the tests
```bash
./test_soll
```
Run sanitized tests
```bash
./test_soll_s
```
Run sanitized tests w/ Valgrind
```bash
valgrind ./test_soll_v
```

## Using the ADT
Below are instructions for using the SOLL.
### Initialisation
Initialise the linked list with the chosen organisation type.  
```c
soll* soll_init(orgtype type);
```
Can be of type:  
- 'none'      : Unsorted linked list.  
- 'mtf'       : When element is accessed it is moved to the front.  
- 'transpose' : When element is accessed it is moved one place closer to the front.

Parameters:  
- type: The organisation type of the list.
  
Returns:  
- A pointer to the newly initialised linked list or NULL if memory allocation fails.

### Add
Adds a new element to the linked list through deep copy.
```c
void soll_add(soll* s, char* str);
```
Parameters:
- s: Pointer to the linked list.
- str: The string to be added to the list.
  
### Remove
Removes an element from the linked list based on the provided string.
```c
bool soll_remove(soll* s, char* str);
```
Parameters:
- s: Pointer to the linked list.
- str: The string to be removed from the list.
  
Returns:
- True if the element is successfully removed, false otherwise.

### Find Element
Searches for an element in the linked list and updates its frequency and position.
```c
bool soll_isin(soll* s, char* str, long* cnt);
```
Parameters:
- s: Pointer to the linked list.
- str: The string to be searched for.
- cnt: Pointer to a variable that stores the pointer chase count.
  
Returns:
- True if the element is found and updated, false otherwise.

### Frequency
Gets the frequency of a particular element in the linked list.
```c
int soll_freq(soll* s, char* str);
```
Parameters:
- s: Pointer to the linked list.
- str: The string to get the frequency for.
  
Returns:
- The frequency of the specified element in the list.

### Size
```c
int soll_size(soll* s);
```
Parameters:
- s: Pointer to the linked list.
  
Returns:
- The size of the linked list.

### Retrieve String Representation
Converts the linked list to a string representation.
```c
void soll_tostring(soll* s, char* str);
```
Parameters:
- s: Pointer to the linked list.
- str: Buffer to store the resulting string.

### Free Memory
Frees the memory used by the linked list.
```c
bool soll_free(soll* s);
```
Parameters:
- s: Pointer to the linked list.
  
Returns:
- True if memory is successfully freed, false otherwise.
  
