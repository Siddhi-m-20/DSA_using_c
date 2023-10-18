/*The operations to be performed on a linked list are
• insert () – inserts the data element x at given position.
• search (L, x) – searches for the data element x and returns the pointer to the node containing x if x is present or returns NULL.
• delete (L, x) – deletes the node containing the data element x by appropriately modifying the links.
• display (L) – displays all the data elements in the list*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *createlist(struct node *head, int data);
struct node *insert_begin(struct node *head, int data);
struct node *insert_specified(struct node *head, int data, int position);
struct node *insert_last(struct node *head, int data);
struct node *delete_begin(struct node *head);
struct node *delete_specified(struct node *head, int data);
struct node *delete_last(struct node *head);
void display(struct node *head);
int  search(struct node *head,int data);

struct node *createlist(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    return head;
}

struct node *insert_begin(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        ptr->data = data;
        // insertion at the begining when list is empty
        if (head == NULL)
        {
            head = ptr;
            printf("\nNode Inserted\n");
            return head;
        }
        // when there are more than one elements in the list.
        else
        {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
            printf("\nNode Inserted\n");
            return head;
        }
    }
}

struct node *insert_specified(struct node *head, int data, int position)
{
    int i;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        if (position == 1)
        {
            head = insert_begin(head, data);
            return head;
        }
        else
        {
            temp = head;
            for (i = 0; i < position - 1; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    printf("\n There are less than %d elements in the list", position);
                    return head;
                }
            }
            ptr->data = data;
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next = ptr;
            temp->next->prev = ptr;
            printf("\nNode inserted\n");
            return head;
        }
    }
}

struct node *insert_last(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        ptr->prev = NULL;
        if (head == NULL)
        {
            head = ptr;
            printf("\nNode inserted\n");
            return head;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
            printf("\nNode inserted\n");
            return head;
        }
    }
}

struct node *delete_begin(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nLinked List is empty.\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
        return head;
    }
    else
    {
        ptr = head;
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode Deleted");
        return head;
    }
}

struct node *delete_specified(struct node *head, int data)
{
    if (head == NULL)
    {
        printf("\nLinked List is empty.\n");
    }
    struct node *temp = head, *ptr = NULL;
    if (temp->data == data)
    {
        head = delete_begin(head);
    }
    else
    {
        ptr = temp->next;
        while (ptr != NULL && ptr->data != data)
        {
            temp = temp->next;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = NULL;
        if (ptr->next != NULL)
        {
            temp->next->prev = temp;
        }
        free(ptr);
        printf("\nNode Deleted\n");
    }
    return head;
}

struct node *delete_last(struct node *head)
{
    struct node *ptr;

    if (head == NULL)
    {
        printf("\nLinked List is empty.\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nNode Deleted.\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nNode Deleted.\n");
    }

    return head;
}


void display(struct node *head)
{
    if (head == NULL)
    {
        printf("\nLink list is empty.\n");
    }
    else
    {
        struct node *ptr;
        printf("\n Printing List values:\n");
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int search(struct node *head,int data)
{
    struct node *ptr;
    int i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\n Empty List:\n");
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                return i+1;
                break;
            }
            i++;
            ptr = ptr->next;
        }
        return -1;
    }
}