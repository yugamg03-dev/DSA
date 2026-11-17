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

int symmetry(struct TreeNode* left, struct TreeNode* right) {
    if (!left && !right)
        return 1;

    if (!left || !right)
        return 0;

    if (left->val != right->val)
        return 0;

    return symmetry(left->left, right->right) &&
           symmetry(left->right, right->left);
}

int isSymmetric(struct TreeNode* root) {
    if (!root)
        return 1;

    return symmetry(root->left, root->right);
}

int main() {
    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(2);

    root->left->left = createNode(3);
    root->left->right = createNode(4);

    root->right->left = createNode(4);
    root->right->right = createNode(3);

    printf("%d\n", isSymmetric(root));

    return 0;
}