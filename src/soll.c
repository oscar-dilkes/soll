/*
 * File: soll.c
 * Author: Oscar Dilkes
 * Created on: 13/08/2023
 * Description: Implementation of a linked list with various operations and organisation types.
 */

/*
  _____      _  __         ____                        _     _               _      _       _            _   _      _     _   
 / ____|    | |/ _|       / __ \                      (_)   (_)             | |    (_)     | |          | | | |    (_)   | |  
| (___   ___| | |_ ______| |  | |_ __ __ _  __ _ _ __  _ ___ _ _ __   __ _  | |     _ _ __ | | _____  __| | | |     _ ___| |_ 
 \___ \ / _ \ |  _|______| |  | | '__/ _` |/ _` | '_ \| / __| | '_ \ / _` | | |    | | '_ \| |/ / _ \/ _` | | |    | / __| __|
 ____) |  __/ | |        | |__| | | | (_| | (_| | | | | \__ \ | | | | (_| | | |____| | | | |   <  __/ (_| | | |____| \__ \ |_ 
|_____/ \___|_|_|         \____/|_|  \__, |\__,_|_| |_|_|___/_|_| |_|\__, | |______|_|_| |_|_|\_\___|\__,_| |______|_|___/\__|
                                      __/ |                           __/ |                                                   
                                     |___/                           |___/                                                    
*/

#include "soll_util.h"

node *create_node(char *str) {
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node != NULL) {
    // Find the length of the input string
    size_t len = strlen(str);

    // Allocate memory for the new string in the node
    new_node->str = (char *)malloc(len + 1); // +1 for the null terminator
    if (new_node->str != NULL) {
      // Copy the input string into the newly allocated memory
      memcpy(new_node->str, str, len + 1);
      new_node->freq = 1; // Initialise frequency to 1 for newly added elements
      new_node->next = NULL;
      // NULL comparison more efficient as removes need to load a second
      // variable into a register
    } else {
      // Failed to allocate memory for the string, free the node and return NULL
      free(new_node);
      new_node = NULL;
    }
  }
  return new_node;
}

soll *soll_init(orgtype type) {
  soll *s = (soll *)malloc(sizeof(soll));
  if (s != NULL) {
    // Set the organisation type of the list
    s->type = type;
    // Initialise the size of the list to 0
    s->size = 0;
    // Initialise the head of the list to NULL
    s->head = NULL;
  }
  return s;
}

void soll_add(soll *s, char *str) {
  if (s == NULL) {
    fprintf(stderr, "The given list doesn't exist.\n");
    return;
  } else if (str == NULL) {
    fprintf(stderr, "The given string doesn't exist.\n");
    return;
  }

  // Create a new node with the given string
  node *new_node = create_node(str);
  if (new_node == NULL) {
    fprintf(stderr, "Memory allocation failed. Unable to add element.\n");
    return;
  }

  if (s->head == NULL) {
    // If the list is empty, set the new node as the head of the list
    s->head = new_node;
  } else {
    // If the list is not empty, find the last node and link the new node to it
    s->tail->next = new_node;
  }

  s->tail = new_node;

  // Increment the size of the list
  s->size++;
}

bool soll_remove(soll *s, char *str) {
  // If the head is not set or doesn't exist return false as can't traverse list
  if (s == NULL || str == NULL || s->head == NULL) {
    return false;
  }

  // Traverse the list to find the node with the given string
  node *curr = s->head;
  node *prev = NULL;

  while (curr != NULL) {
    if (strcmp(curr->str, str) == 0) {
      // If the element is found, unlink it from the list
      if (prev != NULL) {
        prev->next = curr->next;
        if (curr->next == NULL) {
          s->tail = prev;
        }
      } else {
        s->head = curr->next;
      }
      // Free the memory taken by the string in the node
      free(curr->str);
      // Free the memory taken by the node
      free(curr);
      // Reduce size of list by one
      s->size--;
      return true;
    }
    prev = curr;
    curr = curr->next;
  }

  fprintf(stderr, "Element '%s' not found in list.\n", str);
  return false;
}

bool soll_isin(soll *s, char *str, long *cnt) {

  if (s == NULL) {
    fprintf(stderr, "The given list doesn't exist.\n");
    return false;
  } else if (str == NULL) {
    fprintf(stderr, "The given string doesn't exist.\n");
    return false;
  }
  // Traverse the list to find nodes with the given string
  node *curr = s->head;
  node *prev = NULL;

  while (curr != NULL) {
    if (strcmp(curr->str, str) == 0) {
      curr->freq++;
      if (s->type == mtf) {
        // If organisation type is mtf, move the element to the head of the
        // list
        if (prev != NULL) {
          prev->next = curr->next;

          if (curr->next == NULL) {
            s->tail = prev;
          }

          curr->next = s->head;

          s->head = curr;
        }
      } else if (s->type == transpose) {
        // If organisation type is transpose, move the element one place
        // closer to the head

        // Comparison checks if currently on head
        if (prev != NULL) {

          // Node before previous node needs to be known for pointer adjustments
          // (this will become new previous) Could also call prev_prev, called
          // distant for clarity
          node *distant = s->head;

          // Can't find distant if in first two items of the list
          if (distant != curr && distant->next != curr) {
            // Iterate through list to determine location of distant
            while (distant->next != prev) {
              distant = distant->next;
            }

            // What's after the distant node is no longer the previous node but
            // now the current node we have just accessed
            distant->next = curr;
          }

          // Current node has swapped with the previous node taking its place so
          // adjust the next pointer for the previous node to take the place
          // that current held
          if (curr->next == NULL) {
            prev->next = NULL;
            s->tail = prev;
          } else {
            prev->next = curr->next;
          }
          // Same as previous adjustment above, adjust the next pointer to
          // indicate that current and next have swapped places
          curr->next = prev;

          // Update head
          if (prev == s->head) {
            s->head = curr;
          }
        } else if (prev == s->head) {
          // Following two lines do the same as the final two lines for the
          // pointer adjustments if not at head Swap places of the previous and
          // the current
          prev->next = curr->next;
          curr->next = prev;
          // Update head
          s->head = curr;
        }
      }

      return true;
    }

    prev = curr;
    curr = curr->next;
    (*cnt)++; // Increment the pointer chase count
  }

  return false;
}

int soll_freq(soll *s, char *str) {
  if (s == NULL) {
    fprintf(stderr, "The given list doesn't exist.\n");
    return 0;
  } else if (str == NULL) {
    fprintf(stderr, "The given string doesn't exist.\n");
    return 0;
  }

  // Traverse the list to find the node with the given string
  node *curr = s->head;

  while (curr != NULL) {
    if (strcmp(curr->str, str) == 0) {
      return curr->freq; // Return the frequency of the element
    }
    curr = curr->next;
  }

  fprintf(stderr, "Element '%s' not found in list.\n", str);
  return 0;
}

int soll_size(soll *s) {
  if (s == NULL) {
    fprintf(stderr, "The given list doesn't exist.\n");
    return 0;
  }
  // Return the size of the list
  return s->size;
}

void soll_tostring(soll *s, char *str) {
  if (s == NULL) {
    fprintf(stderr, "The given list doesn't exist.\n");
    return;
  } else if (str == NULL) {
    fprintf(stderr, "The given string doesn't exist.\n");
    return;
  }

  // Initialise string as empty
  str[0] = '\0';
  // Start building string from head
  node *curr = s->head;
  // Initialise the position in the buffer
  size_t pos = 0;

  while (curr != NULL && pos < LISTSTRLEN - 1) {
    // Build string from head
    pos +=
        snprintf(str + pos, LISTSTRLEN - pos, "%s(%d)|", curr->str, curr->freq);
    curr = curr->next;
  }

  // Remove the trailing "|" character from the final string
  if (pos > 0 && str[pos - 1] == '|') {
    str[pos - 1] = '\0';
  }
}

bool soll_free(soll *s) {
  if (s == NULL)
    return true;

  node *curr = s->head;
  while (curr != NULL) {
    node *temp = curr;
    curr = curr->next;
    // Free the memory occupied by the string in the node
    free(temp->str);
    // Free the memory occupied by the node
    free(temp);
  }

  // Free the memory occupied by the list struct
  free(s);
  return true;
}
