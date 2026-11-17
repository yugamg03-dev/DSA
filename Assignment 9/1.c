#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int x) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct QueueNode {
    struct TreeNode* node;
    int hd;
};

void topView(struct TreeNode* root) {
    if (!root)
        return;

    struct QueueNode q[1000];
    int map[2001];
    int visited[2001] = {0};

    int front = 0, rear = 0;
    int minHD = 1000, maxHD = 1000;

    q[rear].node = root;
    q[rear++].hd = 0;

    while (front < rear) {
        struct TreeNode* curr = q[front].node;
        int hd = q[front++].hd;

        int index = hd + 1000;

        if (!visited[index]) {
            map[index] = curr->val;
            visited[index] = 1;
        }

        if (hd < minHD)
            minHD = hd;

        if (hd > maxHD)
            maxHD = hd;

        if (curr->left) {
            q[rear].node = curr->left;
            q[rear++].hd = hd - 1;
        }

        if (curr->right) {
            q[rear].node = curr->right;
            q[rear++].hd = hd + 1;
        }
    }

    for (int i = minHD; i <= maxHD; i++) {
        if (visited[i + 1000])
            printf("%d ", map[i + 1000]);
    }

    printf("\n");
}

int main() {
    struct TreeNode* root = createNode(1);

    root->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    topView(root);

    return 0;
}