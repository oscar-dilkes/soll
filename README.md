# SOLL

This repository contains the source code and utilities for a self-organising linked list ADT.
                                           
## Table of Contents

- [Directory Structure](#directory-structure)
- [Building and Testing](#building-and-testing)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Directory Structure

The project directory is organized as follows:

- **src**: Contains the source code files.
  - `soll.h`: Header file defining the linked list data structure.
  - `soll_util.h`: Header file with utility functions and testing.
  - `soll.c`: Implementation of the linked list functions.
  - `test_soll.c`: Test file for the linked list functions.

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
