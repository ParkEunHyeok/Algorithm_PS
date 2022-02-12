#include <iostream>
#define MAX_SIZE 100002
using namespace std;

/*
    priority_queue<int> q;  // 내림차순
    priority_queue<int, vector<int>, less<int>> q;  // 내림차순
    priority_queue<int, vector<int>, greater<int>> q;   // 오름차순
*/

int heap[MAX_SIZE] = {0,};
int cnt = 0;    // 힙에 추가한 데이터 개수

// 힙 자료구조에 데이터 추가
void push(int node) {
    if(cnt==MAX_SIZE) {
        cout << "데이터를 추가할 공간이 없습니다." << endl;
        return;
    }

    heap[cnt] = node;

    // 추가한 노드를 기점으로 부모가 값이 더 작으면 위치를 바꿔줌
    int current = cnt;
    int root = (cnt-1)/2;
    while(current!=0) {
        if(heap[current] > heap[root]) {
            swap(heap[current], heap[root]);
        } else break;
        current = root;
        root = (current-1)/2;
    }
    cnt++;
}

// 힙 자료구조에서 데이터 꺼내기
int pop() {
    if(cnt==0) {
        cout << "데이터가 없습니다" << endl;
        return -1;
    }

    // 가장 우선순위가 높은 데이터 반환
    int result = heap[0];
    heap[0] = heap[cnt-1];  // 가장 마지막에 있는 데이터를 root로 올림

    int current = 0;
    int child = (current*2)+1;  // 왼쪽 자식 선택

    while(child<cnt) {
        // 배열 범위 벗어나는지 확인. 왼쪽 자식보다 오른쪽 자식이 더 크면, 더 큰 자식을 선택함
        if((heap[child] < heap[child+1])&&((child+1)<cnt)) child ++;

        if(heap[current] < heap[child]) {
            swap(heap[current], heap[child]);
        } else break;
        current = child;
        child = (current*2)+1;
    }
    cnt--;
    return result;
}

void print() {
    cout << "\n\n";
    for(int i=0; i<cnt; i++) {
        cout << heap[i] << " ";
    }
}

int main() {
    for(int i=0; i<MAX_SIZE; i++) {
        push(i);
    }

    print();
    cout << " - pop result : " << pop();
    print();
    cout << " - pop result : " << pop();
    print();
    cout << " - pop result : " << pop();
    print();
    cout << " - pop result : " << pop();
    print();
    cout << " - pop result : " << pop();
    
    print();

    return 0;
}