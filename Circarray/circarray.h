/*
 * This file contains the definition of an interface for a dynamic array.
 * You should not modify anything in this file, but you can find descriptions
 * of the dynamic array functions, including their parameters and their return
 * values, below.
 */

#ifndef __CIRCARRAY_H
#define __CIRCARRAY_H

/*
 * Structure used to represent a circular array.
 */
struct circarray;

/*
 * Creates a new, empty dynamic array and returns a pointer to it.
 */
struct circarray* circarray_create();

/*
 * Free the memory associated with a dynamic circular array.  Note that, while this
 * function cleans up all memory used in the array itself, it does not free
 * any memory allocated to the pointer values stored in the array.  This is
 * the responsibility of the caller.
 *
 * Params:
 *   da - the circular array to be destroyed.  May not be NULL.
 */
void circarray_free(struct circarray* da);

/*
 * Returns the length (i.e. the number of elements) of a given circular array.
 */
int circarray_length(struct circarray* da);

/*
 * Enqueues a new element to a circular array at a specified index.  All existing
 * elements following the specified index are moved back to make room for the
 * new element.
 *
 * Params:
 *   da - the circular array into which to insert an element.  May not be NULL.
 *   val - the value to be inserted.  Note that this parameter has type int,
 *     which means that a pointer of any type can be passed.
 */
void circarray_enqueue(struct circarray* da, int val);

/*
 * dequeues the element at a the begining from a circular array.  All existing
 * elements following the specified index are moved forward to fill in the
 * gap left by the removed element.
 *
 * Params:
 *   da - the circular array from which to dequeue an element.  May not be NULL.
 */
int circarray_dequeue(struct circarray* da);

/*
 * Returns the value of an existing element a circular array array.  Note that
 * this value is returned as type int
 *
 * Params:
 *   da - the circular array from which to get a value.  May not be NULL.
 *   idx - the index of the element whose value should be returned.  Must
 *     be between 0 and the length of the array.The special value -1 may also
 *     be passed to return the element at the end of the array.
 */
int circarray_get(struct circarray* da, int idx);

/*
 * Sets an existing element in a circular array array to a new value.
 *
 * Params:
 *   da - the circular array in which to set a value.  May not be NULL.
 *   idx - the index of the element whose value is to be set.  Must be
 *     between 0 and the length of the array. The special value -1 may also be
 *     passed to set the element at the end of the array.
 *   val - the new value to be set.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void circarray_set(struct circarray* da, int j, int val);

/*
 * prints the entire circular array
 *
 * Params:
 *   da - the circular array in which to set a value.  May not be NULL.
 */
void circarray_print(struct circarray* da);

void circarray_print_array(struct circarray* ca);



#endif
