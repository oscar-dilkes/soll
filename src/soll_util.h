/*
 * File: soll_util.h
 * Author: Oscar Dilkes
 * Created on: 13/08/2023
 * Description: Header file containing utility functions and structures for soll ADT and test file.
 */

#ifndef SOLL_UTIL_H
#define SOLL_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../soll.h"

typedef struct node node;
#define LISTSTRLEN 1000

struct node {
  char *str;
  int freq;
  struct node *next;
};

struct soll {
  orgtype type;
  int size;
  node *head;
  node *tail;
};

/*
 * Helper function that creates a new node with the provided string.
 * Parameters:
 *   str: The string to be stored in the new node.
 * Returns:
 *   A pointer to the newly created node or NULL if memory allocation fails.
 */
node *create_node(char *str);

// Performs white-box testing including tests for individual functions and corner cases.
void white_box_test();

// Performs black-box testing, covering various scenarios and interactions between functions.
void black_box_test();

#endif // SOLL_UTIL_H