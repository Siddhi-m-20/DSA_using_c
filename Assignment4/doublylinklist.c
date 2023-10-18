/*Implement a list library (doublylist.h) for a doubly linked list with the above four operations. Write a menu driven driver program to call the operations.*/

#include <stdio.h>
#include <stdlib.h>
#include "doublylinklist.h"

void main()
{
    int choice = 0;
    struct node *head = NULL;
    int n;
    while (choice != 9)
    {
        printf("\n *****************Main Menu *****************\n");
        printf("\nChoose one option from the following list....\n");
        printf("\n===================================================================================\n");
        printf("\n0.Create a list\n1.Insert \n2.Delete \n3.Search for an element\n4.Show\n5.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
            int opt, pos, data;
        case 0:
            printf("Enter the number of elements:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                int data;
                printf("Enter data %d : ", i + 1);
                scanf("%d", &data);
                head = createlist(head, data);
            }
            break;
        case 1:
            do
            {
                printf("\n1.Insert at the begining\n2.Insert at the specified position\n3.Insert at the last position.\n");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    printf("\nInsert the data which you want in a linked list:\n");
                    scanf("%d", &data);
                    head = insert_begin(head, data);
                    break;
                case 2:
                    printf("\nInsert the data which you want in a linked list:\n");
                    scanf("%d", &data);
                    printf("\nEnter the position after which you want to insert a new node.\n");
                    scanf("%d", &pos);
                    head = insert_specified(head, data, pos);
                    break;
                case 3:
                    printf("\nInsert the data which you want in a linked list:\n");
                    scanf("%d", &data);
                    head = insert_last(head, data);
                    break;
                }
            } while (opt != 4);
            break;
        case 2:
            do
            {
                printf("\n1.Delete from the begining\n2.Delete the specific data\n3.Delete from the last.\n");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    head = delete_begin(head);
                    break;
                case 2:
                    printf("\nEnter the data which you want to delete from the list:\n");
                    scanf("%d", &data);
                    head = delete_specified(head, data);
                    break;
                case 3:
                    head = delete_last(head);
                    break;
                }
            } while (opt != 4);
            break;
            case 3:
                printf("\nEnter the data to be searched: \n");
                scanf("%d",&data);
                pos=search(head,data);
                if(pos==-1){
                    printf("\nData not found in the list.");
                }else{
                printf("\n%d is found at %d location in the linked list.",data,pos);
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