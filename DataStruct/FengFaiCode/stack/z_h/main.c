#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isNumber(char c)
{
    return (c >= '0') && (c <= '9');
}

int isOperator(char c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
    return (c == '(');
}

int isRight(char c)
{
    return (c == ')');
}

int priority(char c)
{
    int ret = 0;
    if ( (c == '+') || (c == '-') )
    {
        ret = 1;
    }
    else if ( (c == '*') || (c == '/') )
    {
        ret = 2;
    }
    return ret;
}

void outPut(char c)
{
    if (c != '\0')
    {
        printf("%c", c);
    }
}

void transform(const char *arr)
{
    int i = 0;
    LinkStack *tmp = LinkStack_Create();
    while (arr[i] != '\0')
    {
        if (isNumber(arr[i]))
        {
            outPut(arr[i]);
        }
        else if (isOperator(arr[i]))
        {
            while (priority(arr[i]) <= priority((char)LinkStack_Top(tmp)))
            {
                outPut((char)LinkStack_Pop(tmp));
            }
            LinkStack_Push(tmp, (void *)arr[i]);
        }
        else if (isLeft(arr[i]))
        {
            LinkStack_Push(tmp, (void *)arr[i]);
        }
        else if (isRight(arr[i]))
        {
            //char c = '\0';
            while (!isLeft((char)LinkStack_Top(tmp)))
            {
                outPut((char)(int)LinkStack_Pop(tmp));
            }

            LinkStack_Pop(tmp);
        }
        else
        {
            printf("Invalid expression!");
            break;
        }
        i++;
    }

    while ((LinkStack_Size(tmp) > 0) && (arr[i] == '\0'))
    {
        outPut((char)LinkStack_Pop(tmp));
    }

    LinkStack_Destroy(tmp);
}

int main()
{
    transform("(6+5)*7+7");

    printf("\n");
    system("pause");
    return 0;
}
