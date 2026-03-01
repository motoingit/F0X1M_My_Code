#include <stdio.h>
#include <stdlib.h>

struct NODE_STRUCTURE_AVL{
    int data;
    int height;
    struct NODE_STRUCTURE_AVL* right;
    struct NODE_STRUCTURE_AVL* left;
};
typedef struct NODE_STRUCTURE_AVL NODE;

NODE* createNode(int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->height = 1;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

int getHeight(NODE* root){
    if(root == NULL){
        return 0;
    }else{
        return root->height;
    }
}

int maxOf(int left, int right){
    if(left >= right){
        return left;
    }else{
        return right;
    }
}

int getBalance(NODE* root){
    return getHeight(root->left) - getHeight(root->right);
}

//todo: DO rotation affects height ?         YES !

//rightRotation
NODE* rightRotation(NODE* root){
    NODE* child = root->left;
    NODE* childRight = child->right;

    child->right = root;
    root->left = childRight;

    //update height of root andf cild
    root->height = 1+maxOf(getHeight(root->left), getHeight(root->right));
    child->height = 1+maxOf(getHeight(child->left), getHeight(child->right));

    return child;
}

//leftRotation
NODE* leftRotation(NODE* root){
    NODE* child = root->right;
    NODE* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    //update height of root andf cild
    root->height = 1+maxOf(getHeight(root->left), getHeight(root->right));
    child->height = 1+maxOf(getHeight(child->left), getHeight(child->right));

    return child;
}

NODE* insertAVL(NODE* root, int data) {

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertAVL(root->left, data);
    else if (data > root->data)
        root->right = insertAVL(root->right, data);
    else{
        printf("Dont again !\n");
        return root; // duplicate ignored safely
    }

    // Update height
    root->height = 1 + maxOf(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && data < root->left->data)
        return rightRotation(root);

    // RR Case
    if (balance < -1 && data > root->right->data)
        return leftRotation(root);

    // LR Case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RL Case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

//! Do NOT try to delete inside findMax()
NODE* findMax(NODE* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

//todo:      yaha pe ulta logic hai unbalancing ka
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
        else if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else{
            NODE* pred = findMax(root->left); //! can we delete when we are finding max
            root->data = pred->data;
            root->left = deleteBST(root->left, pred->data);
        }
    }


    //! why this
    if (root == NULL)
    return NULL;

    root->height = 1 + maxOf(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LX Case
    if (balance > 1){
        if(getBalance(root->left) >= 0) // ll 
            return rightRotation(root);
        else{                  // lr
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }

    // RX Case
    if (balance < -1){ //rr
        if(getBalance(root->right) <= 0) {
            return leftRotation(root);
        }else{ //rl
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    return root;
}


void printTree(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printTree(root->left);
        printTree(root->right);
    }
}

void freeTree(NODE* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
printf("\n");
    NODE* root = NULL;
    int arr[15] = {30, 20, 40, 10, 25, 35, 50, 5, 15, 27, 45, 60, 1, 8, 28};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size; i++){
        root = insertAVL(root, arr[i]);
    }

    for(int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        root = deleteBST(root, num);

        printTree(root);
        printf("\n");
    }

    printf("Preorder Traversal After Deletion : ");
    printTree(root);

    freeTree(root);
printf("\n");
return 0;}