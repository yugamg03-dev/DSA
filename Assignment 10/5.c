#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
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

struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
    {
        if(root->lthread == 0)
            root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        if(root->rthread == 0)
            root->right = insert(root->right, value);
    }

    return root;
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
    if(ptr == NULL)
        return NULL;

    if(ptr->rthread == 1)
        return ptr->right;

    ptr = ptr->right;

    while(ptr != NULL && ptr->lthread == 0)
        ptr = ptr->left;

    return ptr;
}

struct Node* predecessor(struct Node* ptr)
{
    if(ptr == NULL)
        return NULL;

    if(ptr->lthread == 1)
        return ptr->left;

    ptr = ptr->left;

    while(ptr != NULL && ptr->rthread == 0)
        ptr = ptr->right;

    return ptr;
}

struct Node* search(struct Node* root, int key)
{
    while(root != NULL)
    {
        if(key == root->data)
            return root;

        if(key < root->data)
        {
            if(root->lthread == 1)
                return NULL;

            root = root->left;
        }
        else
        {
            if(root->rthread == 1)
                return NULL;

            root = root->right;
        }
    }

    return NULL;
}

struct Node* lowerBound(struct Node* root, int L)
{
    struct Node* ans = NULL;

    while(root != NULL)
    {
        if(root->data >= L)
        {
            ans = root;

            if(root->lthread == 1)
                break;

            root = root->left;
        }
        else
        {
            if(root->rthread == 1)
                break;

            root = root->right;
        }
    }

    return ans;
}

void rangeQuery(struct Node* root, int L, int R)
{
    struct Node* curr = lowerBound(root, L);

    int first = 1;

    printf("RANGE = [");

    while(curr != NULL && curr->data <= R)
    {
        if(!first)
            printf(", ");

        printf("%d", curr->data);

        first = 0;

        curr = successor(curr);
    }

    printf("]\n");
}

struct Node* kthSmallest(struct Node* root, int k)
{
    if(k < 1)
        return NULL;

    struct Node* curr = leftMost(root);

    int count = 1;

    while(curr != NULL && count < k)
    {
        curr = successor(curr);
        count++;
    }

    return curr;
}

int main()
{
    struct Node* root = NULL;

    int n, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    struct Node* prev = NULL;

    convert(root, &prev);

    if(prev != NULL)
    {
        prev->right = NULL;
        prev->rthread = 1;
    }

    int q;
    scanf("%d", &q);

    while(q--)
    {
        char command[20];

        scanf("%s", command);

        if(command[0] == 'N')
        {
            scanf("%d", &value);

            struct Node* curr = search(root, value);
            struct Node* ans = successor(curr);

            if(ans == NULL)
                printf("NEXT = NULL\n");
            else
                printf("NEXT = %d\n", ans->data);
        }

        else if(command[0] == 'P')
        {
            scanf("%d", &value);

            struct Node* curr = search(root, value);
            struct Node* ans = predecessor(curr);

            if(ans == NULL)
                printf("PREV = NULL\n");
            else
                printf("PREV = %d\n", ans->data);
        }

        else if(command[0] == 'R')
        {
            int L, R;

            scanf("%d %d", &L, &R);

            rangeQuery(root, L, R);
        }

        else if(command[0] == 'K')
        {
            int k;

            scanf("%d", &k);

            struct Node* ans = kthSmallest(root, k);

            if(ans == NULL)
                printf("KTH = NULL\n");
            else
                printf("KTH = %d\n", ans->data);
        }
    }

    return 0;
}