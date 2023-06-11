#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a stack data structure
typedef struct {
    float items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize a stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to push an item onto the stack
void push(Stack *s, float value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(1);
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

// Function to pop an item from the stack
float pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: stack underflow\n");
        exit(1);
    } else {
        float value = s->items[s->top];
        s->top--;
        return value;
    }
}

int main() {
    char op;
    float operand, num1, num2, result;
    Stack s;

    // Initialize the stack
    initStack(&s);

    printf("Enter a math expression (use q to quit): ");
    while (scanf("%f", &operand) == 1) {
        push(&s, operand);

        scanf("%c", &op);
        if (op == 'q') {
            break;
        } else if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("Error: invalid operator\n");
            exit(1);
        }

        scanf("%f", &operand);
        push(&s, operand);

        // Perform the arithmetic operation using the top two items on the stack
        num2 = pop(&s);
        num1 = pop(&s);
        switch(op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: division by zero\n");
                    exit(1);
                }
                result = num1 / num2;
                break;
            default:
                printf("Error: invalid operator\n");
                exit(1);
        }
        push(&s, result);

        scanf("%c", &op);
    }

    // The final result is at the top of the stack
    result = pop(&s);
    printf("Result: %f\n", result);

    return 0;
}
