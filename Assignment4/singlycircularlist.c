/*There are lists where new elements are always appended at the end of the list.
The list can be implemented as a circular list with the external pointer pointing to the last element of the list.
Implement singly linked circular list of integers with append and display operations. The operation append(L, n),
appends to the end of the list, n integers either accepted from user or randomly generated.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nMemory allocation failed.exit program.\n");
        exit(0);
    }
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

struct node *append(struct node *head, int data)
{
    struct node *ptr = createnode(data);
    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    ptr->next = head;
    temp->next = ptr;
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    struct node *temp = head;
    printf("\nCircular linked list is:\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    struct node *head = NULL;
    int n, choice = 0, i;
    while (choice != 5)
    {
        printf("\n *****************Main Menu *****************\n");
        printf("\nChoose one option from the following list....\n");
        printf("\n=============================================\n");
        printf("\n1.Append list by user input\n2.Append by random inputs.\n3.Show the list\n4.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
            int data;
        case 1:
            printf("How many integers you want to append?\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter data %d:", i + 1);
                scanf("%d", &data);
                head = append(head, data);
            }
            printf("\n Data appended successfully.\n");
            break;
        case 2:
            printf("Enter how many random integers do you want to apend:\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                data = rand() % 100;
                head = append(head, data);
            }
            printf("\n Data appended successfully.\n");
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Please enter correct choice\n");
        }
    }
    return 0;
}