#include "cststack.h"
int main()
{
    stack s;
    int i;
    char ch;
    char str[80];

    init(&s);

    printf("\nEnter a string:");
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
        push(&s,str[i]);

    i=0;
    while(!isempty(&s)){
        ch = pop(&s);
        str[i++] = ch;        
    }

    printf("\nReversed string is %s",str);

    return 0;
}