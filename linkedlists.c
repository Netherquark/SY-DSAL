#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for string functions

typedef struct {linkedlists.c
    char name[100];
    int rollno;
    int age;
} Student;

typedef struct Node {
    Student student;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* name, int rollno, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize the student data
    strncpy(newNode->student.name, name, 100 - 1);
    newNode->student.name[100 - 1] = '\0'; // Ensure null-termination
    
    newNode->student.rollno = rollno;
    newNode->student.age = age;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, const char* name, int rollno, int age) {
    Node* newNode = createNode(name, rollno, age);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Roll Number: %d, Age: %d\n",
               temp->student.name, temp->student.rollno, temp->student.age);
        temp = temp->next;
    }
}

// Function to free the allocated memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL; // Initialize the head of the list to NULL
    int numStudents, rollno, age;
    char name[100];
    
    // Ask the user for the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    // Loop to get data for each student
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        
        printf("Name: ");
        scanf(" %[^\n]s", name); // %[^\n]s format allows to take a string with spaces

        printf("Roll Number: ");
        scanf("%d", &rollno);

        printf("Age: ");
        scanf("%d", &age);

        // Insert the student data into the list
        insertAtEnd(&head, name, rollno, age);
    }
    
    // Display the linked list
    printf("\nList of Students:\n");
    displayList(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}
