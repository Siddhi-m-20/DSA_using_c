// stack using linkedlist : dynamic stack
#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *init(stack *top)
{
    top = NULL;
    return top;
}

stack *push(stack *top, int x) // insert a new stack at first
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    temp->data = x;
    temp->next = NULL;

    if (top == NULL)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }

    return top;
}

int isempty(stack *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
stack *pop(stack *top) // delete first stack
{
    int x, ans;
    stack *p;
    ans = isempty(top);
    if (ans == 1)
        printf("\nStack is empty");
    else
    {
        p = top;
        top = top->next;
        p->next = NULL;
        x = p->data;
        printf("\nDeleted Element : %d", x);
        free(p);
    }
    return top;
}

int peek(stack *top)
{
    int ans, x = -1;
    ans = isempty(top);
    if (ans == 1)
        printf("\nSTACK is empty");
    else
        x = top->data;
    return x;
}
void display(stack *top)
{
    stack *p;
    p = top;
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
