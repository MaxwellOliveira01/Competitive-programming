#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
#define INF 1e9
using namespace std;

int n,m;
int di[] = {1,-1,0,0}, dj[] = {0,0,1,-1};

int verifica(int i, int j){
    return i >= 0 && j >=0 && i < n && j < m;
}

void solve(vector<vi>& arr){
    vector<vi> mark(n, vi(m,0)), dist(n, vi(m, INF));

    priority_queue< pair<int,pii> , vector< pair<int,pii> >> fila;

    dist[0][0] = 0;
    fila.push({0,{0,0}});
    //peso 0, vertice 0

    while(!fila.empty()){
        pii u = fila.top().ss;
        fila.pop();

        int i = u.ff, j = u.ss;

        if(mark[i][j])
            continue;

        mark[i][j] = 1;

        for(int p = 0; p < 4; p++){
            int iAt = i + di[p], jAt = j + dj[p];

            if(verifica(iAt,jAt)){

                if(dist[i][j] + arr[iAt][jAt] < dist[iAt][jAt]){
                    dist[iAt][jAt] = dist[i][j] + arr[iAt][jAt];

                    fila.push({ -dist[iAt][jAt], {iAt,jAt} });

                }
            }

        }

    }

    cout << dist[n-1][m-1]+arr[0][0] << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int quant;
    cin >> quant;

    while(quant--){
        cin >> n >> m;

        vector<vi> arr(n, vi(m));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];

        solve(arr);
    }

}
