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

void preorderTraversal(struct TreeNode *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode *root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
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

int main() {
    struct TreeNode *root = NULL;

    int num_nodes;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &num_nodes);

    printf("Enter the values of the %d nodes:\n", num_nodes);
    for (int i = 0; i < num_nodes; ++i) {
        int value;
        scanf("%d", &value);
        if (root == NULL) {
            root = newNode(value);
        } else {
            struct TreeNode *current = root;
            while (1) {
                if (value < current->data) {
                    if (current->left == NULL) {
                        current->left = newNode(value);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == NULL) {
                        current->right = newNode(value);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
	
