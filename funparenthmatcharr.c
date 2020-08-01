#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

//just pass as local stack since we're not changing anything
void display(struct Stack st)
{
    //display from top of stack (end of array)
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]); //s ptr is pts to array and arrays are addr
    printf("\n");
}

//need a ptr because we are changing the stack
void push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
        printf("The Stack is Full");
    else
    {
        st->top++;          //increase top ptr
        st->s[st->top] = x; //add x to top of stack
    }
}

//need a ptr because we are changing the stack
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("The Stack is Empty");
    else
    {
        x = st->s[st->top]; // save top var
        st->top--;          //decrease top ptr
    }
    return x;
}

int stackTop(struct Stack st)
{
    if (st.top == -1)
        return -1;
    else
        return st.s[st.top];
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}

//peek down into stack
int peek(struct Stack st, int pos)
{

    int x = -1;
    if (st.top - pos + 1 <= 0) //from top peak down to pos
        printf("Invalid Position");
    else
        x = st.s[st.top - pos + 1];
    return x;
}

int isBalanced(char *exp)
{
    //need to create a stack here for the test
    struct Stack st;
    st.top = -1;
    st.size = strlen(exp);
    st.s = (char *)malloc(st.size * sizeof(char));

    //iterate until null terminator
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        { //opening push it
            push(&st, exp[i]);
            printf("pushed %c\n", exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(st))
                return 0;
            char x = (char)pop(&st); //pop it covert to char from int
            printf("popped %c\n", x);
            //check if it closes the same kind of char on current stack
            // if it doesn't then no match return 0
            if (!((x == '{' && exp[i] == '}') || (x == '(' && exp[i] == ')') || (x == '[' && exp[i] == ']')))
            {
                return 0;
            }
        }
    }
    return isEmpty(st) ? 1 : 0; //if true return 1, else 0
}

int reprompt()
{
    int fixin, input, ret = 0;
    //check valid size
    while (ret != 1 || input > 11 || input < 1)
    {
        printf("Enter a valid size: ");
        while ((fixin = getchar()) != EOF && fixin != '\n')
            ; // fix stdin
        fflush(stdin);
        ret = scanf("%d", &input);
    }
    return input;
}

void resolve(char *infix)
{
    //Here we use our stack structure to test for balance in parenth
    printf("Checking the parenthesis on this equation: %s", infix);
    printf("\n");
    //check if balanced statment
    if (isBalanced(infix))
        printf("This is a balanced infix problem.\n");
    else
        printf("It is not a balanced infix problem.\n");
    printf("Press Any Key to Continue: ");
    getchar();
    getchar();
    fflush(stdin);
    printf("\n");
}

int main()
{
    printf("Welcome to the parenthesis checking program.\n");
    printf("Use a linked list stack to check if parenthesis are balanced.\n");

    int ret, input;
    //prompt user to choose an equation
    do
    {
        printf("\nBelow are some simple infix math equations.\n");
        printf("Parenthesis can be a pain to look at.\n");
        printf("Let the program check to see if the parenthesis are balanced.\n");
        printf("1.  (8 + (3 * 9) - 6)\n");
        printf("2.  (5 * ((4) / (9)) + 1)\n");
        printf("3.  ((6 + 6) + (7 * (2))\n");
        printf("4.  (8 / (2)) / ((2) + 9) \n");
        printf("5.  ((2) * (2) * 2) / (2 + 2 + 2)\n");
        printf("6.  (7 / 3) * (2) + ((5 / (2)))\n");
        printf("7.  ((3) * (9 + 3) / ((3 + 3)\n");
        printf("8.  ((4) * (4) * (4)) / ((4) + (8))\n");
        printf("9.  (9 / 1 / 1) + (9 / 9))\n");
        printf("10.  (9 + 8) + ((7) / 6) - ((5) + (4) + 3))\n");
        printf("11. Exit Program.\n");

        //validate
        printf("\nEnter your choice: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 11 || input < 1)
            input = reprompt();

        //set the infix string
        switch (input)
        {
        case 1:
            printf("\n");
            char *infix1 = "(8 + (3 * 9) - 6)";
            resolve(infix1);
            break;
        case 2:
            printf("\n");
            char *infix2 = "(5 * ((4) / (9)) + 1)";
            resolve(infix2);
            break;
        case 3:
            printf("\n");
            char *infix3 = "((6 + 6) + (7 * (2))";
            resolve(infix3);
            break;
        case 4:
            printf("\n");
            char *infix4 = "(8 / (2)) / ((2) + 9)";
            resolve(infix4);
            break;
        case 5:
            printf("/n");
            char *infix5 = "((2) * (2) * 2) / (2 + 2 + 2)";
            resolve(infix5);
            break;
        case 6:
            printf("\n");
            char *infix6 = "(7 / 3) * (2) + ((5 / (2)))";
            resolve(infix6);
            break;
        case 7:
            printf("\n");
            char *infix7 = "((3) * (9 + 3) / ((3 + 3)";
            resolve(infix7);
            break;
        case 8:
            printf("\n");
            char *infix8 = "((4) * (4) * (4)) / ((4) + (8))";
            resolve(infix8);
            break;
        case 9:
            printf("\n");
            char *infix9 = "(9 / 1 / 1) + (9 / 9))";
            resolve(infix9);
            break;
        case 10:
            printf("\n");
            char *infix10 = "(9 + 8) + ((7) / 6) - ((5) + (4) + 3))";
            resolve(infix10);
            break;
        case 11:
            printf("Exiting Program\n");
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    } while (input != 11);

    return 0;
}
