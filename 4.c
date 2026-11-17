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

void insert(struct TreeNode** root, int x) {
    if (*root == NULL) {
        *root = createNode(x);
        return;
    }

    if ((*root)->val > x)
        insert(&(*root)->left, x);
    else
        insert(&(*root)->right, x);
}

void inorder(struct TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int nums[] = {5, 3, 7, 2, 4, 6, 8};
    int n = 7;

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++)
        insert(&root, nums[i]);

    inorder(root);

    printf("\n");

    return 0;
}