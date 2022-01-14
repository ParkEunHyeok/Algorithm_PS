#include <stdio.h>
#define MAX 20

// Node 구조체
typedef struct node{
    char name;
    struct node *left;
    struct node *right;
}node;

node input[MAX];
int index = 0;  // 다음 노드가 들어갈 자리

// char를 받아서 다음 노드 생성
void next(char data) {
    int count = 0;
    while(input[count].name != NULL) {
        if(input[count].left==NULL) {   // left 노드에 생성
            input[index].name = data;
            input[count].left = &input[index];
            index++;
            return;
        }
        else if(input[count].right==NULL) { // right 노드에 생성
            input[index].name = data;
            input[count].right = &input[index];
            index++;
            return;
        } else {    // 다음 노드로 이동
            count++;
        }
    }

    // 현재 노드가 비어있다면 (첫 번째 노드인 경우)
    if(input[count].name==NULL) input[index++].name = data;
}

// 전위 순회
void preorder(node *root) {
    if(root!=NULL) {
        printf("%c ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 순회
void inorder(node *root) {
    if(root!=NULL) {
        preorder(root->left);
        printf("%c ", root->name);
        preorder(root->right);
    }
}

// 후위 순회
void postorder(node *root) {
    if(root!=NULL) {
        preorder(root->left);
        preorder(root->right);
        printf("%c ", root->name);
    }
}

void print() {
    // 만들어진 이진 트리 출력
    int n = 2;
    while(n < MAX) {
        for(int i=n/2-1; i<n-1; i++) {
            printf("%c ", input[i].name);
        }
        printf("\n");
        n *= 2;
    }
}

int main() {
    int number;
    scanf("%d\n", &number);

    char data[MAX];
    gets(data);

    for(int i=0; i<number; i++) {
        next(data[i]);
    }

    print();
    printf("\n");
    preorder(&input[0]);
    printf("\n");
    inorder(&input[0]);
    printf("\n");
    postorder(&input[0]);
}