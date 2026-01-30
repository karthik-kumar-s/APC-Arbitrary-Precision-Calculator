#include "apc.h"

/*
 * increment_quotient
 * ------------------
 * Increments the quotient linked list by 1.
 * Handles carry propagation similar to addition.
 */
static void increment_quotient(node_t **head, node_t **tail)
{
    node_t *temp = *tail;

    /* If quotient list is empty, initialize with 1 */
    if (*head == NULL)
    {
        insert_at_last(head, tail, 1);
        return;
    }

    /* Increment from least significant digit */
    temp->data++;

    /* Handle carry propagation */
    while (temp != NULL && temp->data > 9)
    {
        temp->data = 0;

        if (temp->prev != NULL)
        {
            temp->prev->data++;
            temp = temp->prev;
        }
        else
        {
            /* Need to create new most significant digit */
            insert_at_first(head, tail, 1);
            break;
        }
    }
}

/*
 * division
 * --------
 * Performs division of two arbitrary precision numbers
 * using repeated subtraction.
 *
 * Only integer quotient is produced.
 * No remainder is printed.
 */
void division(node_t *head1, node_t *tail1,
              node_t *head2, node_t *tail2,
              node_t **headR, node_t **tailR)
{
    node_t *temp_head = head1;
    node_t *temp_tail = tail1;

    node_t *res_head = NULL;
    node_t *res_tail = NULL;

    node_t *sub_head = NULL;
    node_t *sub_tail = NULL;

    /* Division by zero check (basic safety) */
    if (head2 == NULL)
    {
        printf("Division by zero error\n");
        return;
    }

    /*
     * Repeat subtraction while dividend >= divisor
     */
    while (compare_list(temp_head, head2) >= 0)
    {
        /* Subtract divisor from current dividend */
        subtraction(temp_head, temp_tail,
                    head2, tail2,
                    &sub_head, &sub_tail,
                    0);

        /* Free old dividend list */
        delete_list(&temp_head, &temp_tail);

        /* Update dividend with subtraction result */
        temp_head = sub_head;
        temp_tail = sub_tail;

        sub_head = NULL;
        sub_tail = NULL;

        /* Increment quotient by 1 */
        increment_quotient(&res_head, &res_tail);
    }

    /* Final quotient */
    *headR = res_head;
    *tailR = res_tail;
}
