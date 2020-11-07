#include <stdio.h>

int arr[1000000];

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quick_sort(int arr[], int start, int end) {
    int left = start;
    int right = end;
    int pivot = arr[(left+right)/2];

    while(left <= right) {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        if(left <= right) {
            swap(arr, left, right);
            left++;
            right--;
        }
    }

    if(start < right) quick_sort(arr, start, right);
    if(left < end) quick_sort(arr, left, end); 

    return;
}

int main() {
    int n;
    
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        printf("%d\n",arr[i]);
    }

    return 0;
}