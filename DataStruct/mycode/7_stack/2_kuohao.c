#include<stdio.h>

#define  SIZE  512
#define TRUE 1
#define FLASE 0

char  stack[SIZE];
int top = 0;

void push(char item)
{
    stack[top++] = item;
}

char pop()
{
    return stack[--top];
}

int Match_Bracket()
{
    char ch,x;

    scanf("%c",&ch);

    while(ch != '#')
    {
        if((ch == '(' )||( ch == '[' )) 
            push(ch);
        else if(ch == ']')
        {
            x = pop();
            if(x != '[')
            {
                printf(" '[' bu pipei ");
                return FLASE;
            }
        }
        else if (ch == ')')
        {
            x = pop();
            if(x != '(')
            {
                printf(" '('  bupipei ");
                return FLASE;
            }
        }
        scanf("%c",&ch);
    }

    if(top != 0)
    {
        printf(" shu liang bu pi pei !");
        return FLASE;
    }
    else return TRUE;

}

int main()
{

    if(Match_Bracket() == TRUE)
    {
        printf("pi pei\n");
    }
    else
    {
        printf("bu pi pei\n");
    }

    return 0;
}
