#include <stdio.h>
//벌집의 개수는 6개씩 늘어나는 등차수열
int main() {
    int n,i;
    int count =1;
    scanf("%d",&n);
    for(i=1; i<=n; i++) {
        count += (i-1)*6; //count에 6씩 늘어나는 값을 곱하여 최댓값 구함
        if(n<=count) break;// 구하면 빠져나감
    }
    printf("%d", i);
}