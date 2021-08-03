#include <iostream>
using namespace std;

int tree[27][2];

void preorder(int node) {
    if(node==-1) return;
    cout << (char)(node+'A');
    preorder(tree[node][0]);
    preorder(tree[node][1]);
}

void inorder(int node) {
    if(node==-1) return;
    inorder(tree[node][0]);
    cout << (char)(node+'A');
    inorder(tree[node][1]);
}

void postorder(int node) {
    if(node==-1) return;
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    cout << (char)(node+'A');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        if(b!='.') tree[a-'A'][0] = b-'A';
        else tree[a-'A'][0] = -1;

        if(c!='.') tree[a-'A'][1] = c-'A';
        else tree[a-'A'][1] = -1;
    }

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

    return 0;
}