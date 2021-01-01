#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);

        if(num) {
            pq.push(make_pair(abs(num), num));
        }
        else {
            if(pq.empty()) {
                printf("0\n");
            }
            else {
                printf("%d\n", pq.top().second);
                pq.pop();
            }
        }
    }

    return 0;
}