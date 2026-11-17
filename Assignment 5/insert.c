#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertAtBeginning(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertAtPosition(int value, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    temp = head;

    for (i = 1; i < position - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int n, value, position, choice, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("\nCircular Linked List: ");
    display();

    printf("\nWhere do you want to insert the element?\n");
    printf("1. Beginning\n");
    printf("2. In between\n");
    printf("3. End\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the element: ");
    scanf("%d", &value);

    switch (choice) {
        case 1:
            insertAtBeginning(value);
            break;

        case 2:
            printf("Enter the position: ");
            scanf("%d", &position);
            insertAtPosition(value, position);
            break;

        case 3:
            insertAtEnd(value);
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nCircular Linked List after insertion: ");
    display();

    return 0;
}