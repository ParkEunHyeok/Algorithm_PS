#include <iostream>
using namespace std;

int preorder[1001];
int inorder[1001];

void tree(int root, int left, int right) {
    for(int i=left; i<right; i++) {
        if(preorder[root]==inorder[i]) {
            tree(root+1, left, i);
            tree(root+i+1-left, i+1, right);
            cout << preorder[root] << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i=0; i<n; i++) cin >> preorder[i];
        for(int i=0; i<n; i++) cin >> inorder[i];

        tree(0,0,n);
        cout << "\n";
    }

    return 0;
}