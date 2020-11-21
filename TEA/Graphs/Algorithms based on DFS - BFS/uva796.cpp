#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
using ll = long long;

using namespace std;

void bridge(vector<vi>& arr, int u, int &n, vector<pii>& ans, vector<pii>& est, vi& mark, vi& predecessor){

    est[u] = {n,n};
    n++;
    mark[u] = 1;

    for(auto v: arr[u]){
        if(mark[v] == 0){
            predecessor[v] = u;
            bridge(arr,v,n,ans,est,mark,predecessor);
            est[u].ss = min(est[u].ss, est[v].ss);

            if(est[v].ss > est[u].ff){
                if(u < v) ans.push_back({u,v});
                else ans.push_back({v,u});
            }
        }

        else if(v != predecessor[u])
            est[u].ss = min(est[u].ss,est[v].ff);

    }

}

void solve(vector<vi>& arr){
    int n = 0;

    vector<pii> ans;
    vector<pii> est(arr.size()); // {index,low}
    vector<int> mark(arr.size(),0); //0->branco e 1-> preto
    vector<int> predecessor(arr.size(),-1);

    for(int i = 0; i < arr.size(); i++)
        bridge(arr,i,n,ans,est,mark,predecessor);

    sort(ans.begin(),ans.end());

    cout << ans.size() << " critical links" << endl;

    for(auto x: ans)
        cout << x.ff << " - " << x.ss << endl;
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,ver,quant,no;
    char paren;
    while(cin >> n){
        vector< vi > arr(n, vi());
        for(int i = 0; i < n; i++){
            cin >> no >> paren >> quant >> paren;

            while(quant--){
                cin >> ver;
                arr[no].push_back(ver);
            }
        }
    solve(arr);

    }
}
