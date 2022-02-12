#include <iostream>
#define MAX_SIZE 100002
using namespace std;

int heap[MAX_SIZE];
int cnt = 0;

void push(int node) {
    if(cnt==MAX_SIZE) {
        cout << "데이터를 추가할 공간이 없습니다." << "\n";
        return;
    }

    heap[cnt] = node;

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

void pop() {
    if(cnt==0) {
        cout << "0" << "\n";
        return;
    }

    int result = heap[0];
    heap[0] = heap[cnt-1];

    int current = 0;
    int child = (current*2)+1;

    while(child<cnt) {
        if((heap[child] < heap[child+1])&&((child+1)<cnt)) child ++;

        if(heap[current] < heap[child]) {
            swap(heap[current], heap[child]);
        } else break;
        current = child;
        child = (current*2)+1;
    }
    cnt--;
    cout << result << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp==0) pop();
        else push(tmp);
    }

    return 0;
}