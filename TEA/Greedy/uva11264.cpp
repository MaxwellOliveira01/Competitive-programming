#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        long long n,p,s=0; cin >> n;
        int coins[n];

        for(int i = 0; i < n; i++){
            cin >> coins[i];
        }

        s = coins[0];

        long long ans = 2;

        for(int i = 1; i < n-1; i++){
            if(s + coins[i] < coins[i+1]){
                ans++;
                s += coins[i];

            }

        }

        cout << ans << endl;
    }
}
