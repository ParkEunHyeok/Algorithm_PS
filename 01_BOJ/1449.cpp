#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, l;   // 물 새는 곳의 개수, 테이프의 길이
    int arr[1001];
    int tape[1001] = {0,};
    scanf("%d%d", &n, &l);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);
    int result = 0;
    for(int i=0; i<n; i++) {
        if(!tape[arr[i]]) {
            int end_point = min(1001, arr[i]+l);
            for(int j=arr[i]; j<end_point; j++) {
                tape[j]++;
            }
            result++;
        }
    }

    printf("%d", result);
    return 0;
}