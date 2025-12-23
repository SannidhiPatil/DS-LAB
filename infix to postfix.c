#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push into stack */
void push(char ch) {
    stack[++top] = ch;
}

/* Pop from stack */
char pop() {
    return stack[top--];
}

/* Check if character is an operator */
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // If operand, add to postfix
        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }

        // If '(' push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If operator push to stack
        else if (isOperator(ch)) {
            push(ch);
        }

        // If ')' pop operator and add to postfix
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
