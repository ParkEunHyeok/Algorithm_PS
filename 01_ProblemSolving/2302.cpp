#include <stdio.h>

int main(void)
{
    int M,N,x,mid=0,ans=1;
    int arr[41] = {};
    arr[0] = 1, arr[1] = 1;//3:3, 4:5

    scanf("%d%d",&M,&N);
    for(int i=2; i<=M; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d", &x);
        ans *= arr[x-1-mid];
        mid = x;
    }
    ans *= arr[M-mid];
    printf("%d",ans);

    return 0;
}