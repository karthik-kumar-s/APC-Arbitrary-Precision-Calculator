#include "list.h"

/*
 * insert_at_last
 * ----------------
 * Inserts a new node with given data at the end of the list.
 * Used while converting input digits and in some result constructions.
 */
void insert_at_last(node_t **head, node_t **tail, int data)
{
    node_t *new = (node_t *)malloc(sizeof(node_t));

    /* Safety check */
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    /* If list is empty */
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }
}

/*
 * insert_at_first
 * ----------------
 * Inserts a new node with given data at the beginning of the list.
 * Used mainly for result storage (LSB → MSB generation).
 */
void insert_at_first(node_t **head, node_t **tail, int data)
{
    node_t *new = (node_t *)malloc(sizeof(node_t));

    /* Safety check */
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    /* If list is empty */
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

/*
 * delete_list
 * ------------
 * Deletes the entire list and frees allocated memory.
 * Used heavily in multiplication and division to avoid garbage accumulation.
 */
void delete_list(node_t **head, node_t **tail)
{
    node_t *temp = *head;

    while (temp != NULL)
    {
        node_t *next = temp->next;
        free(temp);
        temp = next;
    }

    /* Reset head and tail */
    *head = NULL;
    *tail = NULL;
}

/*
 * print_list
 * -----------
 * Prints the number stored in the linked list from head to tail.
 * No spaces, no formatting – exact digit output.
 */
void print_list(node_t *head)
{
    node_t *temp = head;

    if (temp == NULL)
    {
        printf("0");
        return;
    }

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
