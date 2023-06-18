#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node* next;
};
typedef struct node node_t;

void printlist(node_t *head) {
	node_t	*tmp = head;

	while (tmp) {
		printf("%i", tmp->value);
		if (tmp->next)
			printf(" - ");
		tmp = tmp->next;
	}	
	printf("\n");
}

int main() {
	node_t n1, n2, n3, n4;
	node_t *head;

	n1.value = 45;
	n2.value = 8;
	n3.value = 32;
	n4.value = 42;

	//link them up
	head = &n2;
	n3.next = &n4;
	n2.next = &n3;
	n1.next = NULL; //so we know when to stop
	n4.next = &n1; 


	printlist(head);

	return 0;	
}
