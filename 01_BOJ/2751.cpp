/*
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
*/

#include <stdio.h>

int n;
int arr[1000001];
int *arr2;

void merge(int left, int right) {
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j]) arr2[k++] = arr[i++];
        else arr2[k++] = arr[j++];
    }

    int tmp = i>mid ? j : i;

    while(k<=right) arr2[k++] = arr[tmp++];

    for(int i=left; i<=right; i++) {
        arr[i] = arr2[i];
    }
}

void partition(int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;
        partition(left, mid);
        partition(mid+1, right);
        merge(left, right);
    }
}

int main() {
    scanf("%d", &n);
    arr2 = new int[n];

    for(int i=0; i<n; i++) {    
        scanf("%d", &arr[i]);
    }

    partition(0, n-1);

    for(int i=0; i<n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}