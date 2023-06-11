#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Definition of a stack node
struct StackNode {
    struct TreeNode *node;
    struct StackNode *next;
};

// Function to create a new stack node
struct StackNode* createStackNode(struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct StackNode** topRef, struct TreeNode* node) {
    struct StackNode* stackNode = createStackNode(node);
    stackNode->next = *topRef;
    *topRef = stackNode;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode** topRef) {
    struct TreeNode* node;
    struct StackNode* temp;

    temp = *topRef;
    node = temp->node;
    *topRef = temp->next;
    free(temp);

    return node;
}

// Function to perform a depth first traversal of a tree
void dfs(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct StackNode *stack = NULL;
    push(&stack, root);

    while (stack != NULL) {
        struct TreeNode* node = pop(&stack);
        printf("%d ", node->val);

        if (node->right != NULL) {
            push(&stack, node->right);
        }

        if (node->left != NULL) {
            push(&stack, node->left);
        }
    }
}

// Test program
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 4;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 5;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("Depth First Traversal: ");
    dfs(root);

    return 0;
}
