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

int values[1000];
int count = 0;

void inorder(struct TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);

    values[count++] = root->val;

    inorder(root->right);
}

int main() {
    struct TreeNode* root = createNode(4);

    root->left = createNode(2);
    root->right = createNode(5);

    root->left->left = createNode(1);
    root->left->right = createNode(3);

    int k = 3, x = 3;

    inorder(root);

    int dist[1000];

    for (int i = 0; i < count; i++) {
        dist[i] = abs(values[i] - x);
    }

    int selected[1000] = {0};

    printf("The %d smallest values closest to %d are: ", k, x);

    for (int i = 0; i < k && i < count; i++) {
        int best = -1;

        for (int j = 0; j < count; j++) {
            if (!selected[j]) {
                if (best == -1 ||
                    dist[j] < dist[best] ||
                    (dist[j] == dist[best] && values[j] < values[best])) {
                    best = j;
                }
            }
        }

        selected[best] = 1;
        printf("%d ", values[best]);
    }

    printf("\n");

    return 0;
}