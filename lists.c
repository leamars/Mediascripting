#include <stdio.h>

#define MaxStack  50  /* MaxStack stands for the size of all stack arrays */

typedef struct {
    int topPosition;
    char * stackArray [MaxStack];
} stringStack;      /* type for a stack of strings */

int full (stringStack stack);
int push (stringStack *stack, char * item);
void initializeStack (stringStack * stack);
int empty (stringStack stack);
char * pop (stringStack *stack);
char * top (stringStack stack);
int size (stringStack stack);
char * get_nth (stringStack stack, int nth);
void print (stringStack stack);

int main (void)

{
    stringStack bills, magazines, notes;
    
    initializeStack (&bills);
    initializeStack (&magazines);
    initializeStack (&notes);
    
    
    push (&bills, "Mortgage");
    push (&bills, "Doctor's Bill");
    push (&bills, "Credit Card");
    
    printf ("Bills : %d", empty (bills));
    
    printf ("\nMagazines : %d\n", empty (magazines));
    
    push (&magazines, "Communications of the ACM - March 2009");
    push (&magazines, "CS Education Bulletin - Spring 2009");
     
    printf ("Bills:\n");
    
    print (bills);
    
    printf ("Magazines:\n");
    
    print (magazines);
    
    printf ("Notes:\n");
    
    print (notes);
    
    printf ("\n%s\n", pop (&bills));
    
    printf ("%s", pop (&bills));
    
    printf ("\n\n%s\n", pop (&magazines));
    
    printf ("%s", pop (&magazines));
    
    printf ("\n\nBills : %d", empty (bills));
    
    printf ("\nMagazines : %d", empty (magazines));
    
    push (&bills, "Mortgage");
    push (&bills, "Doctor's Bill");
    
    printf ("\n\nBills : %d", size (bills));
    
    printf ("\n\nBills : %s", get_nth (bills, 1));
    
  return 0;

}

int full (stringStack stack)

{
    /* determine if there are more positions in a stackArray */
    return (stack.topPosition == (MaxStack-1));
}

int push (stringStack *stack, char * item)

{
    /* return -1 if stack full */
    if (full (*stack)) {
        printf ("attempt to push item onto an already full stack\n");
        return -1;
    }
    
    /* add item to stack */
    (stack->topPosition) ++;
    stack->stackArray[stack->topPosition] = item;
    
}

void initializeStack (stringStack * stack)  /* (sets topPosition of stack to -1) */

{
    stack->topPosition = -1;
}

int empty (stringStack stack)

{
    return (stack.topPosition < 0);
}

char * pop (stringStack *stack)
/* (returns 0 if stack is empty, otherwise removes the top string from the                                                      stack and returns it) */
{
    char * top;
    
    if (empty (* stack))
    {
        return 0;
    }
    else
        
        top = stack->stackArray[stack->topPosition];
    
        (stack->topPosition) --;
        
    return top;
}


char * top (stringStack stack)
/* (returns 0 if stack is empty, otherwise returns the top string on the stack) */
{
    if (empty (stack))
    {
        return 0;
    }
    
    return stack.stackArray[stack.topPosition];
    
}

int size (stringStack stack)
/* returns the number of items currently on the stack */

{
    return (stack.topPosition + 1);
}

void print (stringStack stack)
/* prints all of the current elements on the stack */

{
    while ((top (stack)) != NULL)
    {
        printf ("\t%s\n", pop (&stack));
    }
}

char * get_nth (stringStack stack, int nth)
/* returns the string at the nth position from the top of the stack */

{
    int max;
    
    max = stack.topPosition;
    
    if (nth < MaxStack && nth >= 0)
        
    {
        return stack.stackArray[max - nth];
    }
}
