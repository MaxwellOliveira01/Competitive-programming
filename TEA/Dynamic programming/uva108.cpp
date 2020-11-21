#include <bits/stdc++.h>
#define vii vector<int>
using namespace std;

vector<vii> s(101,vii(101,0)), m(101,vii(101,0));
int n;

void preprocess(){
    s[0][0] = m[0][0];

    for(int j = 1; j < n; j++) s[0][j] = s[0][j-1] + m[0][j-1];

    for(int i = 1; i < n; i++) s[i][0] = s[i-1][0] + m[i][0];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + m[i][j];


}

int sum(int i, int j, int ii, int jj){
    if(jj == 0 || i == 0) return s[ii][jj];
    return s[ii][jj]-s[i-1][jj]-s[ii][j-1]+s[i-1][j-1];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int re,ans = -1000000;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }

    preprocess();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int ii = i; ii < n; ii++)
                for(int jj = j; jj < n; jj++)
                    ans = max(ans,sum(i,j,ii,jj));


    cout << ans << endl;

}
