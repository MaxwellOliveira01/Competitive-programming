#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
using ll = long long;

using namespace std;

void AP(vector<vi>& arr, int u, int &n, vi& ans, vector<pii>& est, vi& mark, vi& predecessor){

    est[u] = {n,n};
    n++;
    mark[u] = 1;
    int f = 0;

    for(auto v: arr[u]){
        if(mark[v] == 0){
            predecessor[v] = u;

            if(predecessor[u] == -1)
                f++;

            AP(arr,v,n,ans,est,mark,predecessor);
            est[u].ss = min(est[u].ss, est[v].ss);

            if(est[v].ss >= est[u].ff){
                ans[u] = 1;
            }
        }

        else if(v != predecessor[u])
            est[u].ss = min(est[u].ss,est[v].ff);

    }

    if(predecessor[u] == -1)
        ans[u] = (f>1);

}

void solve(vector<vi>& arr){
    int n = 0,cont=0;

    vector<pii> est(arr.size()); // {index,low}
    vector<int> ans(arr.size()+1,0);
    vector<int> mark(arr.size(),0); //0->branco e 1-> preto
    vector<int> predecessor(arr.size(),-1);

    for(int i = 0; i < arr.size(); i++)
        AP(arr,i,n,ans,est,mark,predecessor);

    for(auto x: ans)
        cont+=x;

    cout << cont << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,ver,no;
    string re;
    while(cin >> n, n){

        vector<vi> arr(n+1, vi());

        while(cin >> ver, ver){
            getline(cin,re);
            stringstream ss(re);

            while(ss >> no){
                arr[ver].push_back(no);
                arr[no].push_back(ver);
            }
        }

        solve(arr);
    }
}
