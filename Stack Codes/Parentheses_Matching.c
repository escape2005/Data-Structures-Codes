#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5

char stack[MAX];
int top = -1;

void push(int c){
    if(top == MAX-1){
        printf("Overflow!!\n");
    }
    else{
        top++;
        stack[top] = c;
    }
}

char pop(){
    if(top == -1){
        printf("Underflow!!\n");
    }
    else{
        int temp = stack[top];
        top--;
        return temp;
    }
}

int is_matching(char c1, char c2){
    if(c1 == '(' && c2 == ')'){
        return 1;
    }
    else if(c1 == '[' && c2 == ']'){
        return 1;
    }
    else if(c1 == '{' && c2 == '}'){
        return 1;
    }
    else{
        return 0;
    }
}

int isBalanced(char* text){
    int i = 0;
    for(i = 0; i<strlen(text);i++){
        if(text[i] == '(' || text[i] == '[' || text[i] == '{'){
            push(text[i]);
        }
        else if(text[i] == ')' || text[i] == ']' || text[i] == '}'){
            if(top == -1){
                return 0;
            }
            else if(!is_matching(pop(), text[i])){
                return 0;
            }
        }
    }
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void main(){
    char text[50];
    printf("Enter the string: ");
    scanf("%s", text);

    if(isBalanced(text)){
        printf("Balanced");
    }
    else{
        printf("Not Balanced");
    }
}
