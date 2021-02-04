#include <stdio.h>

int main() {
    int n, s, r;    // 팀의 수 N, 카약이 손상된 팀의 수 S, 카약을 하나 더 가져온 팀의 수 R
    int arr[12]={0,};
    int num;
    scanf("%d%d%d", &n, &s, &r);
    for(int i=0; i<s; i++) {
        scanf("%d", &num);
        arr[num]--;
    }
    for(int i=0; i<r; i++) {
        scanf("%d", &num);
        arr[num]++;
    }

    int count = 0;
    // 손상:-1, 유지:0, 여분:1
    for(int i=1; i<=n; i++) {
        if(arr[i]==-1) {
            if(arr[i-1]==1) {
                arr[i-1] = 0;
                arr[i] = 0;
            }
            else if(arr[i+1]==1) {
                arr[i+1] = 0;
                arr[i] = 0;
            }
            else count++;
        }
    }

    printf("%d", count);
    return 0;
}