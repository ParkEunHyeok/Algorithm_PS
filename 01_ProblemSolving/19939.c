#include <stdio.h>

int main() {
    int n, k;   // 공의 개수, 팀의 수
    scanf("%d%d", &n, &k);

    int stair = 0;
    for(int i=1; i<=k; i++) {
        stair += i;
    }

    if(n < stair) {
        printf("-1");
    }
    else if(n==stair) {
        printf("%d", k-1);
    }
    else {
        n -= stair;
        if(n%k==0) printf("%d", k-1);
        else printf("%d", k);
    }

    return 0;
}