#include <stdio.h>
#include "ststack.h"

int main()
{
    Stack stack;
    initialize(&stack);
    int E=isEmpty(&stack);
    printf("%d\n",E);
    int F=isFull(&stack);
    printf("%d\n",F);
    int n=10;
    for(int i=0;i<n;i++){
    push(&stack, i+1);
    }
    
    
    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    display(&stack);

    return 0;
}
