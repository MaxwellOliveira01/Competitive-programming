#include <bits/stdc++.h>
#define pii pair<long long,long long>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<long long>
#define INF 1e10
using namespace std;

void setInf(vector< vector<pii> >& arr, vector<vi>& predecessor, int v){

    for(auto x: predecessor[v]){

        for(auto& p: arr[v])
            if(p.ff == x)
                p.ss = INF;

        for(auto& p: arr[x])
            if(p.ff == v)
                p.ss = INF;

        setInf(arr, predecessor, x);

    }
}

vi djikstra(vector< vector<pii> >& arr, vector<vi>& predecessor, int x){
    vi d(arr.size(), INF), mark(arr.size(), 0);
    priority_queue<pii, vector<pii>, greater<pii> > fila;

    d[x] = 0;
    fila.push({0,x});

    while(!fila.empty()){
        auto u = fila.top().ss;
        fila.pop();

        if(mark[u])
            continue;

        for(auto g: arr[u]){
            long long v = g.ff, p = g.ss;

            if(d[u] + p < d[v]){
                d[v] = p+d[u];

                fila.push({d[v],v});

                predecessor[v].clear();
                predecessor[v].push_back(u);
            }

            else if(d[u] + p == d[v])
                predecessor[v].push_back(u);

        }

    }

    return d;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, d;
    cin >> n >> m;

    vector< vector<pii> > arr(n+1);
    vector< vi > predecessor(n+1);
    vi dist;

    while(m--){
        cin >> u >> v >> d;
        arr[u].push_back({v,d});
        arr[v].push_back({u,d});
    }

    djikstra(arr, predecessor, 1);
    setInf(arr, predecessor, n);

    dist = djikstra(arr, predecessor, 1);

    if(dist[n] < INF)
        cout << dist[n] << endl;
    else
        cout << -1 << endl;

}
