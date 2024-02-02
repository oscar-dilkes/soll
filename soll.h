/*
 * File: soll.h
 * Author: Oscar Dilkes
 * Created on: 13/08/2023
 * Description: Header file defining the Self-Organising Linked List (soll) ADT with functions for 
 *              initialisation, element manipulation, and memory management.
 */

#ifndef SOLL_H
#define SOLL_H

#include <stdbool.h>

typedef struct soll soll;
typedef enum{none, mtf, transpose} orgtype;

/*
 * Initialise the linked list with the chosen organisation type.
 * Can be of type:
 *   'none'      : Unsorted linked list.
 *   'mtf'       : When element is accessed it is moved to the front.
 *   'transpose' : When element is accessed it is moved one place closer to the front.
 * Parameters:
 *   type: The organisation type of the list.
 * Returns:
 *   A pointer to the newly initialised linked list or NULL if memory allocation fails.
 */
soll* soll_init(orgtype type);

/*
 * Adds a new element to the linked list through deep copy.
 * Parameters:
 *   s: Pointer to the linked list.
 *   str: The string to be added to the list.
 */
void soll_add(soll* s, char* str);

/*
 * Removes an element from the linked list based on the provided string.
 * Parameters:
 *   s: Pointer to the linked list.
 *   str: The string to be removed from the list.
 * Returns:
 *   True if the element is successfully removed, false otherwise.
 */
bool soll_remove(soll* s, char* str);

/*
 * Searches for an element in the linked list and updates its frequency and position.
 * Parameters:
 *   s: Pointer to the linked list.
 *   str: The string to be searched for.
 *   cnt: Pointer to a variable that stores the pointer chase count.
 * Returns:
 *   True if the element is found and updated, false otherwise.
 */
bool soll_isin(soll* s, char* str, long* cnt);

/*
 * Gets the frequency of a particular element in the linked list.
 * Parameters:
 *   s: Pointer to the linked list.
 *   str: The string to get the frequency for.
 * Returns:
 *   The frequency of the specified element in the list.
 */
int soll_freq(soll* s, char* str);

/*
 * Gets the size of the linked list.
 * Parameters:
 *   s: Pointer to the linked list.
 * Returns:
 *   The size of the linked list.
 */
int soll_size(soll* s);

/*
 * Converts the linked list to a string representation.
 * Parameters:
 *   s: Pointer to the linked list.
 *   str: Buffer to store the resulting string.
 */
void soll_tostring(soll* s, char* str);

/*
 * Frees the memory used by the linked list.
 * Parameters:
 *   s: Pointer to the linked list.
 * Returns:
 *   True if memory is successfully freed, false otherwise.
 */
bool soll_free(soll* s);

#endif // SOLL_H