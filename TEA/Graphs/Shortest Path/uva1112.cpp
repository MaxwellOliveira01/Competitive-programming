#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
#define INF 1e9
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;

    while(q--){
        int n,e,t,m,a,b,c,ans = 0;
        cin >> n >> e >> t >> m;

        vector<vi> arr(n, vi(n, INF));

        for(int i = 0; i < n; i++)
            arr[i][i] = 0;

        while(m--){
            cin >> a >> b >> c;
            arr[a-1][b-1] = c;
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);

        for(int i = 0; i < n; i++)
            if(arr[i][e-1] <= t)
                ans++;

        cout << ans << endl;

        if(q) cout << endl;

    }
}
