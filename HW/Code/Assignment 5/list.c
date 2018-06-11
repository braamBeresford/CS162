/********************************************************************* 
 ** Program Filename:  list.c
 ** Author: Braam Beresford
 ** Date: 06/10/2018
 ** Description: Basic linked list functions
 ** Input: User
 ** Output: Command line
 *********************************************************************/ 
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********************************************************************* 
 ** Function: Length 
 ** Description: Returns length of linked list
 ** Parameters:  Valid head pointer
 ** Pre-Conditions: 
 ** Post-Conditions: Returns length of list 
 *********************************************************************/ 
int length(struct node* head) { 
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

/********************************************************************* 
 ** Function: Print
 ** Description: Prints linked list until index or NULL
 ** Parameters:  Head pointer and number of index
 ** Pre-Conditions: A non-null head pointer, 
 ** Post-Conditions: Printed linked list
 *********************************************************************/
void print(struct node * head, int number) { 
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

/********************************************************************* 
 ** Function: Push
 ** Description: Places a node with a given value at the front
 ** Parameters:  Head pointer and value for insertion
 ** Pre-Conditions: Correct parameters, can be NULL head
 ** Post-Conditions: Returns head pointer
 *********************************************************************/
struct node * push(struct node* head, int value) {
	struct node* new_node = malloc(sizeof(struct node));
	new_node->val = value;
	new_node->next = head;
	head = new_node;

	return head;

}

/********************************************************************* 
 ** Function: Append
 ** Description: Places node with given value onto end of linked list
 ** Parameters:  Head pointer and value
 ** Pre-Conditions: Non NULL head
 ** Post-Conditions: Returns head pointer
 *********************************************************************/
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

/********************************************************************* 
 ** Function: Clear
 ** Description: Empties linked list, de-allocing memory
 ** Parameters:  Head pointer
 ** Pre-Conditions: Head not null
 ** Post-Conditions: Returns head pointer
 *********************************************************************/
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

/********************************************************************* 
 ** Function: Remove_node
 ** Description: Removes a node at a particular index
 ** Parameters: Head pointer and index
 ** Pre-Conditions: Index must be within range of linked list
 ** Post-Conditions: Returns head
 *********************************************************************/
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


/********************************************************************* 
 ** Function: swap
 ** Description: Swaps two nodes
 ** Parameters:  Two nodes to be switches
 ** Pre-Conditions: Nodes must be non NULL
 ** Post-Conditions: Returns pointer to preceding node
 *********************************************************************/
struct node *swap( struct node *a, struct node *b )
{
    a->next = b->next;
    b->next = a;
    return b;
}

/********************************************************************* 
 ** Function: Sort_ascending
 ** Description: Sorts linked list in ascending order
 ** Parameters:  Head pointer
 ** Pre-Conditions: Non-null head pointer
 ** Post-Conditions: Returns last node
 *********************************************************************/
struct node *sort_ascending(struct node *head)
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

/********************************************************************* 
 ** Function: Sort_descending
 ** Description: Sorts list in descending order
 ** Parameters:  Head pointer
 ** Pre-Conditions: Head shouldn't be NULL
 ** Post-Conditions: Returns last pointer 
 *********************************************************************/
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

/********************************************************************* 
 ** Function: Insert_middle
 ** Description: Inserts value at specific index of linked list
 ** Parameters:  Head, index, and the value
 ** Pre-Conditions: Non-null value and valid index
 ** Post-Conditions: Returns head
 *********************************************************************/
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


// int main() {
// 	struct node* head =  NULL;

// 	head->val;


// 	head = append(head, 4);
// 	// printf("VALLL%d\n ", head->val);
// 	// return 0;
// 	head = push(head, 5);
// 	head = append(head, 2);
// 	head = append(head, 3);
// 	head = push(head, 6);
// 	head = append(head, 8);
// 	head = append(head, 7);
// 	head = append(head, 89);
// 	head = append(head, 10);
// 	head = append(head, 9);

// 	print(head, 100);
// 	// head->next = swap(head->next);
// 	head = sort_ascending(head);
// 	// head = sort_descending(head);
// 	print(head, 100);
// 	// printf("Length %d\n", length(head));
// 	// print(head, 5);
// 	// // // head = clear(head);
// 	// head = remove_node(head, 2);
// 	// putchar('\n');



// 	// head = insert_middle(head, 3, 8);

// 	// printf("Length %d\n", length(head));

// 	// print(head, 5);

// 	// head = insert_middle(head, 4, 8);

// 	// print(head, 5);
// 	// printf("Length %d\n", length(head));
// 	// head = remove_node(head, 2);
// 	// print(head, 5);
// 	// printf("Length %d\n", length(head));
// 	// putchar('\n');

// 	clear(head);
// 	// print(head, 5);
// 	return 0;
// }