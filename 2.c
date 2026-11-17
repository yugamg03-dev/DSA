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

int isLeaf(struct TreeNode* root) {
    return !root->left && !root->right;
}

int minDepth(struct TreeNode* root) {
    if (!root)
        return 0;

    if (isLeaf(root))
        return 1;

    int leftDepth = 100000;
    int rightDepth = 100000;

    if (root->left)
        leftDepth = minDepth(root->left);

    if (root->right)
        rightDepth = minDepth(root->right);

    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}

int main() {
    struct TreeNode* root = createNode(1);

    root->right = createNode(3);
    root->right->right = createNode(5);
    root->right->right->right = createNode(7);

    printf("%d\n", minDepth(root));

    return 0;
}