#include <stdio.h>

int round, kim, lim;
int count=0;

/*
void dfs() {
    for(int i=1; i<round; i+=2) {
        if(arr[i]==1 && arr[i+1]==1) {
            printf("%d", count);
            return;
        }
        else if(arr[i]==1 || arr[i+1]==1) {
            arr[i/2+1] = 1;
        }
        else arr[i/2+1] = 0;
    }
    if(round%2==1) arr[round/2+1] = arr[round];
    round /= 2;
    count++;
    dfs();
}
*/

int main() {
    scanf("%d%d%d", &round, &kim, &lim);

    while(kim!=lim) {
        kim = (kim+1)/2;
        lim = (lim+1)/2;
        count++;
    }
    printf("%d", count);

    return 0;
}