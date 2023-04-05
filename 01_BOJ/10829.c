#include <stdio.h>

long long n;
int arr[100];
int cnt = 0;

void func() {
    if(n==0) return;

    arr[cnt++] = n%2;
    n /= 2;

    func();
}

int main() {
    scanf("%lld", &n);

    func();

    for(int i=cnt-1; i>=0; i--) printf("%d", arr[i]);

    return 0;
}