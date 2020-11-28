#include <stdio.h>

int main() {
    int num = 1;
    while(1) {
        int l, p, v;
        scanf("%d %d %d", &l, &p, &v);
        if(l==0 && p==0 && v==0) break;
        else {
            int result = 0;
            while(v/p) {
                v -= p;
                result += l;
            }
            if(l<v) result += l;
            else result += v;
            printf("Case %d: %d\n", num, result);
        }
        num++;
    }
    return 0;
}