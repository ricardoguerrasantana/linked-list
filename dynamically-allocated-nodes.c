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

node_t *create_new_node(int value){
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

int main() {
	node_t *head;
	node_t *tmp;

	tmp = create_new_node(45);
	head = tmp;
	tmp = create_new_node(8);
	tmp->next = head; // current head linked after new node
	head = tmp; // new node added to the front of the list
	tmp = create_new_node(32);
	tmp->next = head;
	head = tmp;
	tmp = create_new_node(42);
	tmp->next = head;
	head = tmp;

	printlist(head);

	return 0;	
}
