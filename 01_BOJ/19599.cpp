#include <iostream>
#include <vector>
using namespace std;

vector<int> b, t;

int main() {
    int n;
    cin >> n;
    b.resize(n);
    t.resize(n);
    int r1=0, r2=0, r3=0;

    for(int i=0; i<n; i++) {
        int tar_idx = i;
        int left = 0, right = n-1;
        int count = 0;

        while(left<=right) {
            int mid = (left+right)/2;
            if(mid==tar_idx) {
                b[tar_idx] = count;
                break;
            }
            else if(tar_idx < mid) {
                right = mid-1;
            }
            else if(tar_idx > mid) {
                left = mid+1;
            }

            count++;
        }
    }

    for(int i=0; i<n; i++) {
        int tar_idx = i;
        int left = 0, right = n-1;
        int count = 0;

        while(left<=right) {
            int left_third = left + ((right-left)/3);
            int right_third = right - ((right-left)/3);

            if(left_third == tar_idx) {
                t[tar_idx] = count;
                break;
            }
            else if(right_third == tar_idx) {
                t[tar_idx] = count+1;
                break;
            }
            else if(tar_idx < left_third) {
                right = left_third-1;
                count+=2;
            }
            else if(tar_idx < right_third) {
                left = left_third+1;
                right = right_third-1;
                count+=2;
            }
            else  {
                left = right_third+1;
                count+=2;
            }
        }

        if(b[i] < t[i]) r1++;
        else if(b[i] == t[i]) r2++;
        else r3++;
    }


    printf("%d\n%d\n%d", r1,r2,r3);
    return 0;
}