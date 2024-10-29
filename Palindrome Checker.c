#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int top;
    char items[MAX];
} Stack;

// Queue structure
typedef struct Queue {
    int front, rear;
    char items[MAX];
} Queue;

// Stack functions
void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack is full.\n");
    } else {
        s->items[++s->top] = item;
    }
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return '\0';
    } else {
        return s->items[s->top--];
    }
}

// Queue functions
void enqueue(Queue *q, char item) {
    if (q->rear == MAX - 1) {
        printf("Queue is full.\n");
    } else {
        q->items[++q->rear] = item;
        if (q->front == -1) {
            q->front = 0;
        }
    }
}

char dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty.\n");
        return '\0';
    } else {
        return q->items[q->front++];
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    Stack s;
    Queue q;
    s.top = -1;
    q.front = -1;
    q.rear = -1;

    // Convert string to lowercase and remove non-alphanumeric characters
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            char ch = tolower(str[i]);
            push(&s, ch);
            enqueue(&q, ch);
        }
    }

    // Compare elements from stack and queue
    while (q.front <= q.rear) {
        if (pop(&s) != dequeue(&q)) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Main function to test the palindrome checker
int main() {
    char str[MAX];

    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
