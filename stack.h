#include <stdio.h>
#include <stdlib.h>
struct stack
{
    unsigned capacity;
    int top;
    int *arr;
};
struct stack *createStack(int capacity)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->top = -1;
    temp->capacity = capacity;
    temp->arr = malloc(sizeof(int) * capacity);
    return temp;
}
void push(struct stack *userStack, int data)
{
    if (userStack->top == userStack->capacity - 1)
        printf("STACK OVERFLOW\n");
    else
    {
        userStack->top++;
        userStack->arr[userStack->top] = data;
    }
}
int pop(struct stack *userStack)
{
    if (userStack->top == -1)
    {
        printf("UNDREFLOW\n");
        return -69;
    }
    else
    {
        int temp = userStack->arr[userStack->top];
        userStack->top -= 1;
        return temp;
    }
}

int peep(struct stack *userStack)
{
    if (userStack->top == -1)
    {
        printf("UNDREFLOW\n");
        return -69;
    }
    else
    {
        int temp = userStack->arr[userStack->top];
        return temp;
    }
}
void change(struct stack *userStack, int pos, int value)
{
    if (userStack->top == -1)
        printf("UNDERFLOW\n");
    else
    {
        int index = userStack->top - pos + 1;
        //userStack->arr[index] = value;
        if (index > -1 && index <= userStack->top)
            userStack->arr[index] = value;
        else
            printf("INVALID INDEX\n");
    }
}
void display(struct stack *userStack)
{
    if (userStack->top == -1)
        printf("UNDERFLOW\n");
    else
    {
        for (int i = 0; i <= userStack->top; i++)
            printf("%d ", userStack->arr[i]);
    }
}
