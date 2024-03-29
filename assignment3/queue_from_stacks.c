/*
 * This is the file in which you'll write the functions required to implement
 * a queue using two stacks.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name:
 * Email:
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "queue_from_stacks.h"

/*
 * This function should allocate and initialize all of the memory needed for
 * your queue and return a pointer to the queue structure.
 */
struct queue_from_stacks* queue_from_stacks_create() {

  struct queue_from_stacks* q = malloc(sizeof(struct queue_from_stacks));
  q->s1 = stack_create();
  q->s2 = stack_create();

  return q;
}

/*
 * This function should free all of the memory allocated to a queue, including
 * the memory associated with each stack.
 *
 * Params:
 *   queue - the queue to be destroyed.  May not be NULL.  The function should
 *     exit the program with an error if queue is NULL.
 */
void queue_from_stacks_free(struct queue_from_stacks* queue) {

  stack_free(queue->s2);
  stack_free(queue->s1);

  free(queue);

}

/*
 * This function should return 1 if a queue is completely empty or 0 if there
 * is at least one element stored in the queue.
 *
 * Params:
 *   queue - the queue whose emptiness is to be checked.  May not be NULL.
 *     The function should exit the program with an error if queue is NULL.
 *
 * Return:
 *   Should return 1 if the queue is empty or 0 otherwise.
 */
int queue_from_stacks_isempty(struct queue_from_stacks* queue) {
  if(stack_isempty(queue->s1) == 1 && stack_isempty(queue->s2) == 1){ //if both stacks are empty then queue is empty
    return 1;
  }
  return 0;
}

/*
 * Should enqueue a new value onto the end of a queue.
 *
 * Params:
 *   queue - the queue onto which to enqueue a value.  May not be NULL.
 *     The function should exit the program with an error if queue is NULL.
 *   value - the new value to be enqueueed onto the queue
 */
void queue_from_stacks_enqueue(struct queue_from_stacks* queue, int value) {
  stack_push(queue->s1, value);
}

/*
 * Should return a queue's front value without removing that value from the
 * queue.
 *
 * Params:
 *   queue - the queue from which to read the front value.  May not be NULL or
 *     empty.  The function should exit the program with an error if queue is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the front of the queue.
 */
int queue_from_stacks_front(struct queue_from_stacks* queue) {

  if(stack_isempty(queue->s2) == 1){ //if pop-stack is empty
    while(stack_isempty(queue->s1) == 0){ //while push-stack is not empty
      int val = stack_pop(queue->s1); //move items from push-stack to pop-stack
      stack_push(queue->s2, val);
    }
  }

  int val = stack_top(queue->s2); //get top from pop-stack

  return val;
}

/*
 * Should remove the front element from a queue and return its value.
 *
 * Params:
 *   queue - the queue from which to dequeue a value.  May not be NULL or
 *     empty.  The function should exit the program with an error if queue is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the front of the queue before that value
 *   is dequeued.
 */
int queue_from_stacks_dequeue(struct queue_from_stacks* queue) {

  if(stack_isempty(queue->s2) == 1){ //if pop-stack is empty
    while(stack_isempty(queue->s1) == 0){ // while push-stack is not empty
      int val = stack_pop(queue->s1); // move items from push-stack to pop-stack
      stack_push(queue->s2, val);
    }
  }

  int val = stack_pop(queue->s2); //pop from pop-stack

  return val;
}
