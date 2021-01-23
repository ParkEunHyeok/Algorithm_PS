#include <iostream>
#include <string>
using namespace std;

int L, C;   // 암호 자릿수, 문자 개수
int alpha[26];
int c[17];
int visit[17];
int arr[17];

void dfs(int idx, int cnt, int mo, int za) {
    if(cnt==L) {
        if(mo>=1 && za>=2) {
            for(int i=0; i<L; i++) {
                printf("%c", arr[i]+'a');
            }
            printf("\n");
        }
        return;
    }
    if(idx==C) return;

    for(int i=idx; i<C; i++) {
        if(visit[i]==0) {
            visit[i] = 1;

            if(c[i]==0 || c[i]==4 || c[i]==8 || c[i]==14 || c[i]==20) {
                arr[cnt] = c[i];
                dfs(i+1, cnt+1, mo+1, za);
            }
            else {
                arr[cnt] = c[i];
                dfs(i+1, cnt+1, mo, za+1);
            }

            visit[i] = 0;
        }
    }
    return;
}

int main() {
    cin >> L >> C;
    for(int i=0; i<C; i++) {
        string str;
        cin >> str;
        alpha[str[0]-'a'] = 1;
    }
    
    int idx=0;
    for(int i=0; i<26; i++) {
        if(alpha[i]!=0) {
            c[idx++] = i;
        }
    }

    dfs(0,0,0,0);
    return 0;
}