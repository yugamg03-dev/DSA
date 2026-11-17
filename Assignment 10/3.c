#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* createNode(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
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
            curr->left->parent = curr;
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            curr->right->parent = curr;
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

struct Node* search(struct Node* root, int target)
{
    if(root == NULL)
        return NULL;

    if(root->data == target)
        return root;

    struct Node* temp = search(root->left, target);

    if(temp != NULL)
        return temp;

    return search(root->right, target);
}

void distanceK(struct Node* root, int target, int k)
{
    struct Node* targetNode = search(root, target);

    if(targetNode == NULL)
        return;

    struct Node* queue[100005];
    struct Node* visited[100005];

    int front = 0, rear = 0, v = 0;

    queue[rear++] = targetNode;
    visited[v++] = targetNode;

    int distance = 0;

    while(front < rear && distance < k)
    {
        int size = rear - front;

        for(int i = 0; i < size; i++)
        {
            struct Node* curr = queue[front++];

            struct Node* neighbours[3];

            neighbours[0] = curr->left;
            neighbours[1] = curr->right;
            neighbours[2] = curr->parent;

            for(int j = 0; j < 3; j++)
            {
                struct Node* next = neighbours[j];

                if(next == NULL)
                    continue;

                int found = 0;

                for(int x = 0; x < v; x++)
                {
                    if(visited[x] == next)
                    {
                        found = 1;
                        break;
                    }
                }

                if(!found)
                {
                    visited[v++] = next;
                    queue[rear++] = next;
                }
            }
        }

        distance++;
    }

    if(distance == k)
    {
        for(int i = front; i < rear; i++)
            printf("%d ", queue[i]->data);
    }
}

int main()
{
    int n, target, k;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    scanf("%d", &target);
    scanf("%d", &k);

    distanceK(root, target, k);

    return 0;
}