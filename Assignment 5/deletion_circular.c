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

void deleteAtBeginning() {
    struct Node *temp, *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    last = temp;
    temp = head;

    head = head->next;
    last->next = head;

    free(temp);
}

void deleteAtEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

    free(temp);
}

void deleteAtPosition(int position) {
    struct Node *temp, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == head) {
            printf("Invalid position\n");
            return;
        }
    }

    prev->next = temp->next;

    free(temp);
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

    printf("\nWhere do you want to delete the element?\n");
    printf("1. Beginning\n");
    printf("2. In between\n");
    printf("3. End\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteAtBeginning();
            break;

        case 2:
            printf("Enter the position: ");
            scanf("%d", &position);
            deleteAtPosition(position);
            break;

        case 3:
            deleteAtEnd();
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nCircular Linked List after deletion: ");
    display();

    return 0;
}