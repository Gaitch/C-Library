/*
 *	interface to stack module
 *
 */

#include <stdint.h>   /* for standard integer types */

/* initializes (resets and clears) stack, mandatory after over- or underflow! */
void stack_init (void);

/* push character ('0'-'9','a'-'z','A'-'Z',' ') onto stack, push '*' if character is out of range */
void stack_push (char c);

/* takes topmost element from stack and returns it, returns '\0' in case of an error (overflow, underflow, not initialied) */
char stack_pop (void);

/* returns topmost element form stack, returns '\0' in case of an error */
char stack_peek (void);


