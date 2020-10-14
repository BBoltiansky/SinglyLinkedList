#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct llnode{
	void *value;
	struct llnode *next;
};	
struct linked_list{
	struct llnode *head;
	int size;
};

static inline struct linked_list* ll_create(void)
{
  //Allocate memory for head pointer and size int.
	struct linked_list *ll = malloc(sizeof(struct linked_list));
    if (ll == NULL) {
        printf("No memory available for linked list.\n");
        return NULL;
    }
    ll->head = NULL;
    ll->size = 0;
    return ll;
}

static inline int ll_destroy(struct linked_list *ll)
{	//if list has no nodes, free ll and return 1, else return 0
	if(ll->size == 0){
		free(ll);
    printf("Successfully deleted linked list.\n");
		return 1;
	}else{
		return 0;
	}
}

static inline void ll_add(struct linked_list *ll, void *value)
{
  //create new node, set next and prev to NULL for initialization
	struct llnode *newNode = malloc(sizeof(struct llnode));
  newNode->value = value;
  newNode->next = NULL;
  //if there is no first node, ll is empty. Create first node, set it as the head and tail.
  if(ll->size == 0){
    ll->head = newNode;
    ll->size = 1 + ll->size;
  }else{
    //if there is at least one node, make new node the head. Increment size, move, old node over.
    newNode->next = ll->head;
    ll->head = newNode;
    ll->size += 1;
  }
  
  return;
}

static inline int
ll_length(struct linked_list *ll)
{
  //we store the size of the linked list, so just return it.
  return ll->size;
}

static inline void *
ll_remove_first(struct linked_list *ll)
{
  //first check if there is a node to remove
	if(ll->size != 0){
    struct llnode *node = ll->head;
    if(ll->size == 1){
      //if there is only one node. save value so that we can free the node, decrease size, and return value
      void *retval = node->value;
      free(node);
      ll->size = 0;
      ll->head = NULL;
      return retval;
    }else{
      //Otherwise, we need to set the second node as the first, and repeat the process of saving value to return it.
      ll->head = node->next;
      void *retval = node->value;
      free(node);
      ll->size = ll->size - 1;
      return retval;
    }
  }else{
    return NULL;
  }
}

static inline int
ll_contains(struct linked_list *ll, void *value)
{
  //create a new node for iteration
  struct llnode *node = ll->head;
  int i;
  //Iterate through ll comparing value of node to parameter's value. If found, return i, else return 0.
  for(i = 1; i <= ll->size; i++){
    if(node->value == value){
      return i;
    }else{
      node = node->next;
    }
  }
  return 0;
}

static inline void ll_print(struct linked_list *ll){
  if(ll->size != 0){
    struct llnode *node = ll->head;
    int i;
    for(i = 1; i < ll->size; i++){
      printf("%p, ", node->value);
      node = node->next;
    }
    printf("%p. Total Size : %d\n", node->value, ll->size);
    return;
  }else{
    printf("Linked list is empty\n");
    return;
  }
}

#endif
