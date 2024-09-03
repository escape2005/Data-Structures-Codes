#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();

void main(){
    int choice;
    while (1)
    {
    {
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter what you want to perform: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
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
                printf("Invalid! Enter again.. \n");
        break;
        }
    }
}
}
void enqueue(){
    if(rear == MAX - 1){
        printf("Overflow\n");
        return;
    }
    else{
        if(front==-1){
            front = 0;
        }
        int val;
        printf("Enter the value to be enqueued: ");
        scanf("%d", &val);
        rear++;
        queue[rear] = val;
        printf("Element enqueued successfully!\n");
    }
}

void dequeue(){
    if(front == -1 || front>rear){
        printf("Underflow\n");
    }
    else{
        printf("Element %d dequeued successfully\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1){
        printf("Empty Queue\n");
    }
    else{
        for(int i=front ;i<=rear; i++){
            printf("%d \n", queue[i]);
        }
    }
}
