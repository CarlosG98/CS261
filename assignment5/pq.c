/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Carlos Gonzalez
 * Email: gonzalc5@oregonstate.edu
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 * in addition, you want to define an element struct with both data and priority, 
 * corresponding to the elements of the priority queue. 
 */
struct pq {
  struct dynarray* array;
};

struct element {
  int priority;
  void* data;
};


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {

  struct pq* priqueue = malloc(sizeof(struct pq)); //create and allocate memory for a pointer to priority queue
  priqueue->array = dynarray_create();//create the dynarray associated with the priority queue
  return priqueue;

}


/*  
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {

  dynarray_free(pq->array); //free dynarray first
  free(pq); //then free priority queue

}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
  if(dynarray_length(pq->array) == 0){ //if length of array is 0, then there are no elements.
    return 1;
  }
  return 0;
}

/*
 * This function should swap a node with it's parent or desired child node. 
 *
 * Params:
 *   pq - the priority queue.
 *   node - node that is percolating down/up
 *   swap_node - parent/child node that is to be swapped with current node. 
 *   node_idx - current node's index
 *   swapnode_idx - parent/child 's index
 * Return:
 *   
 */
void swap(struct pq* pq, struct element* node, struct element* swap_node, int node_idx, int swapnode_idx){

  struct element* temp = swap_node; //temp element gets data from parent/child node
  dynarray_set(pq->array, swapnode_idx, node); // node gets placed at parent/child index
  dynarray_set(pq->array, node_idx, temp); //place temp data at node index
}

/*
 * This function should take the end node of the array and percolate it up the heap to its appropriate position. 
 *
 * Params:
 *   pq - the priority queue.
 *   idx - the index of the end node.
 * Return:
 *   
 */
void percolate_up(struct pq* pq, int idx){

  int swapped;
  do{
    swapped = 0; //start loop with swapped = false
    int parent_idx = (idx-1)/2;
    struct element* node = dynarray_get(pq->array, idx);
    struct element* parent = dynarray_get(pq->array, parent_idx);

    if(node->priority > parent->priority){ //if node has higher priority than parent
      swap(pq, node, parent, idx, parent_idx); //swap them
      idx = parent_idx; //nodes idx is now parents former idx
      swapped = 1; //swapped = true
    }
  }while(swapped == 1); //if swapped, repeat process
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, higher priority
 * values are given precedent, and higher place in the queue.  In other words, the
 * element in the priority queue with the highest priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   data - the data value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, higher priority values
 *     should correspond to the first elements.  In other words,
 *     the element in the priority queue with the highest priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* data, int priority) {

  struct element* new_element;
  assert(pq);

  new_element = malloc(sizeof(struct element)); //allocate memory for new node
  new_element->priority = priority;
  new_element->data = data;

  dynarray_insert(pq->array, dynarray_length(pq->array), new_element); //insert at end of array
  percolate_up(pq, dynarray_length(pq->array) -1); //send node to appropriate position
}


/*
 * This function should return the data of the first element in a priority
 * queue, i.e. the data associated with the element with highest priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the data of the first item in pq, i.e. the item with
 *   max priority value.
 */
void* pq_max(struct pq* pq) {
  struct element* node;
  assert(pq);

  node = dynarray_get(pq->array, 0);
  return node->data;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with highest priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with highest priority value.
 */
int pq_max_priority(struct pq* pq) {
  struct element* node;
  assert(pq);

  node = dynarray_get(pq->array, 0);
  return node->priority;
}

/*
 * This function should compare a node's priority to its parent/child 's priority and swap them if necessary.
 *
 * Params:
 *   pq - the priority queue 
 *   node - the node percolating down
 *   child - the child to be swapped with node
 *   swapped - the swapped indicator
 *   node_idx - the node's current index
 *   child_idx - the child's index
 *
 * Return:
 */
void compare(struct pq* pq, struct element* node, struct element* child, int* swapped, int *node_idx, int *child_idx){

  if(node->priority < child->priority){
    swap(pq, node, child, *node_idx, *child_idx);
    *node_idx = *child_idx;
    *swapped = 1;
  }
}
  
/*
 * This function should take the root and percolate it down the heap to its appropriate position
 *
 * Params:
 *   pq - the priority queue to retrieve the root node from its heap
 *  
 * Return:
 */
void percolate_down(struct pq* pq){
  int swapped; //swapped indicator
  int node_idx = 0; //start at the root
  int child1_idx, child2_idx; //left and right children's indices
  struct element* node = NULL, *child1 = NULL, *child2 = NULL;
  do{

    swapped = 0; //start loop with swap = false
    child1_idx = (node_idx*2)+1, child2_idx = (node_idx*2)+2; //calculate children's indices based on node's current position
    
    if(node_idx < dynarray_length(pq->array)){
      node = dynarray_get(pq->array, node_idx);
    }else{
      node = NULL;
    }

    if(child1_idx < dynarray_length(pq->array)){ //if left child exists
      child1 = dynarray_get(pq->array, child1_idx); //retrieve it
    }else{
      child1 = NULL;
    }
    if(child2_idx < dynarray_length(pq->array)){ //if right child exists
      child2 = dynarray_get(pq->array, child2_idx); //retrieve it
    }else{
      child2 = NULL;
    }

    if(child1 != NULL && child2 == NULL){ //if only left exists
      compare(pq, node, child1, &swapped, &node_idx, &child1_idx); //compare left child to node
    }
    else if(child1 == NULL && child2 != NULL ){//else if only right exists
      compare(pq, node, child2, &swapped, &node_idx, &child2_idx);//compare right to node
    }
    else if(child1 != NULL && child2 != NULL){ //if both exists
      if(child1->priority > child2->priority){ //take child with higher priority and compare to node
        compare(pq, node, child1, &swapped, &node_idx, &child1_idx);
      }else{
        compare(pq, node, child2, &swapped, &node_idx, &child2_idx);
      }
    }
  }while(swapped == 1);
}

/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with highest priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   highest priority value.
 */
void* pq_max_dequeue(struct pq* pq) {
 
  struct element* max = dynarray_get(pq->array, 0); //get root node
  struct element* min = dynarray_get(pq->array, -1); //get end node

  void* val = max->data; //store root node's data

  dynarray_set(pq->array, 0, min); //place end node at the root
  dynarray_remove(pq->array, -1); //remove end node, shortening array
  percolate_down(pq); //send root node down

  free(max); //free node that was removed
  return val;
}
