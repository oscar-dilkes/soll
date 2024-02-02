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
