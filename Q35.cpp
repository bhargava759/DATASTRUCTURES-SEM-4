#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int data) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(struct TreeNode *root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

struct TreeNode *insert(struct TreeNode *root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void kthSmallestUtil(struct TreeNode *root, int k, int *count, int *result) {
    if (root == NULL || *count >= k)
        return;

    kthSmallestUtil(root->left, k, count, result);
    (*count)++;

    if (*count == k) {
        *result = root->data;
        return;
    }

    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(struct TreeNode *root, int k) {
    int count = 0;
    int result = -1;
    kthSmallestUtil(root, k, &count, &result);
    return result;
}

int main() {
    struct TreeNode *root = NULL;

    int num_nodes;
    printf("Enter the number of nodes in the Binary Search Tree: ");
    scanf("%d", &num_nodes);

    printf("Enter the values of the %d nodes:\n", num_nodes);
    for (int i = 0; i < num_nodes; ++i) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    int k;
    printf("Enter the value of k to find the kth smallest element: ");
    scanf("%d", &k);

    int kthSmallestValue = kthSmallest(root, k);
    if (kthSmallestValue != -1)
        printf("The %dth smallest element is: %d\n", k, kthSmallestValue);
    else
        printf("Invalid value of k.\n");

    return 0;
}

