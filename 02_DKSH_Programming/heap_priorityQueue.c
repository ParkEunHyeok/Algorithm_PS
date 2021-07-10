#include <stdio.h>
#define MAX 300    // 힙의 최대 크기

int heap[MAX];  // 배열을 사용하여 힙 구현
int n = 0;    // 힙에 들어온 노드 개수, 배열 인덱스

// 우선순위 큐에 새로운 노드를 넣음
void push(int num, int idx) {
    int i = idx;    // 배열 인덱스

    while(i!=1 && num < heap[i/2]) {
        // 자식노드가 부모노드보다 작다면
        // 자식노드 자리로 부모노드를 옮김.
        heap[i] = heap[i/2];

        // 어느 부모노드의 인덱스가 i라고 하면
        // 그의 왼쪽 자식노드의 인덱스는 i*2
        // 그러므로 어느 왼쪽 자식노드의 부모노드는 i/2

        i /= 2; // 자식노드의 인덱스를 부모노드 자리로 옮김.
    }
    heap[i] = num;  // 추가한 num이 제 자리를 찾아감.
}

// 우선순위 큐에서의 pop : 가장 우선순위가 높은 데이터를 빼냄.
void pop() {
    int i = 1;  // 부모 노드에서 출발
    printf("%d ", heap[1]); // 루트 노드 pop, 출력
    heap[1] = heap[n];  // 가장 마지막 노드를 루트 노드로
    n--;    // 노드를 하나 삭제했으므로 n 감소

    while((2*i)+1 <= n) {  // 인덱스가 최하위 노드가 아니면 진행
        int parent = heap[i];
        int left = heap[i*2];
        int right = heap[(i*2)+1];

        if(parent < left && parent < right) {
            // 부모 노드가 자식 노드들보다 작을 때
            // 더이상 트리를 바꿀 필요 없으므로 break
            break;
        }
        else if(parent > left && left < right) {
            // 부모 노드가 더 크고,
            // 왼쪽 자식 노드와 교환할 때
            int temp = parent;
            parent = left;
            left = temp;

            heap[i] = parent;
            heap[i*2] = left;
            heap[(i*2)+1] = right;
            i = i*2;
        }
        else if(parent > right && right < left) {
            // 부모 노드가 더 크고,
            // 오른쪽 자식 노드와 교환할 때
            int temp = parent;
            parent = right;
            right = temp;

            heap[i] = parent;
            heap[i*2] = left;
            heap[(i*2)+1] = right;
            i = (i*2)+1;
        }
    }
}

int main() {
    int cnt = n;

    // 숫자 입력받고 힙에 삽입
    while(1) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp==-1) break;
        push(tmp, ++n);
    }

    // 힙을 순서대로 출력
    for(int i=1; i<=cnt; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");

    // pop 실행
    for(int i=1; i<=cnt; i++) {
        pop();
    }

    return 0;
}