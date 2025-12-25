#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL, *rear = NULL;

void stack_push() {
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("Element pushed\n");
}

void stack_pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    top = top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

void stack_display() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    while (temp->next != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

void queue_insert() {
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Element inserted\n");
}

void queue_delete() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue Empty\n");
        return;
    }
    temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void queue_display() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    while (temp->next != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Stack Push\n2.Stack Pop\n3.Stack Display\n4.Queue Insert\n5.Queue Delete\n6.Queue Display\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                stack_push();
                break;
            case 2:
                stack_pop();
                break;
            case 3:
                stack_display();
                break;
            case 4:
                queue_insert();
                break;
            case 5:
                queue_delete();
                break;
            case 6:
                queue_display();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

