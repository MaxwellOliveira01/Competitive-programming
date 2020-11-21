#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long dp[30001];
    int moeda[] = {1,5,10,25,50};

    memset(dp,0,sizeof(dp));
    dp[0]++;

    for(int i = 0; i < 5; i++){
        for(int j = moeda[i]; j < 30001; j++){
            dp[j] += dp[j-moeda[i]];
        }
    }

    int n;

    while(cin >> n){
        if(dp[n] == 1) cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
    }

}
