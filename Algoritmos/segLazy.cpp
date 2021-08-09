#include <bits/stdc++.h>
#define debug(x) cout << "[" << #x << " = " << x << "] "
#define ff first
#define ss second

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;

using tii = tuple<int,int,int>;
// auto [a,b,c] = ...
// .insert({a,b,c})

const int INF = 1e9; // INF to INT
//const ll INF = 1e18; //INF to LL

/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/
  
struct SegLazy {

    int n;
    vector<ll> seg;
    vector<ll> lazy;

    SegLazy(vector<int>& arr){
        n = (int)arr.size();
        seg.assign(n+n+n+n, 0);
        lazy.assign(n+n+n+n, 0);
        build(1,0,n-1,arr);
    }

    ll merge(ll a, ll b){
        return a+b;
    }

    void build(ll x, int l, int r, vector<int>& arr){
        if(l == r){
            seg[x] = arr[l];
        } else {
            int mid = l + (r-l)/2;
            build(x+x, l, mid, arr);
            build(x+x+1, mid+1, r, arr);
            seg[x] = merge(seg[x+x], seg[x+x+1]);
        }
    }
    
    void upd_lazy(ll node, ll l, ll r){
        seg[node] += (ll)(r-l+1) * lazy[node];
        ll esq = node + node, dir = esq + 1;
        
        if(dir < (int)seg.size()){
            lazy[esq] += lazy[node];
            lazy[dir] += lazy[node];
        }
    
        lazy[node] = 0;
    }
    
    ll q(ll x, int l, int r, int i, int j){
        if(r < i || l > j ) return 0;
        upd_lazy(x,l,r);

        if(l >= i && r <= j ) 
            return seg[x];
        
        int mid = l + (r-l)/2;
        return merge(q(x+x,l,mid,i,j), q(x+x+1,mid+1,r,i,j));
    }
    
    ll query(int l, int r){ //valor em uma posi específica -> query de [l,l]
        return q(1, 0, n-1, l, r);
    }
    
    void upd(ll x, int l, int r, int i, int j, int u){
        if(r < i || l > j) return;
        if(l >= i && r <= j){
            lazy[x] += u;
        } else {
            int mid = l + (r-l)/2;
    
            upd(x+x,l,mid,i,j,u);
            upd(x+x+1,mid+1,r,i,j,u);
        }
    }
    
    void upd_range(int l, int r, ll u){ //intervalo e valor
        upd(1,0,n-1,l,r,u);
    }

};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
}