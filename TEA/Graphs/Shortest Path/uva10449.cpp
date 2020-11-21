#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
#define INF 1e9
using namespace std;

vector<int> mark(205,0);

vi bellman(vector< vector<pii> >& arr){
    vector<int> dist(arr.size(), INF);
    dist[1] = 0;

    for(int i = 0; i < arr.size() -1; i++){
        for(int u = 0; u < arr.size(); u++){
            for(auto v: arr[u])
                if(dist[u] + v.ss < dist[v.ff])
                    dist[v.ff] = dist[u]+v.ss;
        }
    }

    for(int u = 0; u < arr.size(); u++){
        for(auto& v: arr[u]){
            if(dist[u] + v.ss < dist[v.ff]){
                mark[u] = 1;
                dist[v.ff] = -INF;
                //u -> v faz parte de ciclo negativo

            }
        }
    }

    return dist;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,r,q,a,b,setN=1;

    while(cin >> n){
        vector< vector<pii> > arr(n+1);
        vector<int> d;
        int w[n+1];

        for(int i = 1; i <= n; i++)
            cin >> w[i];


        cin >> r;

        while(r--){
            cin >> a >> b;
            arr[a].push_back({b, pow(w[b]-w[a],3)});
        }

        d = bellman(arr);

        cin >> q;

        cout << "Set #" << setN++ << endl;

        while(q--){
            cin >> a;

            if(d[a] < 3 || d[a] >= 1e6 || mark[a])
                cout << "?" << endl;

            else
                cout << d[a] << endl;

        }

        mark.assign(205,0);
    }

}
