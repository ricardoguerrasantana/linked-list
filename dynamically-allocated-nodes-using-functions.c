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

node_t *create_new_node(int value) {
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

void insert_at_head(node_t **head, node_t **node_to_insert) {
	(*node_to_insert)->next = *head;
	*head = *node_to_insert;
}

void insert_at_tail(node_t **tail, node_t **node_to_insert) {
	(*tail)->next = *node_to_insert;
	*tail = *node_to_insert;
}

void insert_after_node(node_t **node, node_t **node_to_insert) {
	(*node_to_insert)->next = (*node)->next;
	(*node)->next = *node_to_insert;
}

node_t *find_node(node_t *head, int value) {
	node_t *tmp;

	tmp = head;
	while (tmp) {
		if (tmp->value == value) return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

int main() {
	node_t *head = NULL;
	node_t *tail = NULL;
	node_t *tmp;
	int i = 0;

	while (i < 11) {
		tmp = create_new_node(i++);
		insert_at_head(&head, &tmp);
	}

	printlist(head);

	tmp = find_node(head, 3);
	printf("found node with value of %i\n", tmp->value);

	head = NULL;
	i = 0;
	while (i < 11) {
		tmp = create_new_node(i++);
		if (!tail) {
			tail = tmp;
			head = tail;
		}
		insert_at_tail(&tail, &tmp);
	}

	node_t *node = find_node(head, 8);
	tmp = create_new_node(1008);
	insert_after_node(&node, &tmp);

	printlist(head);

	return 0;	
}
