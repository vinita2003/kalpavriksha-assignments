
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EXP_SIZE 100

void removeWhitespaces(char *exp)
{
    char *p = exp;
    char *q = exp;
    while (*q != '\0')
    {
        if (!isspace(*q))
        {
            *p++ = *q;
        }
        q++;
    }
    *p = '\0';
};

bool isValidExpression(char *exp)
{
    char operators[4] = {'+', '-', '*', '/'};
    bool isValid = true;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (!(exp[i] >= '0' && exp[i] <= '9') && !(exp[i] == '+' || exp[i] == '*' || exp[i] == '-' || exp[i] == '/'))
        {
            isValid = false;
            break;
        }
        if ((exp[i] == operators[0] || exp[i] == operators[1] || exp[i] == operators[2] || exp[i] == operators[3]) && 
            (exp[i + 1] == operators[0] || exp[i + 1] == operators[1] || exp[i + 1] == operators[2] || exp[i + 1] == operators[3]))
        {
            isValid = false;
            break;
        }
        if (exp[i] == '/' && exp[i + 1] == '0')
        {
            isValid = false;
            break;
        }
    }

    return isValid;
}


int calculate(const char *exp)
{
    int stack[100];      
    int top = -1;        
    char sign = '+';     
    int num = 0;         
    int i = 0;           
    int len = strlen(exp); 

    for (i = 0; i < len; i++)
    {
        char c = exp[i];

        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }

        
        if (!isdigit(c) && c != ' ' || i == len - 1)
        {
            if (sign == '+')
            {
                stack[++top] = num;
            }
            else if (sign == '-')
            {
                stack[++top] = -num;
            }
            else if (sign == '*')
            {
                stack[top] = stack[top] * num;
            }
            else if (sign == '/')
            {
                stack[top] = stack[top] / num;
            }

            sign = c;
            num = 0;
        }
    }

    int result = 0;
    for (i = 0; i <= top; i++)
    {
        result += stack[i];
    }

    return result;
}

int main()
{
    char exp[MAX_EXP_SIZE];
    printf("Enter the mathematical expression: ");
    fgets(exp, MAX_EXP_SIZE, stdin);
    removeWhitespaces(exp);
    if (isValidExpression(exp))
    {
        int result = calculate(exp);
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Invalid expression\n");
    }
    return 0;
}
