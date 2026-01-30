#ifndef APC_H
#define APC_H

/* =========================
 *  Standard Header Files
 * ========================= */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================
 *  User Defined Headers
 * ========================= */
#include "list.h"

/* =========================
 *  Arithmetic Function Prototypes
 * ========================= */

/* 
Addition of two arbitrary precision numbers 
*/
void addition(node_t *head1, node_t *tail1,
              node_t *head2, node_t *tail2,
              node_t **headR, node_t **tailR);

/* 
Subtraction using compare_list 
*/
void subtraction(node_t *head1, node_t *tail1,
                 node_t *head2, node_t *tail2,
                 node_t **headR, node_t **tailR,
                 int sign);

/* Multiplication using partial products */
void multiplication(node_t *head1, node_t *tail1,
                    node_t *head2, node_t *tail2,
                    node_t **headR, node_t **tailR);

/* Division using repeated subtraction */
void division(node_t *head1, node_t *tail1,
              node_t *head2, node_t *tail2,
              node_t **headR, node_t **tailR);

/* =========================
 *  Utility / Helper Functions
 * ========================= */

/* Compare two linked list numbers
 * Returns:
 *   1  → operand1 > operand2
 *   0  → operand1 == operand2
 *  -1  → operand1 < operand2
 */
int compare_list(node_t *head1, node_t *head2);

#endif /* APC_H */
