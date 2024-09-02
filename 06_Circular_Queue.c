#include<stdio.h>
#include<stdlib.h>

#define MAX 8

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int);
void dequeue();
void display();

void main(){
    int choice, val;

    while(1){
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid! Enter again.");
            break;
        }
    }
}

void enqueue(int val){
    if((rear+1)%MAX == front){
        printf("Overflow");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear = (rear+1)%MAX;
        queue[rear] = val;
        printf("Element %d was added successfully\n", val);
    }
}

void dequeue(){
    if(front == -1){
        printf("Underflow");
    }
    else{
        printf("Element %d was deleted.\n", queue[front]);
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty.");
    }
    else{
        int temp = front;
        while(temp!=rear){
            printf("%d\n", queue[temp]);
            temp = (temp+1)%MAX;
        }
        printf("%d\n", queue[rear]);
    }
}
