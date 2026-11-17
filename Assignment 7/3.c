#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1) pop();
        } else {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                    (precedence(stack[top]) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);
    return 0;
}