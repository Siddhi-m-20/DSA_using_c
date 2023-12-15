#include <stdio.h>
#include "dystack.h"

int main()
{
    int choice, x, ans;
    stack *top;

    top = init(top);

    do
    {
        printf("\n1:PUSH");
        printf("\n2:POP");
        printf("\n3:PEEK");
        printf("\n4:PRINT");
        printf("\n5:Exit");

        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number to be pushed:");
            scanf("%d", &x);
            top = push(top, x);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            ans = peek(top);
            if (ans != -1)
                printf("\nTopmost element : %d", ans);
            break;
        case 4:
            display(top);
            break;
        }
    } while (choice != 5);

    return 0;
}