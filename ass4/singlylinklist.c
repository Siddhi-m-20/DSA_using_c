/*Implement a list library (singlylist.h) for a singly linked list with the above four operations. Write a menu driven driver program to call the operations.*/

#include <stdlib.h>
#include <stdio.h>
#include "singlylist.h"

void main()
{
    struct node *head = NULL;
    int n;
    int choice = 0;
    while (choice != 6)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n0.Create a list\n1.Insert \n2.Delete \n3.Search for an element\n4.Show\n5.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
            int opt, pos, data,i;
        case 0:
            printf("Enter the number of elements:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                int data;
                printf("Enter data %d : ", i + 1);
                scanf("%d", &data);
                create_list(&head, data);
            }
            break;
        case 1:
                printf("\nInsert at the specified position\n");
                printf("\nInsert the data which you want in a linked list:\n");
                   scanf("%d", &data);
                printf("\nEnter the position after which you want to insert a new node.\n");
                    scanf("%d", &pos);
                    insert(&head, data, pos);
		display(head);               
     break;
        case 2:
                printf("\nDelete the specific data\n");
                    printf("\nEnter the data which you want to delete:\n");
                    scanf("%d", &data);
                    delete(&head, data);
		display(head);         
           break;
         case 3:
            printf("\nEnter the data to be searched: \n");
            scanf("%d", &data);
            pos = search(head, data);
            if (pos == -1)
            {
                printf("\nData not found in the list.");
            }
            else
            {
                printf("\n%d is found at %d location in the linked list.", data, pos);
            }
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nPlease enter a valid choice..\n");
        }
    }
}
