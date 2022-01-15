#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int> > pq;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int number;
        scanf("%d", &number);

        if(number==0) { // pop
            if(!pq.empty()) {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else {
                printf("0\n");
            }
        }
        else {  // push
            pq.push(number);
        }
    }

    return 0;
}