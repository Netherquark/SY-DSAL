/*
Write a C program to create linked list of PAN numbers of 4 employees then nistert the 5th employees PAN numbers number at the beginning of the list.
Steps:
1. Node structure for the linked list
2. Function to insert a new node at the beginning of the linked list
    a. Allocate the memory for new node
    b. Copy the PAN number into the new node
    c. Make the new node point at the current first node
    d. Update the header pointer to point at the new node
3. Function to print the linked list
4. Main Function
    a. Create the linked list list with 4 employee PAN numbers
    b. insert the 5th employee PAN number
    c. Free memory occupied by the linked list
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    char pan[11];  // Assuming PAN is a 10-character string plus the null terminator
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, char* new_pan) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Copy the PAN number into the new node
    strcpy(new_node->pan, new_pan);

    // Make the new node point to the current first node
    new_node->next = *head_ref;

    // Update the header pointer to point at the new node
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%s -> ", node->pan);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free memory occupied by the linked list
void freeList(struct Node* head) {
    struct Node* tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    // Creating a linked list with 4 employee PAN numbers
    struct Node* head = NULL;

    // PAN numbers for 4 employees
    insertAtBeginning(&head, "ABCDE1234F");
    insertAtBeginning(&head, "FGHIJ5678K");
    insertAtBeginning(&head, "KLMNO9123P");
    insertAtBeginning(&head, "QRSTU4567V");

    // Print the list before inserting the 5th employee's PAN number
    printf("Linked list before inserting the 5th PAN number:\n");
    printList(head);

    // Insert the 5th employee's PAN number at the beginning
    insertAtBeginning(&head, "VWXYZ8901Q");

    // Print the list after inserting the 5th employee's PAN number
    printf("\nLinked list after inserting the 5th PAN number at the beginning:\n");
    printList(head);

    // Free the memory occupied by the linked list
    freeList(head);

    return 0;
}
