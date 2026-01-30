#ifndef LIST_H
#define LIST_H

/* =========================
 *  Standard Header Files
 * ========================= */
#include <stdio.h>
#include <stdlib.h>

/* 
 *  =========================
 *  Doubly Linked List Node
 * ========================= 
 */ 
typedef struct node
{
    int data;          /* Stores single digit (0–9) */
    struct node *prev; /* Pointer to previous node */
    struct node *next; /* Pointer to next node */
} node_t;

/* =========================
 *  Linked List Operations
 * ========================= */

/* Insert digit at the end of the list */
void insert_at_last(node_t **head, node_t **tail, int data);

/* Insert digit at the beginning of the list */
void insert_at_first(node_t **head, node_t **tail, int data);

/* Delete entire list and free memory */
void delete_list(node_t **head, node_t **tail);

/* Print list data from head to tail */
void print_list(node_t *head);

#endif /* LIST_H */
