/*insert () – inserts the data element x at given position.
• search (L, x) – searches for the data element x and returns the pointer to the node
containing x if x is present or returns NULL.
• delete (L, x) – deletes the node containing the data element x by appropriately
modifying the links.
• display (L) – displays all the data elements in the list*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void create_list(struct node **head, int data);
void display(struct node *head);
void insert(struct node **head, int data, int pos);
void delete(struct node **head, int pos);
int search(struct node *head, int data);

void create_list(struct node **head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        return;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void display(struct node *head)
{

    if (head == NULL)
    {
        printf("\nLinked List is Empty.\n");
    }
    else
    {
        printf("\n Printing Elements of linked list: \n");
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        return;
    }
}

void insert(struct node **head, int data, int pos)
{
    int i;
    struct node *temp = *head;
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;

	if(pos==1){
	ptr->next=*head;
	*head=ptr;
	 printf("\nNode Inserted.\n");
	return;
	}

	else{
        for (i = 1; i < pos-1 && temp!=NULL; i++)
        {
            temp = temp->next;
        }

	if(temp==NULL){
	printf("Invalid Position.Insertion not possible.\n");
	free(ptr);
	return;
	}

        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode Inserted.\n");
	} 
   }
}


void delete(struct node **head, int data)
{
    if (*head == NULL)
    {
        printf("\nLinked list is empty.\n");
	return; 
   }
    else
    {
    struct node *temp = *head,*ptr=*head, *ptr1 = NULL;
        if (temp->data == data)
        {
            *head = temp->next;
            free(temp);
            temp = NULL;
            printf("\nNode Deleted Successfully.\n");
        	return;
	}
        else
        {
          
            while (ptr != NULL && ptr->data != data)
            {
                ptr1=ptr;
                ptr = ptr->next;
            }

            if (ptr != NULL)
            {
                ptr1->next = ptr->next;
                free(ptr);
                printf("\nNode deleted Successfully.\n");
            }
            else
            {
                printf("\nNode with data %d not found.\n", data);
            }
        }
    }
}

int search(struct node *head, int data)
{
    if (head == NULL)
    {
        printf("The List is empty");
    }
    else
    {
        int pos = 1, flag = 0;
        struct node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                return pos;
            }
            pos++;
            ptr = ptr->next;
        }
    }
    return -1;
}
