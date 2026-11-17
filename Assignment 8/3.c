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

void inorder(struct TreeNode* root, int ans[], int* index) {
    if (!root)
        return;

    inorder(root->left, ans, index);

    ans[(*index)++] = root->val;

    inorder(root->right, ans, index);
}

int main() {
    struct TreeNode* root = createNode(5);

    root->left = createNode(3);
    root->right = createNode(7);

    root->left->left = createNode(2);
    root->left->right = createNode(4);

    root->right->left = createNode(6);
    root->right->right = createNode(8);

    int ans[100], index = 0;
    int k = 3;

    inorder(root, ans, &index);

    if (k > 0 && k <= index) {
        printf("Kth smallest: %d\n", ans[k - 1]);
        printf("Kth largest: %d\n", ans[index - k]);
    }

    return 0;
}