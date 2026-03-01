#include <stdio.h>
#include <stdlib.h>

/* ---------- Node Definition ---------- */
struct node_struct {
    int data;
    struct node_struct* left;
    struct node_struct* right;
};
typedef struct node_struct NODE;

/* ---------- Create Node ---------- */
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* ---------- Build Tree from Array (Level Order) ---------- */
NODE* buildTree(int arr[], int i, int size) {
    if (i >= size || arr[i] == -1)
        return NULL;

    NODE* root = createNode(arr[i]);
    root->left = buildTree(arr, 2*i + 1, size);
    root->right = buildTree(arr, 2*i + 2, size);

    return root;
}

/* ---------- DFS Traversals ---------- */

// Preorder: Root → Left → Right
void preorder(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder: Left → Root → Right
void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder: Left → Right → Root
void postorder(NODE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* ---------- BFS Traversal (Level Order) ---------- */
void levelOrder(NODE* root) {
    if (root == NULL) return;

    NODE* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        NODE* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
}

/* ---------- Free Tree ---------- */
void freeTree(NODE* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* ---------- Main ---------- */
int main() {

    /*
            1
          /   \
         2     3
              / \
             4   5
    */

    int arr[] = {1, 2, 3, -1, -1, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    NODE* root = buildTree(arr, 0, size);

    printf("Preorder   : ");
    preorder(root);
    printf("\n");

    printf("Inorder    : ");
    inorder(root);
    printf("\n");

    printf("Postorder  : ");
    postorder(root);
    printf("\n");

    printf("Level Order: ");
    levelOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
