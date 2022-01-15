#include <iostream>
using namespace std;

// 데이터를 저장할 노드 구조체
typedef struct Node {
    int data;   // 저장할 데이터
    Node* next; // 다음 데이터의 위치를 가리킬 노드 포인터
    Node* prev;
};

// 노드 구조체의 시작지점, 끝지점, 현재지점을 저장할 구조체
typedef struct LinkedList {
    // 시작노드의 주소값을 저장
    Node head;
    // 마지막 노드의 주소값을 저장
    Node tail;
};

LinkedList list;    // 링크드 리스트

void initLinkedList() {
    list.head.next = NULL;
    list.tail.next = NULL;
}

// 링크드 리스트에 새로운 값 저장
void createNodeToLast(int tdata) {
    // 데이터를 저장할 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = tdata;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(list.head.next==NULL && list.tail.next==NULL) {  // 노드가 하나도 없을 경우
        list.head.next = newNode;
        list.tail.next = newNode;
    } else {    // 기존에 노드가 존재할 경우
        Node* last = list.tail.next;    // 가장 마지막 노드 가져옴
        last->next = newNode;   // 기존 마지막 노드의 다음에 newNode 추가
        newNode->prev = last;
        list.tail.next = newNode;   // tail이 새로 추가된 newNode를 바라보도록 수정
    }
}

void deleteLastNode() {
    Node* first = list.head.next;
    Node* last = list.tail.next;

    // 노드가 하나도 존재하지 않을 경우
    if(first==NULL) return;

    // 노드가 1개 존재할 경우
    if(first==last) {
        free(first);
        list.head.next = NULL;
        list.head.prev = NULL;
        return;
    } else {    // 노드가 여러 개 존재할 경우
        // 마지막 노드 전까지 이동하여
        // 마지막 전전 노드가 마지막 노드가 되도록 null을 추가해야함
        Node* tempNode = first;
        while(tempNode->next->next!=NULL) tempNode = tempNode->next;
        tempNode->next = NULL;
        list.tail.next = tempNode;
        free(last);
    }
}

// 노드 출력
void printNodes() {
    Node* p = list.head.next;
    putchar('[');
    while(p!=NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }
    putchar(']');
    putchar('\n');
}

// 노드 출력 (역방향)
void reversePrintNodes() {
    Node* p = list.tail.next;
    putchar('[');
    while(p!=NULL) {
        printf("%d, ", p->data);
        p = p->prev;
    }
    putchar(']');
    putchar('\n');
}

int main() {
    initLinkedList();
    createNodeToLast(1);
    createNodeToLast(2);
    createNodeToLast(3);
    deleteLastNode();
    createNodeToLast(4);
    createNodeToLast(5);
    createNodeToLast(6);
    deleteLastNode();
    deleteLastNode();
    createNodeToLast(7);

    printNodes();
    reversePrintNodes();

    return 0;
}