#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, i, x;
    struct node *temp, *newnode;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &x);
        newnode->data = x;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void insert_first() {
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void insert_end() {
    int x;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void insert_pos() {
    int x, pos, i;
    struct node *newnode, *temp;
    scanf("%d %d", &x, &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    newnode->next = temp->next;
    temp->next = newnode;
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Create\n2.Insert First\n3.Insert End\n4.Insert Position\n5.Display\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert_first();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_pos();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
        }
    }
}
