#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
#define INF 1e9
using namespace std;

int bellman(vector< vector<pii> >& arr){
    vector<int> dist(arr.size(), INF);
    dist[0] = 0;

    for(int i = 0; i < arr.size() -1; i++){
        for(int u = 0; u < arr.size(); u++){
            for(auto v: arr[u])
                if(dist[u] + v.ss < dist[v.ff])
                    dist[v.ff] = dist[u]+v.ss;
        }
    }

    for(int u = 0; u < arr.size(); u++)
        for(auto v: arr[u])
            if(dist[u] + v.ss < dist[v.ff])
                return 0;

    return 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c,n,m,x,y,t;
    cin >> c;

    while(c--){
        cin >> n >> m;

        vector< vector<pii> > arr(n);

        while(m--){
            cin >> x >> y >> t;
            arr[x].push_back({y,t});
        }

        if(!bellman(arr))
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;

    }

}
