#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node* root, int arr[], int* index)
{
    if(root == NULL)
        return;

    inorder(root->left, arr, index);

    arr[(*index)++] = root->data;

    inorder(root->right, arr, index);
}

int kthSmallest(int arr[], int n, int k)
{
    if(k < 1 || k > n)
        return -1;

    return arr[k - 1];
}

int main()
{
    struct Node* root = NULL;

    int n, value, q, k;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    int arr[n];
    int index = 0;

    inorder(root, arr, &index);

    scanf("%d", &q);

    for(int i = 0; i < q; i++)
    {
        scanf("%d", &k);

        int ans = kthSmallest(arr, n, k);

        if(ans == -1)
            printf("Invalid K\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
