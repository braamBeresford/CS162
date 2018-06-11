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




struct node *swap( struct node *a, struct node *b )
{
    a->next = b->next;
    b->next = a;
    return b;
}

struct node *sort_ascending( struct node *head )
{

	if(head ==  NULL)
		return head;
    struct node *temp1, *temp2, *current;
    bool unsorted = true;

    current = (struct node *)malloc(sizeof(struct node));

    current->next = head;
    if(head->next != NULL) {

        while( unsorted ) {
            unsorted = false;
            temp2 = current;
            temp1 = current->next;
            while( temp1->next != NULL ) {
                if( temp1->val > temp1->next->val ) {
                    temp2->next = swap( temp1, temp1->next );
                    unsorted = true;
                }
                temp2 = temp1;
                if(temp1->next)
                    temp1 = temp1->next;
            }
        }
    }
    temp1 = current->next;
    free( current );
    return temp1;
}

struct node *sort_descending(struct node* head) {
	if(head ==  NULL)
		return head;
    struct node *temp1, *temp2, *current;
    bool unsorted = true;

    current = (struct node *)malloc(sizeof(struct node));

    current->next = head;
    if(head->next != NULL) {

        while( unsorted ) {
            unsorted = false;
            temp2 = current;
            temp1 = current->next;
            while( temp1->next != NULL ) {
                if( temp1->val < temp1->next->val ) {
                    temp2->next = swap( temp1, temp1->next );
                    unsorted = true;
                }
                temp2 = temp1;
                if(temp1->next)
                    temp1 = temp1->next;
            }
        }
    }
    temp1 = current->next;
    free( current );
    return temp1;
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
