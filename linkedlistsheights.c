#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteMiddle(struct Node** head, int pos) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("\nList is too small to delete from middle.\n");
        return;
    }
    
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid position.\n");
        return;
    }
    
    struct Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    printf("\nDeleted node at position %d.\n", pos);
}

void deleteBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty, no node to delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
    printf("\nDeleted node from the beginning.\n");
}

void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("\nDeleted last node, list is empty now.\n");
        return;
    }
    
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
    free(temp);
    printf("\nDeleted last node.\n");
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    int heights[10] = {160, 170, 165, 180, 175, 155, 185, 190, 175, 168};
    for (int i = 0; i < 10; i++) {
        appendNode(&head, heights[i]);
    }
    
    printf("\nInitial List:\n");
    displayList(head);
    
    deleteMiddle(&head, 5);
    displayList(head);
    
    deleteBeginning(&head);
    displayList(head);
    
    deleteEnd(&head);
    displayList(head);

    // Test Cases
    
    struct Node* testHead = NULL;
    
    printf("\nTest Case 1: Empty List\n");
    displayList(testHead);
    deleteMiddle(&testHead, 5);
    deleteBeginning(&testHead);
    deleteEnd(&testHead);

    appendNode(&testHead, 160);
    printf("\nTest Case 2: Single Node\n");
    displayList(testHead);
    deleteMiddle(&testHead, 1);
    deleteBeginning(&testHead);
    displayList(testHead);
    
    for (int i = 0; i < 10; i++) {
        appendNode(&testHead, heights[i]);
    }
    
    printf("\nTest Case 3: Multiple Nodes\n");
    displayList(testHead);
    
    deleteMiddle(&testHead, 5);
    displayList(testHead);
    
    deleteBeginning(&testHead);
    displayList(testHead);
    
    deleteEnd(&testHead);
    displayList(testHead);

    return 0;
}
