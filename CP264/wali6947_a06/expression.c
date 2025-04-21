#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/* 
* We will create a helper method for the precedence of the characters being pushed/popped
*/
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // Default for non-operators
}
/* 
 * Convert infix expression string to postfix expression represented by queue data structure. 
 * @param infixstr - string of infix expression. 
 * @return - postfix expression in queue of QUEUE type. 
*/
QUEUE infix_to_postfix(char *infixstr) {
    char *p = infixstr;
    QUEUE queue = {0};
    STACK stack = {0};
    int sign = 1, num = 0;

    while (*p) {
        if (*p == '-' && (p == infixstr || *(p - 1) == '(')) { // handling negative sign
            sign = -1;
        } 
        else if (mytype(*p) == 0) { // Operand (number)
            num = *p - '0';
            while (*(p + 1) >= '0' && *(p + 1) <= '9') {
                num = num * 10 + (*(p + 1) - '0');
                p++;
            }
            enqueue(&queue, new_node(sign * num, 0));
            sign = 1;
        } 
        else if (mytype(*p) == 1) { // Operator
            while (stack.top && precedence(stack.top->data) >= precedence(*p)) {
                enqueue(&queue, pop(&stack));
            }
            push(&stack, new_node(*p, 1));
        } 
        else if (mytype(*p) == 2) { // Left parenthesis '('
            push(&stack, new_node(*p, 2));
        } 
        else if (mytype(*p) == 3) { // Right parenthesis ')'
            while (stack.top && stack.top->data != '(') {
                enqueue(&queue, pop(&stack));
            }
            pop(&stack); // Remove '(' from stack
        }
        p++;
    }

    // Pop remaining operators from stack to queue
    while (stack.top) {
        enqueue(&queue, pop(&stack));
    }

    return queue;
}

/* 
 * Evaluate and return the value of postfix expression passed by queue.
 * @param queue - postfix expression in queue of QUEUE type.
 * @return - value of postfix expression.
 */
int evaluate_postfix(QUEUE queue) {
    NODE *p = queue.front;
    STACK stack = {0};
    int type = 0;

    while (p) {
        type = p->type;

        if (type == 0) { // Operand
            push(&stack, new_node(p->data, 0));
        } 
        else if (type == 1) { // Operator
            int operator = p->data;
            NODE *operand2 = pop(&stack);
            NODE *operand1 = pop(&stack);

            if (operator == '+') {
                push(&stack, new_node(operand1->data + operand2->data, 0));
            } 
            else if (operator == '-') {
                push(&stack, new_node(operand1->data - operand2->data, 0));
            } 
            else if (operator == '*') {
                push(&stack, new_node(operand1->data * operand2->data, 0));
            } 
            else if (operator == '/') {
                push(&stack, new_node(operand1->data / operand2->data, 0));
            }

            free(operand1);
            free(operand2);
        }
        p = p->next;
    }

    int result = stack.top->data;
    clean_stack(&stack);
    return result;
}

/* 
 * Evaluate and return the value of infix expression passed by string infixstr, 
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.  
 * @return - value of the infix expression.
 */
int evaluate_infix(char *infixstr) {
    QUEUE queue = infix_to_postfix(infixstr); // Store converted postfix expression
    return evaluate_postfix(queue); // Evaluate postfix expression
}