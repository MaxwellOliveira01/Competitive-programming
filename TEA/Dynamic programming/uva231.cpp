#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,first,ans,teste=1;
    while(cin >> first, first != -1){

        vector<int> arr;
        ans = 1;

        arr.push_back(first);

        while(cin >> n, n != -1) arr.push_back(n);

        int dp[arr.size()];
        for(int i = 0; i < arr.size(); i++) dp[i] = 1;

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                if(arr[i] <= arr[j])
                    dp[i] = max(dp[i],1+dp[j]);
            }

            ans = max(ans, dp[i]);

        }

        if(teste != 1) cout << endl;

        cout << "Test #" << teste++ << ":" << endl;
        cout << "  maximum possible interceptions: " << ans << endl;


    }
}
