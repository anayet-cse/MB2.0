#include<stdio.h>
#include<malloc.h>
typedef struct nodeStruct {
    int data;
    struct nodeStruct *left, *right;
}Node;
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(Node *root) {
    if (NULL == root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(Node *root) {
    if (NULL == root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root) {
    if (NULL == root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
Node *insert(Node *root, int data) {
    if (NULL == root)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
Node *del(Node *root, int data) {
    if (NULL == root)
        return root;
    if (data < root->data)
        root->left = del(root->left, data);
    else if (data > root->data)
        root->right = del(root->right, data);
    else if (NULL == root->left && NULL == root->right) {
        free(root);
        return NULL;
    }
    else if (NULL == root->left) {
        Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (NULL == root->right) {
        Node *temp = root->left;
        free(root);
        return temp;
    }
    else {
        Node *leftMost = root->right;
        while (leftMost->left !=NULL)
            leftMost = leftMost->left;
        root->data = leftMost->data;
        root->right = del(root->right, leftMost->data);
    }
    return root;
}
int search(Node *root, int data) {
    if (NULL == root)
        return 0;
    if (data < root->data)
        return search(root->left, data);
    if (data > root->data)
        return search(root->right, data);
    return 1;
}
int main() {
    Node *root = NULL;
    int data, choice;
    do {
        printf("Preorder: ");
        preorder(root);
        printf("\nInorder: ");
        inorder(root);
        printf("\nPostorder: ");
        postorder(root);
        printf("\nEnter your choice from 0 to 3.\n");
        printf("0. Exit\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            printf("The program is now exit.\n");
            printf("Press any key to continue...\n");
            break;
        case 1:
            printf("Enter any number to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter any number to delete: ");
            scanf("%d", &data);
            root = del(root, data);
            break;
        case 3:
            printf("Enter any number to search: ");
            scanf("%d", &data);
            if (1 == search(root, data))
                printf("%d found\n", data);
            else
                printf("%d not found\n", data);
            break;
        }
    }while (choice != 0);
    return 0;
}
