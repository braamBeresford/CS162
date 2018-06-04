#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int length(struct node* head) {
	int count = 0;
	int i;
	int first_time = 0;
	struct node* current = head;
	while (1) {
		if (current != NULL && first_time == 1) {
			count++;
			current = current->next;
		}
		else if (first_time == 0)
			;
		else {
			count--;
			return count;
		}
		first_time = 1;

	}
};


void print(struct node * head, int number) {
	int i;
	struct node* current = head;
	if (head->next == NULL) {
		printf("There is nothing in this linked list\n" );
		return;
	}
	current = current->next; //This is to skip head
	for (i = 0; i < number; i++) {
		if (current != NULL) {
			printf("%d ", current->val);
			current = current->next;
		}

		else {
			putchar('\n');
			return;
		}
	}

}

struct node * push(struct node* head, int value) {
	struct node* new_node = malloc(sizeof(struct node));

	new_node->val = value;

	new_node->next = head->next;
	head->next = new_node;

	return head;

}

struct node * append(struct node* head, int value) {
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = value;
	struct node* current = head;

	if (head->next == NULL) {
		head->next = new_node;
		new_node->next = NULL;
	}

	else {
		while (1) {
			if (current != NULL) {

				current = current->next;
			}


			else {

				current = new_node;
				new_node->next = NULL;
				break;
			}
		}
	}

	return head;
}

struct node * clear(struct node * head) {
	struct node* current = head;
	struct node* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	head->next = NULL;
	return head;
}

struct node * remove_node(struct node *head, int index) {
	struct node * current = head;
	struct node * temp;
	if (index > length(head) - 1) {
		printf("\nThe index you have provided is not within the bounds\n");
		return head;
	}


	int i;
	for (i = 0; i < index; i++) {
		current = current->next;
	}
	temp = current->next->next;
	free(current->next);
	current->next = temp;


	return head;
}

struct node *sort_ascending(struct node* head) {
	int i;
	struct node * current = head;
	struct node * temp;
	int un_sorted = 0;
	do {
		un_sorted = 1;
		current = head;
		for (i = 0; i < length(head); i++) {
			if(current->next == NULL)
				continue;
			else if (current->val > current->next->val) { 
				temp = current->next->next->next;
				current->next->next->next = current->next;
				current->next = current->next->next;
				current->next->next->next = temp;
				un_sorted = 0;
			}	
			current = current->next;
		}

	} while (un_sorted);


	return head;

}

struct node * insert_middle(struct node* head, int index, int value) {
	struct node* current = head;
	if (index > length(head)) {
		printf("\nThe index you have chosen is out of range for this list\n");
		return head;
	}
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = value;
	struct node* temp;


	int i;
	for (i = 0; i < index; i++) {
		current = current->next;
	}

	temp = current->next;
	current->next = new_node;
	new_node->next = temp;

	return head;


}
int main() {
	struct node* head =  malloc(sizeof(struct node));

	head->next = NULL;
	head->val = 0;

	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 3);
	head = push(head, 4);
	// head = push(head, 2);
	// head = push(head, 1);
	// head = push(head, 4);
	// head = push(head, 3);
	// head = push(head, 4);
	// head = push(head, 3);
	// head = push(head, 4);
	// head = push(head, 3);
	// head = push(head, 4);
	// head = push(head, 3);
	// head = push(head, 4);


	// printf("Length %d\n", length(head));
	// print(head, 5);
	// // // head = clear(head);
	// head = remove_node(head, 2);
	// putchar('\n');



	// head = insert_middle(head, 3, 8);

	// printf("Length %d\n", length(head));
	print(head, 5);
	sort_ascending(head);
	// putchar('\n');
	// clear(head);
	print(head, 5);
	return 0;
}