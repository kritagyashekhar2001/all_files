#include <iostream>
using namespace std;

class stack
{
public:
    int top, size;
    int *arr;
    int push();
    int pop();
    int isFull();
    int isEmpty();
};

int isEmpty(stack *ptr)
{
    if (ptr->top <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(stack *ptr)
{
    if (ptr->top >= ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(stack *ptr, int data)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow";
        return 1;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        return 0;
    }
}
int pop(stack *ptr)
{

    if (isEmpty(ptr))
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void display(stack *ptr)
{
    if (ptr->top == -1)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        for (int i = ptr->top; i >= 0; i--)
        {
            cout << ptr->arr[i] << endl;
        }
    }
}
int main()
{
    class stack *sp = new stack();
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    push(sp, 8);
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    printf("After pushing, Full: %d\n", isFull(sp));
    pop(sp);
    pop(sp);

    printf("After pushing, Empty: %d\n", isEmpty(sp));
    display(sp);
}