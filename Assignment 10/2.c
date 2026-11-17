#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int lthread;
    int rthread;
};

struct Node* createNode(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = 0;
    newNode->rthread = 0;

    return newNode;
}

void convert(struct Node* root, struct Node** prev)
{
    if(root == NULL)
        return;

    if(root->lthread == 0)
        convert(root->left, prev);

    if(root->left == NULL)
    {
        root->left = *prev;
        root->lthread = 1;
    }

    if(*prev != NULL && (*prev)->right == NULL)
    {
        (*prev)->right = root;
        (*prev)->rthread = 1;
    }

    *prev = root;

    if(root->rthread == 0)
        convert(root->right, prev);
}

struct Node* leftMost(struct Node* root)
{
    if(root == NULL)
        return NULL;

    while(root->lthread == 0)
        root = root->left;

    return root;
}

struct Node* successor(struct Node* ptr)
{
    if(ptr->rthread == 1)
        return ptr->right;

    ptr = ptr->right;

    while(ptr != NULL && ptr->lthread == 0)
        ptr = ptr->left;

    return ptr;
}

void inorderThreaded(struct Node* root)
{
    struct Node* current = leftMost(root);

    while(current != NULL)
    {
        printf("%d ", current->data);
        current = successor(current);
    }
}

struct Node* buildTree(int arr[], int n)
{
    if(n == 0 || arr[0] == -1)
        return NULL;

    struct Node* queue[n];

    int front = 0, rear = 0, i = 1;

    struct Node* root = createNode(arr[0]);

    queue[rear++] = root;

    while(front < rear && i < n)
    {
        struct Node* curr = queue[front++];

        if(i < n && arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int main()
{
    int n, i;

    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    struct Node* prev = NULL;

    convert(root, &prev);

    if(prev != NULL)
    {
        prev->right = NULL;
        prev->rthread = 1;
    }

    inorderThreaded(root);

    return 0;
}