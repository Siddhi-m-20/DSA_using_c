#include "cststack.h"
int main() // driver code
{
    int i, flag = 1;
    char str[80];
    stack s;

    init(&s);

    printf("\nEnter a string:");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
        push(&s, str[i]);

    i = 0;
    while (!isempty(&s))
    {
        if (str[i] != pop(&s))
        {
            flag = 0;
            break;
        }
        i++;
    }

    if (flag == 1)
        printf("\n%s is a palindrome string", str);
    else
        printf("\n%s is not a palindrome string", str);

    return 0;
}