#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, value, choice, position;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Original List:\n");
    display(head);

    printf("\nWhere do you want to insert?\n");
    printf("1. Start\n");
    printf("2. In between\n");
    printf("3. End\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter element: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (choice == 1) {
        newNode->next = head;
        head = newNode;
    }
    else if (choice == 2) {
        printf("Enter position: ");
        scanf("%d", &position);

        temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    else if (choice == 3) {
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
    else {
        printf("Invalid choice\n");
        free(newNode);
    }

    printf("Updated List:\n");
    display(head);

    return 0;
}