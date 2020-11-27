#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue<int> q;
    cin >> n >> k;
    
    if(n==1) {
        printf("<1>");
        return 0;
    }

    for(int i=1; i<=n; i++) {
        q.push(i);
    }

    int count = 0, escaped = 0;
    printf("<");
    while(1) {
        count++;
        if(count==k) {
            // 만약 카운트가 K번째 값이면 출력해주고 pop
            count = 0;
            escaped++;
            printf("%d, ", q.front());
            q.pop();
        } else {
            // 만약 카운트가 K번째가 아니면 front를 back으로 넣어줌.
            q.push(q.front());
            q.pop();
        }
        if(escaped==n-1) {
            // 만약 큐에 숫자가 하나 남는다면 출력하고 무한루프 탈출
            printf("%d>", q.front());
            break;
        }
    }

    return 0;
}