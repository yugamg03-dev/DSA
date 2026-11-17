#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void serialize(struct TreeNode* root, char result[]) {
    struct TreeNode* q[1000];
    int front = 0, rear = 0;

    result[0] = '\0';

    q[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = q[front++];

        char temp[30];

        if (!node) {
            strcat(result, "#,");
            continue;
        }

        sprintf(temp, "%d,", node->val);
        strcat(result, temp);

        q[rear++] = node->left;
        q[rear++] = node->right;
    }
}

struct TreeNode* deserialize(char data[]) {
    if (data[0] == '\0' || data[0] == '#')
        return NULL;

    char copy[10000];
    strcpy(copy, data);

    char* token = strtok(copy, ",");

    struct TreeNode* root = createNode(atoi(token));

    struct TreeNode* q[1000];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = q[front++];

        token = strtok(NULL, ",");

        if (!token)
            break;

        if (strcmp(token, "#") != 0) {
            node->left = createNode(atoi(token));
            q[rear++] = node->left;
        }

        token = strtok(NULL, ",");

        if (!token)
            break;

        if (strcmp(token, "#") != 0) {
            node->right = createNode(atoi(token));
            q[rear++] = node->right;
        }
    }

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (!root)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->right->left = createNode(4);
    root->right->right = createNode(5);

    char serializedTree[10000];

    serialize(root, serializedTree);

    printf("Serialized tree: %s\n", serializedTree);

    struct TreeNode* newRoot = deserialize(serializedTree);

    printf("Deserialized tree (inorder traversal): ");

    inorderTraversal(newRoot);

    printf("\n");

    return 0;
}