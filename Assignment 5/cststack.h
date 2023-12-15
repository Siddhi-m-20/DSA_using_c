// stack using array : static stack
// stack using linkedlist : dynamic stack
// PUSH
// POP
// PEEK
// DISPLAY
// INIT

#include <stdio.h>
#define MAX 80

typedef struct stack
{
    char data[MAX];
    int top;
} stack;

void init(stack *p)
{
    p->top = -1;
}

int isfull(stack *p)
{
    if (p->top == MAX - 1)
        return 1;

    return 0;
}
void push(stack *p, char x)
{
    if (!isfull(p))
    {
        p->top++;
        p->data[p->top] = x;
    }
}

int isempty(stack *p)
{
    if (p->top == -1)
        return 1;

    return 0;
}

char pop(stack *p)
{
    char x = '\0';
    if (!isempty(p))
    {
        x = p->data[p->top];
        p->top--;
    }
    return x;
}

int peek(stack *p)
{
    char x = '\0';

    if (!isempty(p))
        x = p->data[p->top];

    return x;
}

void display(stack *p)
{
    int i;
    for (i = p->top; i >= 0; i--)
        printf("\n%c", p->data[i]);
}
