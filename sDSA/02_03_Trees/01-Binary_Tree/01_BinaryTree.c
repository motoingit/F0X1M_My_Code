#include <stdio.h>
#include <stdlib.h>

struct node_struct{
    struct node_struct* left;
    int data;
    struct node_struct* right;
};
typedef struct node_struct NODE;

NODE* createNode(int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void freeTree(NODE* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}



NODE* buildTree(int arr[], int i, int size){
    if(i >= size || arr[i] == -1){
        return NULL;
    }

    NODE* root = createNode(arr[i]);
    root->left = buildTree(arr, 2*i+1, size);
    root->right = buildTree(arr, 2*i+2, size);

    return root;
}

void printTree(NODE* root){
    if(root != NULL){
        printf("%d ",root->data);
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
printf("\n");
/*
        1
      /   \
     2     3
          / \
         4   5
*/
    int arr[] = {1,2,3,-1,-1,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    NODE* root = buildTree(arr, 0, size);
    printTree(root);

    freeTree(root);
printf("\n");
return 0;}