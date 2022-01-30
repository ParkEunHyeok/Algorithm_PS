#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[4];
int n;
int Mresult = -1100000000, mresult = 1100000000;

void backtracking(int depth, int num, int add, int sub, int mul, int div) {
    if(depth==n) {
        Mresult = max(Mresult, num);
        mresult = min(mresult, num);
    }

    if(add>0) {
        backtracking(depth+1,num+v[depth],add-1,sub,mul,div);
    }
    if(sub>0) {
        backtracking(depth+1,num-v[depth],add,sub-1,mul,div);
    }
    if(mul>0) {
        backtracking(depth+1,num*v[depth],add,sub,mul-1,div);
    }
    if(div>0) {
        backtracking(depth+1,num/v[depth],add,sub,mul,div-1);
    }
}

int main() {
    cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    for(int i=0; i<4; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<4; i++) {
        backtracking(1,v[0],arr[0],arr[1],arr[2],arr[3]);
    }

    cout << Mresult << "\n" << mresult;
    return 0;
}