#include<stdio.h>
#include <stdlib.h>
struct node *top = NULL;
struct node 
{
    int data;
    struct node *next;
};
void push(int a)
{
 struct node *newnode;
 newnode =(struct node *)malloc(sizeof(struct node));
 newnode->data = a;
 if(top == NULL)
 {
     top = newnode;
     newnode->next = NULL;
 }
 else
 {
     newnode->next= top;
     top = newnode;
 }
}
void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("\nStack underflow");
    }
    temp =  top;
    top = top->next;
    printf("\nThe value popped is %d",temp->data);
    free(temp);
}
 void display()
 {
     struct node *temp;
     temp = top;
     while(temp != NULL)
     {
        printf("\n%d",temp->data);
        temp = temp->next;
     }
 }
 void peek()
 {
     printf("\nThe value at top of the stack is %d",top->data);
 }
 int main()
 {
     int c,d;
     while(1)
     {
         printf("\nEnter 1 to push");
         printf("\nEnter 2 to pop");
         printf("\nEnter 3 to display");
         printf("\nEnter 4 to peek");
         printf("\nEnter 5 to exit");
         printf("\nEnter your choice :");
         scanf("%d",&c);
         switch(c)
         {
             case 1:printf("\nEnter the data to be pushed :");
               scanf("%d",&d);
               push(d);
               break;
             case 2:pop();
             break;
             case 3 :display();
             break;
             case 4:peek();
             break;
             case 5:return 0;
             default :printf("\nInvalid choice :");
             break;            
         }
     }
     return 0;
 }
