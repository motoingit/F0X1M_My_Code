#include <stdio.h>
#include <stdlib.h>

/* =========================
   BST NODE DEFINITION
   ========================= */
struct BST_STRUCTURE {
    struct BST_STRUCTURE* left;
    int data;
    struct BST_STRUCTURE* right;
};
typedef struct BST_STRUCTURE NODE;

/* =========================
   CREATE NODE
   ========================= */
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* =========================
   INSERT INTO BST
   ========================= */
NODE* insertBST(NODE* root, int data) {

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    else
        printf("Duplicate value ignored: %d\n", data);

    return root;
}

/* =========================
   FIND MAX (INORDER PREDECESSOR)
   ========================= */
NODE* findMax(NODE* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

/* =========================
   DELETE FROM BST
   ========================= */
NODE* deleteBST(NODE* root, int targetData) {

    if (root == NULL)
        return NULL;

    if (targetData < root->data) {
        root->left = deleteBST(root->left, targetData);
    }else if (targetData > root->data) {
        root->right = deleteBST(root->right, targetData);
    }else {  // Node found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        }
        
        if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        NODE* pred = findMax(root->left);
        root->data = pred->data;
        root->left = deleteBST(root->left, pred->data);
    }

    return root;
}

/* =========================
   BUILD BST FROM ARRAY
   ========================= */
NODE* buildBST(int arr[], int size) {
    NODE* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertBST(root, arr[i]);
    }
    return root;
}

/* =========================
   FREE BST
   ========================= */
void freeTree(NODE* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* =========================
   PREORDER TRAVERSAL (NLR)
   ========================= */
void printTree(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printTree(root->left);
        printTree(root->right);
    }
}

/* =========================
   MAIN
   ========================= */
int main() {

    int arr[] = {11, 2, 13, 6, 4, 90, 89, 44, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    NODE* root = buildBST(arr, size);

    printf("Preorder Traversal: ");
    printTree(root);

    printf("\nDeleting 13...\n");
    root = deleteBST(root, 13);

    printf("Preorder Traversal After Deletion: ");
    printTree(root);

    freeTree(root);
    return 0;
}
