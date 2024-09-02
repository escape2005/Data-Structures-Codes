#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

char postfix[MAX];
int postfixIndex = 0;

void push(char c);
char pop(void);
char peek(void);
int isEmpty(void);
int precedence(char op);
void infixToPostfix(const char* infix);

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop(void) {
    if (!isEmpty()) {
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

char peek(void) {
    if (!isEmpty()) {
        return stack[top];
    }
    return '\0'; // Return null character if stack is empty
}

int isEmpty(void) {
    return top == -1;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infixToPostfix(const char* infix) {
    postfixIndex = 0; 

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        
        if (isspace(c)) continue; 
        
        if (isalnum(c)) {
            postfix[postfixIndex++] = c; 
        } else if (c == '(') {
            push(c); 
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[postfixIndex++] = pop();
            }
            pop(); 
        } else { 
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[postfixIndex++] = pop(); 
            }
            push(c); 
        }
    }
    
    // Pop all remaining operators from the stack
    while (!isEmpty()) {
        postfix[postfixIndex++] = pop();
    }
    
}


int main() {
    char infix[MAX] = "x=(a+b)*(c+d)";
    
    infixToPostfix(infix);
    
    printf("Postfix: %s\n", postfix);
    
    return 0;
}
