#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int a){
    if(top == 19){
        printf("Overflow");
    }
    else{
        stack[++top] = a;
    }
}

int pop(){
    if (top == -1){
        printf("Underflow");
    }
    else{
        return stack[top--];
    }
}

void main(){
    char input[20];
    int i = 0, num1, num2, ele, ans;
    printf("Enter the expression: ");
    scanf("%s", input);
    while (i<strlen(input))
    {
       ele = input[i];
       if(isdigit(ele)){
        push(ele - '0');
       }
       else{
        num2 = pop();
        num1 = pop();
        switch(ele){
                case '^':
                    ans = pow(num1, num2);
                    break;
                case '+':
                    ans = num1+num2;
                    break;
                case '-':
                    if(num1>num2){
                        ans = num1 - num2;
                    }
                    else{
                        ans = num2 - num1;
                    }
                    break;
                case '*':
                    ans = num1*num2;
                    break;
                case '/':
                    ans = num2/num1;
                    break;
            }
            push(ans);
       }
       i++;
    }
    

    printf("Answer: %d", pop());
}
