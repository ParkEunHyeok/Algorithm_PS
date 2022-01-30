#include <stdio.h>

int checked[1000001] = {0,};
char P[101];

// 에라토스테네스의 체
void primeNum() {
    checked[0] = 1;
    checked[1] = 1;

    for(int i=2; i<=1000000; i++) {
        if(checked[i]==1) continue;

        for(int j=2*i; j<=1000000; j+=i) {
            checked[j] = 1;
        }
    }
}

// P가 K 이하의 소수로 나누어지는지 확인
int rest(int num) {
    int sum = 0;
    for(int i=0; P[i]!=NULL; i++) {
        sum = (sum*10 + (P[i]-'0')) % num;
    }
    if(sum==0) return 1;
    else return 0;
}

int main() {
    primeNum();

    int k;
    int good = 1;
    scanf("%s %d", P, &k);
    
    int answer = 0;
    for(int i=2; i<k; i++) {
        if(checked[i]==1) continue;

        if(rest(i)==1) {
            answer = i;
            good = 0;
            break;
        }
    }

    if(good==1) printf("GOOD");
    else printf("BAD %d", answer);

    return 0;
}