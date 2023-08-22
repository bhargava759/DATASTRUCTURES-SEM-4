#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int key) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *insert(struct TreeNode *root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

struct TreeNode *search(struct TreeNode *root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct TreeNode *minValueNode(struct TreeNode *node) {
    struct TreeNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct TreeNode *maxValueNode(struct TreeNode *node) {
    struct TreeNode *current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
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

    int searchKey;
    printf("Enter the element to search for: ");
    scanf("%d", &searchKey);

    struct TreeNode *foundNode = search(root, searchKey);
    if (foundNode)
        printf("Element %d found in the tree.\n", searchKey);
    else
        printf("Element %d not found in the tree.\n", searchKey);

    struct TreeNode *minNode = minValueNode(root);
    printf("Minimum element in the tree: %d\n", minNode->key);

    struct TreeNode *maxNode = maxValueNode(root);
    printf("Maximum element in the tree: %d\n", maxNode->key);

    return 0;
}

