# SOLL

This repository contains the source code and utilities for a self-organising linked list ADT.
                                           
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

```bash
# Clone the repository
git clone https://github.com/oscardilkes/soll.git

# Navigate to the project directory
cd soll/src

# Build the test executable
make

# Run the tests
./test_soll

# Run sanitized tests
./test_soll_s

# Run sanitized tests w/ Valgrind
valgrind ./test_soll_v
```

## Using the ADT
Below are instructions for using the SOLL.
### Initialisation
```c
soll* soll_init(orgtype type);
```
Initialise the linked list with the chosen organisation type.
Can be of type:  
  'none'      : Unsorted linked list.  
  'mtf'       : When element is accessed it is moved to the front.  
  'transpose' : When element is accessed it is moved one place closer to the front.  
Parameters:  
  type: The organisation type of the list.  
Returns:  
  A pointer to the newly initialised linked list or NULL if memory allocation fails.  
```c
void soll_add(soll* s, char* str);
```

```c
bool soll_remove(soll* s, char* str);
```

```c
bool soll_isin(soll* s, char* str, long* cnt);
```

```c
int soll_freq(soll* s, char* str);
```

```c
int soll_size(soll* s);
```

```c
void soll_tostring(soll* s, char* str);
```

```c
bool soll_free(soll* s);
```
