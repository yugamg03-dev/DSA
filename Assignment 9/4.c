#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct Info {
    int isBST;
    int min;
    int max;
    int sum;
};

int maxSum = INT_MIN;

struct Info findMaxBSTSum(struct TreeNode* root) {
    struct Info info;

    if (!root) {
        info.isBST = 1;
        info.min = INT_MAX;
        info.max = INT_MIN;
        info.sum = 0;
        return info;
    }

    struct Info left = findMaxBSTSum(root->left);
    struct Info right = findMaxBSTSum(root->right);

    if (left.isBST && right.isBST &&
        left.max < root->val &&
        root->val < right.min) {

        info.isBST = 1;
        info.sum = left.sum + right.sum + root->val;

        info.min = root->val < left.min ? root->val : left.min;
        info.max = root->val > right.max ? root->val : right.max;

        if (info.sum > maxSum)
            maxSum = info.sum;

        return info;
    }

    info.isBST = 0;
    info.sum = 0;
    info.min = INT_MIN;
    info.max = INT_MAX;

    return info;
}

int main() {
    struct TreeNode* node3 = createNode(3);
    struct TreeNode* node6 = createNode(6);
    struct TreeNode* node7 = createNode(7);
    struct TreeNode* node9 = createNode(9);
    struct TreeNode* node4 = createNode(4);
    struct TreeNode* node8 = createNode(8);

    struct TreeNode* root = createNode(5);

    node4->left = node3;
    node4->right = node6;

    node8->left = node7;
    node8->right = node9;

    root->left = node4;
    root->right = node8;

    findMaxBSTSum(root);

    printf("Maximum BST subtree sum = %d\n", maxSum);

    return 0;
}