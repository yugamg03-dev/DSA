
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

void deleteTailOfDoublyLL(struct Node** head) {
    if (*head == NULL)
        return;

    if ((*head)->next == NULL) {
        struct Node* deletedNode = *head;
        *head = NULL;
        free(deletedNode);
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    struct Node* prev = temp->prev;
    prev->next = NULL;
    temp->prev = NULL;

    free(temp);
}

void deleteInMiddleOfDoublyLL(struct Node** head, int posi) {
    if (*head == NULL || posi < 1) {
        printf("Position doesn't exist\n");
        return;
    }

    if (posi == 1) {
        struct Node* deletedNode = *head;
        *head = (*head)->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        free(deletedNode);
        return;
    }

    int cnt = 1;
    struct Node* temp = *head;

    while (temp && cnt < posi) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position doesn't exist\n");
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
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
    insertAtTheEndOfDoublyLL(&head, 50);

    printDoublyLL(head);

    deleteTailOfDoublyLL(&head);
    printDoublyLL(head);

    deleteInMiddleOfDoublyLL(&head, 2);
    printDoublyLL(head);

    return 0;
}
