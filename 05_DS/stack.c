#include <stdio.h>
#define MAX 30

typedef struct _ArrayStack {
    int top;
    int data[MAX];
}ArrayStack;

typedef ArrayStack Stack;

void Init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top==MAX-1;
}

void Push(Stack* s, int item) {
    if(isFull(s)) printf("stack empty die");
    else {
        s->top++;
        s->data[s->top] = item;
    }
}

int Peek(Stack* s) {
    int d;
    if(isEmpty(s)) {
        printf("stack full dis");
        return -1;
    }
    else {
        d = s->data[s->top];
        return d;
    }
}

int Pop(Stack* s) {
    int t = Peek(s);
    s->top--;
    return t;
}

void Display(Stack *s) {
    if(isEmpty(s)) printf("stack empty die");
    else {
        printf("bottom [ ");
        for(int i=0; i<=s->top; i++) {
            printf("%d ", s->data[i]);
        }
        printf(" ] top \n\n");
    }
}

int main() {
    Stack s1;
    Init(&s1);
    for(int i=1; i<=5; i++) {
        printf("Push(%d)\n", i);
        Push(&s1, i);
        Display(&s1);
    }

    printf("Pop() : %d\n", Pop(&s1));
    Display(&s1);

    printf("Pop() : %d\n", Pop(&s1));
    Display(&s1);

    printf("Pop() : %d\n", Pop(&s1));
    Display(&s1);

    printf("\n\n");
    return 0;
}