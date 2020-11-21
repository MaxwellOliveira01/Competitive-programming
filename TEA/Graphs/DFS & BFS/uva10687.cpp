#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
vector<pii> point(1010);

void dfs(vector<int>& reach, vector< vector<int> >& grafo, int x){
    if(reach[x]) return;
    reach[x] = 1;
    for(auto k: grafo[x])
        dfs(reach,grafo,k);
}

int comp(pair<double,int>& a, pair<double,int>& b){
    if(a.ff < b.ff) return 1;

    else if(a.ff == b.ff){
        if(point[a.ss].ff < point[b.ss].ff)
            return 1;

        return point[a.ss].ss < point[b.ss].ss;
    }

    return 0;
}

pii adj(int posi){
    vector<pair<double,int>> dist;
    double k;

    for(int i = 0; i < point.size(); i++){
        k = abs(point[i].ff-point[posi].ff)*abs(point[i].ff-point[posi].ff)+
        abs(point[i].ss-point[posi].ss)*abs(point[i].ss-point[posi].ss);

        dist.push_back({k,i});
    }

    sort(dist.begin(),dist.end(),comp);
    return {dist[1].ss,dist[2].ss};

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector< int > reach(1010,0);
    while(cin >> n, n){
        int c = 1;


        reach.resize(n);
        point.resize(n);

        reach.assign(n,0);

        for(int i = 0; i < n; i++)
            cin >> point[i].ff >> point[i].ss;


        if(n <= 3){
            cout << "All stations are reachable." << endl;
            continue;
        }

        vector< vector<int> > grafo(n+1);

        for(int i = 0; i < n; i++){
            pii k = adj(i);
            grafo[i].push_back(k.ff);
            grafo[i].push_back(k.ss);
        }

        dfs(reach,grafo,0);
        for(int i = 0; i < n; i++)
            if(!reach[i]) c = 0;

        if(c) cout << "All stations are reachable." << endl;
        else cout << "There are stations that are unreachable." << endl;

    }
}
