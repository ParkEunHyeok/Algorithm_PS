#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<bool> v;
    v.push_back(true); //1
    v.push_back(false); //2
    v.push_back(true); //3
    v.push_back(true); //4
    cin >> n;
    
    for(int i=4; i<n; i++) {
        if(!v[i-1] || !v[i-3] || !v[i-4]) {
            v.push_back(true);
        }
        else v.push_back(false);
    }

    if(v[n-1]==1) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }
    return 0;
}