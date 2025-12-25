#include <stdio.h>

int cq[100], front = -1, rear = -1, n;

void insert() {
    int x;
    if ((rear + 1) % n == front) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    if (front == -1)
        front = 0;
    rear = (rear + 1) % n;
    cq[rear] = x;
    printf("Element inserted\n");
}

void delete() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted element: %d\n", cq[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue elements:\n");
    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Enter queue size: ");
    scanf("%d", &n);

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
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

