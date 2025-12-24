#include <stdio.h>

int stack[100], top = -1, n;

void push() {
    int x;
    if (top == n - 1) {
        printf("Stack Overflow\n");
    } else {
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    scanf("%d", &n);
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}

