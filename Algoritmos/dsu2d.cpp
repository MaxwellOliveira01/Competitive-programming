#include <bits/stdc++.h>
#define debug(x) cout << "[" << #x << " = " << x << "] "
#define ff first
#define ss second
 
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;
 
const int INF = 1e9; // INF to INT
//const ll INF = 1e18; //INF to LL
 
/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/
 
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
 
struct DSU {
 
    int n = 0, m = 0;
    vector<vector<pii>> parent;
    vector<vector<int>> sz;
 
    DSU(int nn, int mm){
        
        n = nn;
        m = mm;
 
        sz.assign(n + 5, vector<int>(m + 5, 1));
        parent.assign(n + 5, vector<pii>(m+5,{0,0}));
 
        for(int i = 0; i < n + 2; i++){
            for(int j = 0; j < m + 2; j++){
                parent[i][j] = {i,j};
            }
        }
 
    }
 
    pii find(pii x){
        if(x == parent[x.ff][x.ss]) return x;
        return parent[x.ff][x.ss] = find(parent[x.ff][x.ss]); 
    }
 
    void join(pii a, pii b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a.ff][a.ss] < sz[b.ff][b.ss]) swap(a, b);
        parent[b.ff][b.ss] = a;
        sz[a.ff][a.ss] += sz[b.ff][b.ss];
    } 
 
    int getSize(pii x){
        return sz[x.ff][x.ss];
    }
 
};
