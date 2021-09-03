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

struct BIT {

    int n;
    vector<int> bit;

    BIT(int nn){
        n = nn;
        bit.assign(n + 10, 0);
    }

    int query(int x){
        x++;
        int ans = 0;
        while(x > 0){
            ans += bit[x];
            x -= (x & (-x));
        }
        return ans;
    }

    void update(int x, int val){
        if(x < 0) return;
        x++;
        while(x < (int)bit.size()){
            bit[x] += val;
            x += (x & (-x));
        }
    }

    int findkth(int k){
        //find kth smallest (required use every pos i to store the quantity of value i) 
        int x = 0, mx = 200;
        for(int b = n; b > 0 && mx > 0; b /= 2){
            while( x+b < n && query(x+b) < k && mx-- > 0 ){
                x += b;
            }
        }
        return x+1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, re;
    cin >> n >> q;

    BIT bit(n);

    for(int i = 0; i < n; i++){
        cin >> re;
        bit.update(re,1);
    }

    for(int i = 0; i < q; i++){
        cin >> re;
        if(re > 0) bit.update(re,1);
        else {
            int x = bit.findkth(-re);
            bit.update(x,-1);
        }
    }

    //cout << bit.query(n + 1) << endl;
    cout << ( bit.query(n + 1) > 0 ? bit.findkth(1) : 0 ) << endl;
}
