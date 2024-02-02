/*
 * File: test_soll.c
 * Author: Oscar Dilkes
 * Created on: 13/08/2023
 * Description: Test file for soll.
 */

#include "soll_util.h"

int main(void) {

  // Run white-box testing
  white_box_test();

  // Run black-box testing
  black_box_test();

  return 0;
}

// White-box testing function
void white_box_test() {
  printf("\nStart White-box Testing...\n");

  // Test create_node function
  node *n = create_node("test");
  assert(n != NULL);
  assert(strcmp(n->str, "test") == 0);
  assert(n->freq == 1);
  assert(n->next == NULL);
  free(n->str);
  free(n);

  // Following tests for organisation type none
  // Test the soll_init function
  soll *s_none = soll_init(none);
  assert(s_none != NULL);
  assert(s_none->type == none);
  assert(s_none->size == 0);
  assert(s_none->head == NULL);

  // Test the soll_add function
  soll_add(s_none, "one");
  assert(s_none->size == 1);
  assert(strcmp(s_none->head->str, "one") == 0);
  assert(s_none->head->freq == 1);
  assert(s_none->head->next == NULL);

  // Test the soll_remove function
  assert(soll_remove(s_none, "one"));
  assert(s_none->size == 0);
  assert(s_none->head == NULL);
  assert(!soll_remove(s_none, "three")); // Element not in the list

  // Test the soll_isin function
  long cnt = 0;
  assert(!soll_isin(s_none, "two", &cnt));
  assert(cnt == 0); // No pointer chase occurred

  // Test the soll_tostring function
  char str_none[LISTSTRLEN];
  soll_tostring(s_none, str_none);
  assert(strcmp(str_none, "") == 0);

  // Test the soll_freq function
  assert(soll_freq(s_none, "two") == 0);

  // Test the soll_free function
  assert(soll_free(s_none));

  // Following tests for organisation type mtf
  // Test the soll_init function
  soll *s_mtf = soll_init(mtf);
  assert(s_mtf != NULL);
  assert(s_mtf->type == mtf);
  assert(s_mtf->size == 0);
  assert(s_mtf->head == NULL);

  // Test the soll_add function
  soll_add(s_mtf, "one");
  assert(s_mtf->size == 1);
  assert(strcmp(s_mtf->head->str, "one") == 0);
  assert(s_mtf->head->freq == 1);
  assert(s_mtf->head->next == NULL);

  // Test the soll_remove function
  assert(soll_remove(s_mtf, "one"));
  assert(s_mtf->size == 0);
  assert(s_mtf->head == NULL);

  // Test the soll_isin function
  cnt = 0;
  assert(!soll_isin(s_mtf, "two", &cnt));
  assert(cnt == 0); // No pointer chase occurred

  // Test the soll_tostring function
  char str_mtf[LISTSTRLEN];
  soll_tostring(s_mtf, str_mtf);
  assert(strcmp(str_mtf, "") == 0);

  // Test the soll_freq function
  assert(soll_freq(s_mtf, "two") == 0);

  // Test the soll_free function
  assert(soll_free(s_mtf));

  // Following tests for organisation type transpose
  // Test the soll_init function
  soll *s_transpose = soll_init(transpose);
  assert(s_transpose != NULL);
  assert(s_transpose->type == transpose);
  assert(s_transpose->size == 0);
  assert(s_transpose->head == NULL);

  // Test the soll_add function
  soll_add(s_transpose, "one");
  assert(s_transpose->size == 1);
  assert(strcmp(s_transpose->head->str, "one") == 0);
  assert(s_transpose->head->freq == 1);
  assert(s_transpose->head->next == NULL);

  // Test the soll_remove function
  assert(soll_remove(s_transpose, "one"));
  assert(s_transpose->size == 0);
  assert(s_transpose->head == NULL);

  // Test the soll_isin function
  cnt = 0;
  assert(!soll_isin(s_transpose, "two", &cnt));
  assert(cnt == 0); // No pointer chase occurred

  // Test the soll_tostring function
  char str_transpose[LISTSTRLEN];
  soll_tostring(s_transpose, str_transpose);
  assert(strcmp(str_transpose, "") == 0);

  // Test the soll_freq function
  assert(soll_freq(s_transpose, "two") == 0);

  // Test the soll_free function
  assert(soll_free(s_transpose));

  printf("White-box Testing Passed!\n\n");
}

// Black-box testing function
void black_box_test() {
  printf("Start Black-box Testing...\n");

  // Test for organisation type none
  soll *s_none = soll_init(none);
  assert(s_none != NULL);
  assert(soll_size(s_none) == 0);

  soll_add(s_none, "one");
  soll_add(s_none, "two");
  soll_add(s_none, "three");
  soll_add(s_none, "four");
  assert(soll_size(s_none) == 4);

  // Access elements and check positions (should not move)
  long cnt = 0;
  assert(soll_isin(s_none, "two", &cnt));
  assert(cnt == 1); // Element at index 1, 1 pointer chase
  cnt = 0;
  assert(soll_isin(s_none, "three", &cnt));
  assert(cnt == 2); // Element at index 2, 2 pointer chases

  // Add new elements
  soll_add(s_none, "five");
  soll_add(s_none, "six");
  assert(soll_size(s_none) == 6);

  // Check positions of accessed elements (should not move)
  cnt = 0;
  assert(soll_isin(s_none, "two", &cnt));
  assert(cnt == 1); // Element at index 1, 1 pointer chase
  cnt = 0;
  assert(soll_isin(s_none, "three", &cnt));
  assert(cnt == 2); // Element at index 2, 2 pointer chases

  assert(soll_free(s_none));

  // Test for organisation type mtf
  soll *s_mtf = soll_init(mtf);
  assert(s_mtf != NULL);
  assert(soll_size(s_mtf) == 0);

  soll_add(s_mtf, "one");
  soll_add(s_mtf, "two");
  soll_add(s_mtf, "three");
  soll_add(s_mtf, "four");
  assert(soll_size(s_mtf) == 4);

  // Access elements and check positions (should move to head)
  cnt = 0;
  assert(soll_isin(s_mtf, "three", &cnt));
  assert(cnt == 2); // Element moved to head, 0 pointer chases
  cnt = 0;
  assert(soll_isin(s_mtf, "two", &cnt));
  assert(
      cnt ==
      2); // Element 'moved down' a place in list where "three" occupied before

  // Add new elements
  soll_add(s_mtf, "five");
  soll_add(s_mtf, "six");
  assert(soll_size(s_mtf) == 6);

  // Check positions of accessed elements (should move to head)
  cnt = 0;
  assert(soll_isin(s_mtf, "three", &cnt));
  assert(cnt ==
         1); // Element moved down list by one, as "two" was moved to front
  cnt = 0;
  assert(soll_isin(s_mtf, "two", &cnt));
  assert(cnt ==
         1); // Element moved down list by one, as "three" was moved to frotn

  assert(soll_free(s_mtf));

  // Test for organisation type transpose
  soll *s_transpose = soll_init(transpose);
  assert(s_transpose != NULL);
  assert(soll_size(s_transpose) == 0);

  soll_add(s_transpose, "one");
  soll_add(s_transpose, "two");
  soll_add(s_transpose, "three");
  soll_add(s_transpose, "four");
  assert(soll_size(s_transpose) == 4);

  // Access elements and check positions (should move closer to head)
  cnt = 0;
  assert(soll_isin(s_transpose, "three", &cnt));
  assert(cnt == 2); // Element moved one position closer, 2 pointer chase
  cnt = 0;
  assert(soll_isin(s_transpose, "three", &cnt));
  assert(cnt == 1); // Element moved one position closer, 1 pointer chase
  cnt = 0;
  assert(soll_isin(s_transpose, "two", &cnt));
  assert(cnt == 2); // Element moved two positions down from a double isin
                    // access of "three"

  // Add new elements
  soll_add(s_transpose, "five");
  soll_add(s_transpose, "six");
  assert(soll_size(s_transpose) == 6);

  // Check positions of accessed elements (should move closer to head)
  cnt = 0;
  assert(soll_isin(s_transpose, "three", &cnt));
  assert(cnt == 0); // Element moved to head, 0 pointer chase
  cnt = 0;
  assert(soll_isin(s_transpose, "two", &cnt));
  assert(cnt == 1); // Element moved one position closer, 1 pointer chase

  assert(soll_free(s_transpose));

  printf("Black-box Testing Passed!\n\n");
}
