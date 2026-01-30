#include "apc.h"

/*
 * addition
 * --------
 * Performs addition of two arbitrary precision numbers represented
 * as doubly linked lists.
 *
 * Traversal is done from tail to head (LSB to MSB).
 * Result digits are inserted at the beginning of the result list.
 */
void addition(node_t *head1, node_t *tail1,
              node_t *head2, node_t *tail2,
              node_t **headR, node_t **tailR)
{
    (void)head1;
    (void)head2;

    node_t *temp1 = tail1;
    node_t *temp2 = tail2;

    int sum = 0;
    int carry = 0;

    /* Initialize result list */
    *headR = NULL;
    *tailR = NULL;

    /*
     * Continue till both lists are completely traversed
     */
    while (temp1 != NULL || temp2 != NULL)
    {
        /* Case 1: Both digits are present */
        if (temp1 != NULL && temp2 != NULL)
        {
            sum = temp1->data + temp2->data + carry;
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        /* Case 2: Only operand1 digit present */
        else if (temp1 != NULL)
        {
            sum = temp1->data + carry;
            temp1 = temp1->prev;
        }
        /* Case 3: Only operand2 digit present */
        else
        {
            sum = temp2->data + carry;
            temp2 = temp2->prev;
        }

        /* Carry handling */
        if (sum > 9)
        {
            carry = 1;
            sum = sum % 10;
        }
        else
        {
            carry = 0;
        }

        /* Store result digit at beginning */
        insert_at_first(headR, tailR, sum);
    }

    /*
     * If carry remains after loop completion,
     * insert it at the beginning of result list
     */
    if (carry == 1)
    {
        insert_at_first(headR, tailR, carry);
    }
}
