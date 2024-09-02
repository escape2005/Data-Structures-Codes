#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node *next;
};

// Pointers to the front and rear of the queue
struct node *front = NULL;
struct node *rear = NULL;

// Function to enqueue (insert) an element at the rear of the queue
void enqueue(int a) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;

    if (rear == NULL) { // Queue is empty
        front = rear = newnode;
    } else { // Queue is not empty
        rear->next = newnode;
        rear = newnode;
    }
}

// Function to dequeue (remove) an element from the front of the queue
void dequeue() {
    struct node *temp;
    if (front == NULL) { // Queue is empty
        printf("\nQueue underflow");
    } else {
        temp = front;
        front = front->next;

        if (front == NULL) { // Queue becomes empty after dequeue
            rear = NULL;
        }

        printf("\nThe value dequeued is %d", temp->data);
        free(temp);
    }
}

// Function to display all elements in the queue
void display() {
    struct node *temp;
    if (front == NULL) {
        printf("\nQueue is empty");
    } else {
        temp = front;
        while (temp != NULL) {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}

// Function to peek at the front element of the queue
void peek() {
    if (front == NULL) {
        printf("\nQueue is empty");
    } else {
        printf("\nThe value at the front of the queue is %d", front->data);
    }
}

int main() {
    int c, d;
    while (1) {
        printf("\nEnter 1 to enqueue");
        printf("\nEnter 2 to dequeue");
        printf("\nEnter 3 to display");
        printf("\nEnter 4 to peek");
        printf("\nEnter 5 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("\nEnter the data to be enqueued: ");
                scanf("%d", &d);
                enqueue(d);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid choice");
                break;
        }
    }
    return 0;
}
