#include <iostream>

using namespace std;

int s1[50], s2[50];

int top1 = -1, top2 = -1;

int count = 0;

void push1(int data)
{

    top1++;
    s1[top1] = data;
}
void push2(int data)
{

    top2++;
    s2[top2] = data;
}

int pop1()
{
    return s1[top1--];
}
int pop2()
{
    return s2[top2--];
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    if (top1 == -1)
    {
        cout << "stack is empty";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int a = pop1();
            push2(a);
        }

        int b = pop2();
        cout << "popped element is" << b;

        count--;
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
    }
}
void display()
{
    for (int i = 0; i < top1; i++)
    {
        printf("%d", s1[i]);
        cout << endl;
    }
}

int main()
{

    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(2);
    enqueue(17);
    enqueue(27);
    enqueue(23);

    enqueue(27);
    dequeue();
    cout << endl;
    enqueue(29);
    enqueue(7);
    enqueue(8);
    dequeue();
    cout << endl;
    dequeue();
    cout << endl;
    dequeue();

    cout << endl;
    display();
}
