#include "apc.h"

/*
 * compare_list
 * ------------
 * Compares two numbers represented as doubly linked lists.
 *
 * Returns:
 *   1  -> list1 > list2
 *   0  -> list1 == list2
 *  -1  -> list1 < list2
 */
int compare_list(node_t *head1, node_t *head2)
{
    int len1 = 0, len2 = 0;
    node_t *temp1 = head1;
    node_t *temp2 = head2;

    /* Calculate length of list1 */
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    /* Calculate length of list2 */
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    /* Length comparison */
    if (len1 > len2)
        return 1;
    else if (len1 < len2)
        return -1;

    /* If lengths are equal, compare digit by digit */
    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
            return 1;
        else if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    /* Both numbers are equal */
    return 0;
}

/*
 * subtraction
 * -----------
 * Performs subtraction of two arbitrary precision numbers.
 *
 * IMPORTANT:
 * - Assumes operand1 >= operand2
 * - Sign handling is done in main()
 * - Traversal is from tail to head
 */
void subtraction(node_t *head1, node_t *tail1,
                 node_t *head2, node_t *tail2,
                 node_t **headR, node_t **tailR,
                 int sign)
{
    (void)head1;
    (void)head2;
    (void)sign;

    node_t *temp1 = tail1;
    node_t *temp2 = tail2;

    int diff = 0;
    int borrow = 0;

    /* Initialize result list */
    *headR = NULL;
    *tailR = NULL;

    /*
     * Traverse both lists from LSB to MSB
     */
    while (temp1 != NULL)
    {
        if (temp2 != NULL)
        {
            diff = temp1->data - temp2->data - borrow;
            temp2 = temp2->prev;
        }
        else
        {
            diff = temp1->data - borrow;
        }

        /* Borrow handling */
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        /* Store result digit */
        insert_at_first(headR, tailR, diff);

        temp1 = temp1->prev;
    }
}
