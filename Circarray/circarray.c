/*
 * This file contains the definitions of structures and functions implementing
 * a dynamic array.  You should not modify anything in this file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "circarray.h"

#define CIRCARRAY_INIT_CAPACITY 1

/*
 * This is the definition of the dynamic array structure.  Note that because
 * we're storing int pointers as int*, the data array needs to be an
 * array of int
 */
struct circarray {
  int* array;
  int length;
  int capacity;
  int offset;
};


struct circarray* circarray_create() {
  struct circarray* ca = malloc(sizeof(struct circarray));
  assert(ca);

  assert(ca->array);
  ca->length = 0;
  ca->capacity = CIRCARRAY_INIT_CAPACITY;
  ca->array = malloc(CIRCARRAY_INIT_CAPACITY * sizeof(int));

  return ca;
}


void circarray_free(struct circarray* ca) {
  assert(ca);
  free(ca->array);
  free(ca);
}


int circarray_length(struct circarray* ca) {
  assert(ca);
  return ca->length;
}


/*
 * Auxilliary function to perform a resize on the underlying array.
 */
void _circarray_resize(struct circarray* ca) {
  /*
   * Allocate space for the new array.
   */
  int* new_array = malloc(2 * ca->capacity * sizeof(int));
  assert(new_array);

  /*
   * Copy data from the old array to the new one.
   * we will loop through the "abstract" j indices, and copy the i indicies:
   */
  for (int j = 0; j < ca->length; j++) {    
    int i = ( ca->offset + j ) % ca->capacity;
    //printf("mapping j -> i: %d -> %d\n",i,j);
    new_array[j] = ca->array[i];
  }

  /*
   * Put the new array into the circarray struct.
   */
  free(ca->array);
  ca->array = new_array;
  ca->capacity *= 2;
  ca->offset = 0;
}


void circarray_enqueue(struct circarray* ca, int val) {
  assert(ca);
  /*
   * Make sure we have enough space for the new element.
   */
  if (ca->length == ca->capacity) {
    _circarray_resize(ca);
  }
  /*
   * Enqueue the new element into the array.
   * should be defined by this equation because j = length
   */
  int i = ( ca->offset + ca->length ) % ca->capacity;
  printf("--> enqueue %d to i=%d\n",val,i);
  ca->array[i] = val;
  ca->length++;
}


int circarray_dequeue(struct circarray* ca) {
  assert(ca);

  /* we want the first term, so j = 0 */
  int i = ( ca->offset + 0 ) % ca->capacity;
  int val = ca->array[i];
  ca->length--;
  ca->offset++;
  ca->array[i] = 0;

  return val;
}


int circarray_get(struct circarray* ca, int j) {
  assert(ca);
  int i = ( ca->offset + j ) % ca->capacity;
  assert((i < ca->length && i >= 0) || i == -1);

  return ca->array[i];
}


void circarray_set(struct circarray* ca, int j, int val) {
  assert(ca);
  int i = ( ca->offset + j ) % ca->capacity;
  assert((i < ca->length && i >= 0) || i == -1);

  ca->array[i] = val;
}

void circarray_print(struct circarray* ca) {
  assert(ca);
  printf("\nlength = %d\n",ca->length);
  for(int j=0; j < ca->length; j++) {
    int i = ( ca->offset + j ) % ca->capacity;
    printf("queue[%d] = %d\n",j,ca->array[i]);
  }
}

void circarray_print_array(struct circarray* ca) {
  assert(ca);
  printf("\nlength = %d\n",ca->length);
  for(int i=0; i < ca->capacity; i++) {
    printf("array[%d] = %d\n",i,ca->array[i]);
  }
}
