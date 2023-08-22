#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode *node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(struct TreeNode *node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

struct TreeNode *newNode(int key) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct TreeNode *rightRotate(struct TreeNode *y) {
    struct TreeNode *x = y->left;
    struct TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct TreeNode *leftRotate(struct TreeNode *x) {
    struct TreeNode *y = x->right;
    struct TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct TreeNode *insert(struct TreeNode *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode *root = NULL;

    int num_elements;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements to insert:\n", num_elements);
    for (int i = 0; i < num_elements; ++i) {
        int element;
        scanf("%d", &element);
        root = insert(root, element);
    }

    printf("Inorder traversal of AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

