#include "apc.h"

/*
 * multiplication
 * --------------
 * Performs multiplication of two arbitrary precision numbers
 * using school-level multiplication logic.
 *
 * Uses addition() to accumulate partial products.
 */
void multiplication(node_t *head1, node_t *tail1,
                    node_t *head2, node_t *tail2,
                    node_t **headR, node_t **tailR)
{
    (void)head1;
    (void)head2;

    node_t *temp2 = tail2; /* Traverses operand-2 */
    node_t *temp1;         /* Traverses operand-1 */

    node_t *headR1 = NULL, *tailR1 = NULL; /* Accumulated result */
    node_t *headR2 = NULL, *tailR2 = NULL; /* Current partial product */

    int count = 0; /* Controls zero shifting */
    int prod, carry;

    /* Traverse operand-2 from LSB to MSB */
    while (temp2 != NULL)
    {
        carry = 0;
        temp1 = tail1;

        /* -----------------------------
         * Zero padding (shift handling)
         * ----------------------------- */
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                insert_at_first(&headR2, &tailR2, 0);
            }
        }

        /* -----------------------------
         * Inner loop: digit multiplication
         * ----------------------------- */
        while (temp1 != NULL)
        {
            prod = (temp1->data * temp2->data) + carry;

            carry = prod / 10;
            prod = prod % 10;

            insert_at_first(&headR2, &tailR2, prod);

            temp1 = temp1->prev;
        }

        /* If carry remains after inner loop */
        if (carry > 0)
        {
            insert_at_first(&headR2, &tailR2, carry);
        }

        /* --------------------------------
         * First iteration special handling
         * -------------------------------- */
        if (count == 0)
        {
            /* Copy headR2 into headR1 */
            headR1 = headR2;
            tailR1 = tailR2;

            headR2 = NULL;
            tailR2 = NULL;
        }
        else
        {
            /* Add accumulated result and new partial product */
            addition(headR1, tailR1, headR2, tailR2, headR, tailR);

            /* Update accumulated result */
            delete_list(&headR1, &tailR1);
            headR1 = *headR;
            tailR1 = *tailR;

            /* Clear temporary result list */
            delete_list(&headR2, &tailR2);
        }

        /* Prepare for next digit */
        count++;
        temp2 = temp2->prev;
    }

    /* Final result */
    *headR = headR1;
    *tailR = tailR1;
}
