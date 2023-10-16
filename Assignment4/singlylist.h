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
void beginsert(struct node **head, int data);
void randominsert(struct node *head, int data, int pos);
void lastinsert(struct node *head, int data);
struct node *begin_delete(struct node *head);
void random_delete(struct node **head, int pos);
void last_delete(struct node *head);
int search(struct node *head,int data);


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
    }
}

void beginsert(struct node **head, int data)
{
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = *head;
    *head = ptr;
    printf("\nNode Inserted.\n");
}

void randominsert(struct node *head, int data, int pos)
{
    int i;
    struct node *temp = head;
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode Inserted.");
    }
}

void lastinsert(struct node *head, int data)
{
    struct node *temp = head;
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nNode Inserted");
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            printf("\nNode Inserted");
        }
    }
}

struct node *begin_delete(struct node *head)
{

    if (head == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        head = temp->next;
        free(temp);
        temp = NULL;
        printf("\nNode Deleted Successfully.\n");
    }
    return head;
}

void last_delete(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted Successfully.\n");
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        printf("\nNode Deleted Successfully.\n");
    }
}

void random_delete(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("\nLinked list is empty.\n");
    }
    else
    {
        struct node *ptr = *head, *prev = NULL;
        int i;
        if (pos == 1)
        {
            *head = ptr->next;
            free(ptr);
            ptr = NULL;
            printf("\nNode Deleted\n");
        }
        else{
            if (ptr == NULL)
        {
            printf("\nPosition %d is out of range.\n", pos);
            return;
        }
        for (i = 0; i < pos && ptr != NULL; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        
        prev->next = ptr->next;
        free(ptr);
        printf("\nNode deleted Successfully");
        }
    }
}

int search(struct node *head,int data)
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
