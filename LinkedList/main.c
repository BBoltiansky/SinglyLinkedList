#include <list.h>
#include "list.h"
int setUp(void);
int
main(void)
{
	if(setUp()){
		struct linked_list *ll = ll_create();
    int a = 25;
    int *p = &a;
    int b = 35;
    int *badd = &b;
    ll_add(ll, badd);
    ll_add(ll, p);
    ll_add(ll, p);
    ll_add(ll, badd);
    ll_add(ll, p);
    ll_add(ll, badd);
    ll_print(ll);
    int length = ll_length(ll);
    printf("Length of LL is : %d\n", length);
    int valueLoc = ll_contains(ll, p);
    printf("Value was found at index %d\n", valueLoc);
    printf("Removed %p\n", ll_remove_first(ll));
    ll_print(ll);
    printf("Removed %p\n", ll_remove_first(ll));
    ll_print(ll);
    printf("Removed %p\n", ll_remove_first(ll));
    ll_print(ll);
    printf("Removed %p\n", ll_remove_first(ll));
    ll_print(ll);
    printf("Removed %p\n", ll_remove_first(ll));
    ll_print(ll);
    printf("Removed %p\n", ll_remove_first(ll));
    ll_print(ll);
    printf("Removed %p\n\n", ll_remove_first(ll));
    ll_print(ll);
    ll_destroy(ll);
    
	}
}

int setUp(void){
	struct linked_list* ll = ll_create();
	if(ll != NULL){
    free(ll);
		printf("\nLinked list set up correctly.\n");
		return 1;
	}else{
		printf("Failed Setup\n");
		return 0;
	}
}
