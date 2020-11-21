#include <bits/stdc++.h>
using namespace std;
long dp[21][501],n;

long solve(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    long cont = 0,contB = 0;

    if(i >= j){
        for(int k = i+1; k <= n; k++)
            cont = max(cont,solve(k,1)+solve(k,j));
        for(int k = 1; k < j; k++)
            contB = max(contB,solve(i,k)+solve(n,k));

        if(i == n) cont = 0;
        if(j == 0) contB = 0;

        dp[i][j] = cont+contB;

    }

    else{
        for(int k = i; k < j; k++)
            cont = max(cont,solve(i,k)+solve(k+1,j));
        dp[i][j] = cont;
    }

    return dp[i][j];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans,an;

    while(cin >> n >> an){

        for(int i = 0; i < 21; i++)
            for(int j = 0; j < 501; j++)
                dp[i][j] = -1;

        dp[n][1] = an;
        solve(1,n);

        cout << dp[1][n] << endl;
    }

}
