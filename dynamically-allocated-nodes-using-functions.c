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

void insert_at_head(node_t **head, node_t **node_to_insert) {
	(*node_to_insert)->next = *head;
	*head = *node_to_insert;
}

int main() {
	node_t *head = NULL;
	node_t *tmp;
	int i = 0;

	while (i < 11) {
		tmp = create_new_node(i++);
		insert_at_head(&head, &tmp);
	}

	printlist(head);

	return 0;	
}
