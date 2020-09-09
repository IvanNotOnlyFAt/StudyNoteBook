#include <stdio.h>

#include "stack.h"

int isLeft(char c)
{
    int ret = 0;
    switch (c) {
    case '<':
    case '(':
    case '{':
    case '[':
    case '\'':
    case '\"':
        ret = 1;
    default:
        ret = 0;
    }
    return ret;
}

int isRight(char c)
{
    int ret = 0;
    switch (c) {
    case '>':
    case ')':
    case '}':
    case ']':
    case '\'':
    case '\"':
        ret = 1;
    default:
        ret = 0;
    }
    return ret;
}

int match(char lc, char rc)
{
    int ret = 0;
    switch (lc)
    {
    case '<': ret = (rc == '>'); break;
    case '{': ret = (rc == '}'); break;
    case '(': ret = (rc == ')'); break;
    case '[': ret = (rc == ']'); break;
    case '\'': ret = (rc == '\''); break;
    case '\"': ret = (rc == '\"'); break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

void dealString(char *str)
{
    int i = 0;
    LinkStack *stack = LinkStack_Create();
    while(str[i] != '\0')
    {
        if(isLeft(str[i]))
        {
            LinkStack_Push(stack, str + i);
            i++;
            continue;
        }
        if(isRight(str[i]))
        {
            char *p = (char *)LinkStack_Pop(stack);
            if (p == NULL || !match(*p, str[i]))
            {
                printf("匹配失败在：%c\n", str[i]);
                break;
            }
        }
        i++;
    }
    if (LinkStack_Size(stack) == 0 && str[i] == '\0')
    {
        printf("匹配成功!\n");
    }else{
        while (LinkStack_Size(stack) > 0)
        {
            printf("匹配失败在: %c\n", (LinkStack_Pop(stack)));
        }
    }
    LinkStack_Destroy(stack);
}

int main()
{
    char arr[] = "#include<stdio.h> int main() { helloworld! }";
    dealString(arr);

    return 0;
}
