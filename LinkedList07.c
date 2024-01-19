#include<stdio.h>
typedef struct nodeStruct{
    int data;
    struct nodeStruct *next;
}Node;
Node *createNode(int data) {
    Node *newNode;
    newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(Node *list) {
    printf("Linked list contains: ");
    while (list->next != NULL) {
        printf("%d ", list->next->data);
        list = list->next;
    }
    printf("\n");
}
void insertFirst(Node *list, int data) {
    Node *temp;
    temp = list->next;
    list->next = createNode(data);
    list->next->next = temp;
}
void insertLast(Node *list, int data) {
    while(list->next != NULL)
        list = list->next;
    list->next = createNode(data);
}
int main() {
    Node *head;
    head = createNode(0);
    int data;
    int choice;
    do {
        printList(head);
        printf("Enter your choice from 0 to 6\n");
        printf("0. Exit.\n");
        printf("1. Insert First\n");
        printf("2. Insert Any Position\n");
        printf("3. Insert Last\n");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            printf("The program is now exit\n");
            break;
        case 1:
            printf("Enter any number to insert: ");
            scanf("%d", &data);
            insertFirst(head, data);
            break;
        case 3:
            printf("Enter any number to insert: ");
            scanf("%d", &data);
            insertLast(head, data);
            break;
        }
    }while (choice != 0);
    return 0;
}
