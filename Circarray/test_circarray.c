/*
 * This file contains executable code for testing your work in this assignment.
 */

#include <stdio.h>
#include <stdlib.h>
#include "circarray.h"



int main(int argc, char** argv) {
  struct circarray* queue = circarray_create();
  printf("\noperation: enqueue 2\n");
  circarray_enqueue(queue,2);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: enqueue 3\n");
  circarray_enqueue(queue,3);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: enqueue 5\n");
  circarray_enqueue(queue,5);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: dequeue\n");
  circarray_dequeue(queue);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: enqueue 7\n");
  circarray_enqueue(queue,7);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: enqueue 11\n");
  circarray_enqueue(queue,11);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: dequeue\n");
  circarray_dequeue(queue);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: enqueue 13\n");
  circarray_enqueue(queue,13);
  circarray_print(queue);
  circarray_print_array(queue);
  printf("\noperation: enqueue 17\n");
  circarray_enqueue(queue,17);
  circarray_print(queue);
  circarray_print_array(queue);
}
