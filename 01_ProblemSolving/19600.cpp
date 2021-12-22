#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;

    while(q--) {
        int n, s, e;
        cin >> n >> s >> e;

        int b[n]={0,};
        int t[n]={0,};
        int res_b[n]={0,};
        int res_t[n]={0,};

        for(int i=s; i<=e; i++) {
            int tar_idx = i;
            int left = 0, right = n-1;
            int count = 0;

            while(left<=right) {
                if(b[tar_idx]!=0) break;

                int mid = (left+right)/2;
                b[mid] = count;
                
                if(mid==tar_idx) {
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

            if(i==0) {
                res_b[0] = b[0];
                continue;
            }
            res_b[i] = b[i] + res_b[i-1];
        }

        for(int i=s; i<=e; i++) {
            int tar_idx = i;
            int left = 0, right = n-1;
            int count = 0;

            while(left<=right) {
                if(t[tar_idx]!=0) break;

                int left_third = left + ((right-left)/3);
                int right_third = right - ((right-left)/3);
                t[right_third] = count+1;
                t[left_third] = count;

                if(left_third == tar_idx) {
                    //t[tar_idx] = count;
                    break;
                }
                else if(right_third == tar_idx) {
                    //t[tar_idx] = count+1;
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

            if(i==0) {
                res_t[0] = t[0];
                continue;
            }
            res_t[i] = t[i] + res_t[i-1];
        }

        cout << (res_t[e]-res_b[e]) << "\n";
    }

    return 0;
}