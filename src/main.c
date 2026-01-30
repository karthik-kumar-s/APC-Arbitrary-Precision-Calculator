#include "apc.h"

/*
 * main
 * ----
 * Reads command line arguments, converts operands into doubly linked lists,
 * identifies operator, and calls the appropriate arithmetic function.
 */
int main(int argc, char *argv[])
{
    /* Head and tail pointers for operand 1 */
    node_t *head1 = NULL;
    node_t *tail1 = NULL;

    /* Head and tail pointers for operand 2 */
    node_t *head2 = NULL;
    node_t *tail2 = NULL;

    // Head and tail pointers for result 
    node_t *headR = NULL;
    node_t *tailR = NULL;

    int i;

    /* Validate command line arguments */
    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return 1;
    }

    /* ===============================
     * Convert Operand 1 into List
     * =============================== */
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        /* Validate digit */
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Invalid operand: %s\n", argv[1]);
            return 1;
        }

        insert_at_last(&head1, &tail1, argv[1][i] - '0');
    }

    /* ===============================
     * Convert Operand 2 into List
     * =============================== */
    for (i = 0; argv[3][i] != '\0'; i++)
    {
        /* Validate digit */
        if (argv[3][i] < '0' || argv[3][i] > '9')
        {
            printf("Invalid operand: %s\n", argv[3]);
            return 1;
        }

        insert_at_last(&head2, &tail2, argv[3][i] - '0');
    }

    /* ===============================
     * Operator Selection
     * =============================== */
    switch (argv[2][0])
    {
    case '+':
        addition(head1, tail1, head2, tail2, &headR, &tailR);
        print_list(headR);
        break;

    case '-':
    {
        int cmp = compare_list(head1, head2);

        if (cmp == 0)
        {
            /* Result is zero */
            printf("0");
        }
        else if (cmp > 0)
        {
            subtraction(head1, tail1, head2, tail2, &headR, &tailR, 0);
            print_list(headR);
        }
        else
        {
            subtraction(head2, tail2, head1, tail1, &headR, &tailR, 1);
            printf("-");
            print_list(headR);
        }
        break;
    }

    case 'x':
    case 'X':
        multiplication(head1, tail1, head2, tail2, &headR, &tailR);
        print_list(headR);
        break;

    case '/':
        division(head1, tail1, head2, tail2, &headR, &tailR);
        print_list(headR);
        break;

    default:
        printf("Invalid operator: %s\n", argv[2]);
        break;
    }

    printf("\n");

    /* ===============================
     * Free All Allocated Memory
     * =============================== */
    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return 0;
}
