#include <iostream>
#include <stdlib.h>

using namespace std;

class node
{
public:
    char data;
    int size;
    int top;
    char *arr;
};

int isEmpty(node *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(node *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(node *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char pop(node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char x = ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesis(char *exp)
{
    class node *sp;

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
    int count = 0;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = "[(8)](*--$$9)";
    if (parenthesis(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}