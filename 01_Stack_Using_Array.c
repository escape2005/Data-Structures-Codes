#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int c){
    if(top == MAX-1){
        printf("Overflow!!\n");
    }
    else{
        top++;
        stack[top] = c;
        printf("Element pushed successfully\n");
    }
}

void pop(){
    if(top == -1){
        printf("Underflow!!\n");
    }
    else{
        top--;
        printf("Element popped succesfully\n");
    }
}

void peek(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        printf("Element on top = %d\n", stack[top]);
    }
}

void display(){
    for(int i = 0; i <= top; i++){
        printf("Element %d = %d\n", i+1, stack[i]);
    }
}

void main(){
    int choice, val;
    do{
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter the operation you want to perform: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;
         
        case 3:
            peek();
            break;
        
        case 4:
            display();
            break;
        
        case 5: 
            exit(0);
        
        default:
            printf("Invalid! Enter again..");
            break;
        }
    } while(choice!=5);
}
