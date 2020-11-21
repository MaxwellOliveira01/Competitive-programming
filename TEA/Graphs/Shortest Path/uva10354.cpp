#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
#define INF 1e9
using namespace std;

vi vertices(102,0);

void setInf(vector< vector<pii> >& arr, vector< vi >& predecessor, int of){

    for(auto x: predecessor[of]){
        for(auto& p: arr[of])
            p.ss = INF;

        for(auto& p: arr[x])
            p.ss = INF;

        vertices[x] = 1;
        vertices[of] = 1;

        setInf(arr, predecessor, x);
    }

}

vi djikstra(vector<vector<pii>>& arr, vector< vi >& predecessor, int x, int op){
    vi d(predecessor.size(), INF), mark(predecessor.size(), 0);

    priority_queue< pii, vector<pii>, greater<pii> > fila;

    d[x] = 0;
    fila.push({0,x});

    while(!fila.empty()){
        auto u = fila.top().ss;
        fila.pop();

        if(mark[u]) continue;

        if(vertices[u] && op)
            continue;


        for(auto g: arr[u]){
            int v = g.ff, p = g.ss;

            if(d[u] + p < d[v]){
                d[v] = d[u] + p;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, bh, of, yh, m, a, b, c,cost;

    while(cin >> n >> r >> bh >> of >> yh >> m){
        vector< vector<pii> > arr(n+1);
        vector< vi > predecessor(n+1);

        for(int i = 0; i < r; i++){
            cin >> a >> b >> c;

            arr[a].push_back({b,c});
            arr[b].push_back({a,c});

        }

        vi d(n+1,INF), d2(n+1,INF);

        //Boss house -> All
        d = djikstra(arr, predecessor, bh, 0);
        setInf(arr,predecessor,of);


        //Home -> All
        d2 = djikstra(arr,predecessor, yh, 1);


        if(d2[m] < INF && m != bh && m != of && yh != bh && yh != of && !vertices[m] && !vertices[yh])
            cout << d2[m] << endl;

        else
            cout << "MISSION IMPOSSIBLE." << endl;

        vertices.assign(n+1,0);

    }
}
