#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int deque[MAX];
int front = -1;
int rear = -1;

void insert_front(int val);
void insert_rear(int val);
void delete_front();
void delete_rear();
void display();

int main() {
    int choice, val;

    while(1) {
        printf("\n1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted at front: ");
                scanf("%d", &val);
                insert_front(val);
                break;
            case 2:
                printf("Enter the value to be inserted at rear: ");
                scanf("%d", &val);
                insert_rear(val);
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}

void insert_front(int val) {
    if((front == 0 && rear == MAX-1) || (front == rear + 1)) {
        printf("Overflow: Cannot insert at front\n");
    } else {
        if(front == -1) {
            front = rear = 0;
        } else if(front == 0) {
            front = MAX - 1;
        } else {
            front = front - 1;
        }
        deque[front] = val;
        printf("Inserted %d at front\n", val);
    }
}

void insert_rear(int val) {
    if((front == 0 && rear == MAX-1) || (front == rear + 1)) {
        printf("Overflow: Cannot insert at rear\n");
    } else {
        if(front == -1) {
            front = rear = 0;
        } else if(rear == MAX - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        deque[rear] = val;
        printf("Inserted %d at rear\n", val);
    }
}

void delete_front() {
    if(front == -1) {
        printf("Underflow: Cannot delete from front\n");
    } else {
        printf("Deleted %d from front\n", deque[front]);
        if(front == rear) {
            front = rear = -1;
        } else if(front == MAX - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
}

void delete_rear() {
    if(rear == -1) {
        printf("Underflow: Cannot delete from rear\n");
    } else {
        printf("Deleted %d from rear\n", deque[rear]);
        if(front == rear) {
            front = rear = -1;
        } else if(rear == 0) {
            rear = MAX - 1;
        } else {
            rear = rear - 1;
        }
    }
}

void display() {
    if(front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements are: ");
        int i = front;
        while(i != rear) {
            printf("%d ", deque[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", deque[rear]);
    }
}
