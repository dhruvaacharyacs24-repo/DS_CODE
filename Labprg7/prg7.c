#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_end() {
    int x;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        printf("Node inserted as first node\n");
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    printf("Node inserted at end\n");
}

void insert_left() {
    int key, x;
    struct node *newnode, *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter value to insert left of: ");
    scanf("%d", &key);
    printf("Enter new data: ");
    scanf("%d", &x);
    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = temp;
    newnode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;
    temp->prev = newnode;
    printf("Node inserted to the left\n");
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly linked list:\n");
    temp = head;
    while (temp->next!= NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert at End\n2.Insert Left of a Node\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_end();
                break;
            case 2:
                insert_left();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

