#include <stdio.h>

const int MAX = 12;
char stack[MAX];
int top = -1;

void push(char c) {
    if(top+1<MAX) top++;
    else {
        printf("stack overflow");
        return;
    }
    stack[top] = c;
}

void pop() {
    if(top!=-1) top--;
    else {
        printf("stack underflow");
        return;
    }
}

int empty() {
    if(top==-1) return 1;
    else return 0;
}

int main() {
    while(1) {
        char ch;
        scanf("%c", &ch);

        if(ch=='(') {
            push(ch);
        }
        else if(ch==')'){
            pop();
        }
        else {
            break;
        }
    }

    if(empty()) printf("옳은 괄호");
    else printf("틀린 괄호");

    return 0;
}