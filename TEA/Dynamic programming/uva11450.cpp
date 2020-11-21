#include <bits/stdc++.h>
#define INF 1e5
using namespace std;
int m,c;
vector< vector<int> > prices(21,vector<int>());
int dp[21][201];

int solve(int current, int i){
    if(current < 0) return -INF;
    if(i < 0 && current >= 0) return m-current;

    if(dp[i][current] >= 0) return dp[i][current];

    int ans = -INF;

    for(int j = 0; j < prices[i].size(); j++){
        ans = max(ans,solve(current-prices[i][j],i-1));
    }

    dp[i][current] = ans;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,k,re;
    cin >> t;

    while(t--){
        cin >> m >> c;

        prices.assign(21,vector<int>());
        for(int i = 0; i < 21; i++)
            for(int j = 0; j < 201; j++)
                dp[i][j] = -1;


        for(int i = 0; i < c; i++){
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> re;
                prices[i].push_back(re);
            }
        }


        solve(m,c-1);


        dp[c-1][m] == -INF ? cout << "no solution" << endl : cout << dp[c-1][m] << endl;

    }
}
