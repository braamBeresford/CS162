#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int length(struct node* head) { //Works
	int count = 0;
	int i;
	int first_time = 0;
	struct node* current = head;
	while (1) {
		if (current != NULL) {
			count++;
			current = current->next;
		}

		if (current == NULL)
			return count;

	}
};


void print(struct node * head, int number) { ///Works
	int i;
	struct node* current = head;
	if (head == NULL) {
		printf("There is nothing in this linked list\n" );
		return;
	}

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
	putchar('\n');

}

struct node * push(struct node* head, int value) {//works
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = value;
	new_node->next = head;
	head = new_node;

	return head;

}

struct node * append(struct node* head, int value) { //works
	int i;
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = value;
	new_node->next = NULL;

	struct node* current = head;

	if (head == NULL) {
		head = new_node;
	}

	else {
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = new_node;
	}

	return head;
}

struct node * clear(struct node * head) {//Works
	struct node* current = head;
	struct node* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
	return head;
}

struct node * remove_node(struct node *head, int index) { //works
	struct node * current = head;
	struct node * temp;

	if (index > length(head)) {
		printf("\nThe index you have provided is not within the bounds\n");
		return head;
	}

	int i;
	if (index == 0) {
		temp = current->next;
		free(current);
		head = temp;
		return head;
	}

	for (i = 0; i < index - 1; i++) { // -1 so we are the node before the one being deleted
		current = current->next;
	}
	temp = current->next->next;
	free(current->next);

	current->next = temp;

	return head;
}

struct node * swap(struct node* current){
	struct node * temp1 = current->next->next->next;
	struct node * temp2 = current->next->next;
	struct node * temp3 = current->next;

	current->next = temp2;
	current->next->next = temp3;
	current->next->next->next=temp1;
	return current;
}

struct node *sort_ascending(struct node* head) {
	int i;
	struct node * current = head;
	struct node * temp;
	bool un_sorted;
	do {
		un_sorted = false;
		current = head;
		for (i = 0; i < length(head); i++) {
			if(current->next->next == NULL){
				un_sorted = true;
				printf("Oh no :(\n");
				break;
			}
			if (current->next->val > current->next->next->val) {
				un_sorted = true;
				printf("Actiavted\n");
				current = swap(current);
			}
			current = current->next;
		}
		printf("still running %d\n", un_sorted);
		print(head, 100);
	} while (un_sorted);


	return head;
}

struct node *sort_descending(struct node* head) {
	int i;
	struct node * current = head;
	struct node * temp;
	bool un_sorted;
	do {
		un_sorted = true;
		current = head;
		for (i = 0; i < length(head); i++) {
			if(current->next->next == NULL)
				return head;
			if (current->next->val < current->next->next->val) {
				un_sorted = false;
				current = swap(current);
			}
			current = current->next;
		}

	} while (un_sorted);


	return head;

}

struct node * insert_middle(struct node* head, int index, int value) {
	struct node* current = head;
	if (index > length(head) - 1) {
		printf("\nThe index you have chosen is out of range for this list\n");
		return head;
	}

	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = value;
	struct node* temp;

	if (index == 0) {
		temp = head;
		head = new_node;
		head->next = temp;
		return head;
	}

	int i;
	for (i = 0; i < index - 1; i++) {
		current = current->next;
	}
	temp = current->next;
	current->next = new_node;
	new_node->next = temp;

	return head;


}
int main() {
	struct node* head =  NULL;

	head->val;

	
	head = append(head, 4);
	printf("VALLL%d\n ", head->val);
	return 0;
	head = append(head, 5);
	head = append(head, 2);
	head = append(head, 3);
	head = append(head, 6);
	head = append(head, 8);
	head = append(head, 7);
	head = append(head, 89);
	head = append(head, 10);
	head = append(head, 9);

	print(head, 100);
	// head->next = swap(head->next);
	head = sort_ascending(head);
	// head = sort_descending(head);
	print(head, 100);
	// printf("Length %d\n", length(head));
	// print(head, 5);
	// // // head = clear(head);
	// head = remove_node(head, 2);
	// putchar('\n');



	// head = insert_middle(head, 3, 8);

	// printf("Length %d\n", length(head));

	// print(head, 5);

	// head = insert_middle(head, 4, 8);

	// print(head, 5);
	// printf("Length %d\n", length(head));
	// head = remove_node(head, 2);
	// print(head, 5);
	// printf("Length %d\n", length(head));
	// putchar('\n');
	
	// clear(head);
	// print(head, 5);
	return 0;
}