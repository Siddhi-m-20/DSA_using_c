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
void insert_specified(struct node **head, int data, int position);
void delete_specified(struct node **head, int data);
void display(struct node *head);
int search(struct node *head, int data);

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
void insert_specified(struct node **head, int data, int position)
{
  int count = 1;
  struct node *ptr, *temp;
  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\nOVERFLOW");
  }
  else
  {
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    if (position == 1)
    {
      ptr->next = *head;
      ptr->prev = NULL;
      if (*head != NULL)
      {
        (*head)->prev = ptr;
      }
      *head = ptr;
      return;
    }
    else
    {
      temp = *head;
      while (temp != NULL && count < position - 1)
      {
        temp = temp->next;
        count++;
      }
      if (temp == NULL)
      {
        printf("Invalid position.\n");
        free(temp);
        return;
      }

      ptr->next = temp->next;
      temp->next->prev = ptr; // This line assumes temp->next is not NULL, so ensure proper error handling
      ptr->prev = temp;
      temp->next = ptr;
    }
  }
}
void delete_specified(struct node **head, int data)
{
  if (*head == NULL)
  {
    printf("\nLinked List is empty.\n");
    return;
  }
  struct node *temp = *head;
  while (temp != NULL && temp->data != data)
  {
    temp = temp->next;
  }
  if (temp == NULL)
  {
    printf("\nData %d not found in a linked list", data);
    return;
  }
  if (temp->prev != NULL)
  {
    temp->prev->next = temp->next;
  }
  else
  {
    *head = temp->next;
  }
  if (temp->next != NULL)
  {
    temp->next->prev = temp->prev;
  }
  free(temp);
  printf("\nNode Deleted\n");
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
int search(struct node *head, int data)
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
        return i + 1;
        break;
      }
      i++;
      ptr = ptr->next;
    }
    return -1;
  }
}
