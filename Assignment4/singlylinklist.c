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
            int opt,pos,data;
        case 0:
            printf("Enter the number of elements:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                int data;
                printf("Enter data %d : ", i + 1);
                scanf("%d", &data);
                create_list(&head, data);
            }
            break;
        case 1:
            do
            {
                printf("\n1.Insert at the begining\n2.Insert at the specified position\n3.Insert at the last position.");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    printf("\nInsert the data which you want in a linked list:\n");
                    scanf("%d", &data);
                    beginsert(&head, data);
                    break;
                case 2:
                    printf("\nInsert the data which you want in a linked list:\n");
                    scanf("%d", &data);
                    printf("\nEnter the position after which you want to insert a new node.\n");
                    scanf("%d", &pos);
                    randominsert(head, data, pos);
                    break;
                case 3:
                    printf("\nInsert the data which you want in a linked list:\n");
                    scanf("%d", &data);
                    lastinsert(head, data);
                    break;
                }
            } while (opt != 4);
            break;
        case 2:
            do
            {
                printf("\n1.Delete from the begining\n2.Delete from the specified position\n3.Delete from the last.\n");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    head = begin_delete(head);
                    break;
                case 2:
                    printf("Enter position of node after which you want to delete the node:");
                    scanf("%d", &pos);
                    random_delete(&head, pos);
                    break;
                case 3:
                    last_delete(head);
                    break;
                }
            } while (opt != 4);
            break;
        case 3:
            printf("Enter the data to be searched: \n");
            scanf("%d",&data);
            pos=search(head,data);
            if(pos==-1){
                printf("Data not found in the list.");
            }else{
            printf("%d is found at %d location in the linked list.",data,pos);
            }
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice..\n");
        }
    }
}