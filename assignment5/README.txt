Author: Carlos Gonzalez
Date: May 31, 2020

Priority Queue Program

The priority queue contains a dynamic array that is used to implement a heap. The array is 
filled with items of type struct element. Each element contains data and its priority key. 

Functions:

	struct pq* pq_create() - This function creates and allocates memory for a priority queue and its
				 dynamic array. Returns a pointer to the priority queue. 

	void pq_free(struct pq*) - Takes in a pointer to a priority queue, frees its dynarray then frees
				   the priority queue.
	
	int pq_isempty(struct pq*) - Takes in a pointer to a priority queue. uses the length of the 
				     dynarray to determine whether it is empty. Returns 1 if empty.

	void swap(...) - This function passes in a priority queue, two nodes to be swapped and their
			 indices. Uses the dynarray_set() function to swap positions in array. 

	void percolate_up(...) - This function takes the recently added node and sends it up the heap
				 to its appropriate position to satisfy the max heap property.

	void pq_insert(...) - this function takes in data and a priority key. Creates a new node and 
			      gets assigned the passed in data and key. Then is inserted at the end of
			      the array. Calls the percolate_up() function to maintain max heap property.

	void* pq_max(...) - Returns the data associated with the node of highest priority. Does not remove
			    the node.

	int pq_max_priority(...) - returns the priority value of the node of highest priority. Does not remove
				   the node. 

	void compare(...) - Helper function for percolate_down(...). Takes in a node and its child and compares
			    their priority values. Swaps nodes if necessary. If swapped, then node's new index is its
			    childs index. Set swapped indicator to true.

	void percolate_down(...) - Takes the root node, which was previously swapped with the max node. Identifies its
				   left and right child, if they exist. Take the child with higher priority, and use it
				   to compare priority values to the node. Swap if necessary. Repeat until it reaches its
				   appropriate position in heap. 

	void* pq_max_dequeue(...) - returns the data of the node with highest priority. then removes it from the queue.
				    uses helper function to maintain max heap property.