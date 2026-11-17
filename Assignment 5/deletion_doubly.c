
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtTheEndOfDoublyLL(struct Node** head, int x) {
    struct Node* newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtTheMiddleOfDoublyLL(struct Node** head, int x, int posi) {
    if (posi < 1) {
        printf("Position must be positive\n");
        return;
    }

    if (*head == NULL) {
        return;
    }

    int cnt = 1;
    struct Node* temp = *head;

    while (temp && cnt < posi - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position doesn't exist\n");
        return;
    }

    struct Node* newNode = createNode(x);
    struct Node* next = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = next;
    next->prev = newNode;
}

void printDoublyLL(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtTheEndOfDoublyLL(&head, 10);
    insertAtTheEndOfDoublyLL(&head, 20);
    insertAtTheEndOfDoublyLL(&head, 30);
    insertAtTheEndOfDoublyLL(&head, 40);

    printDoublyLL(head);

    insertAtTheEndOfDoublyLL(&head, 50);
    printDoublyLL(head);

    insertAtTheMiddleOfDoublyLL(&head, 25, 3);
    printDoublyLL(head);

    return 0;
}
