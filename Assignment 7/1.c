#include <stdio.h>
#include <string.h>

int longestValidParentheses(char str[])
{
    int stack[1000];
    int top = 0;
    int maxLen = 0;

    stack[0] = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            stack[++top] = i;
        }
        else
        {
            top--;

            if (top == -1)
            {
                stack[++top] = i;
            }
            else
            {
                int length = i - stack[top];

                if (length > maxLen)
                    maxLen = length;
            }
        }
    }

    return maxLen;
}

int main()
{
    char str[1000];

    printf("Enter parentheses string: ");
    scanf("%s", str);

    printf("Longest valid length = %d\n",
           longestValidParentheses(str));

    return 0;
}