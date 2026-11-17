#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int x) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *first = NULL;
struct TreeNode *second = NULL;
struct TreeNode *middle = NULL;
struct TreeNode *prev = NULL;

void inorder(struct TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);

    if (prev && prev->data > root->data) {
        if (!first) {
            first = prev;
            middle = root;
        } else {
            second = root;
        }
    }

    prev = root;

    inorder(root->right);
}

void recoverTree(struct TreeNode* root) {
    inorder(root);

    if (first && second) {
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
    }
    else if (first && middle) {
        int temp = first->data;
        first->data = middle->data;
        middle->data = temp;
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (!root)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode* root = createNode(3);

    root->left = createNode(1);
    root->right = createNode(4);
    root->right->left = createNode(2);

    recoverTree(root);

    printf("Inorder traversal of recovered BST: ");

    inorderTraversal(root);

    printf("\n");

    return 0;
}