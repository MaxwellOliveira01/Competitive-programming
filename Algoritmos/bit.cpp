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

const int oo = (int)1e9 + 5; //INF to INT
const ll OO = 0x3f3f3f3f3f3f3f3fLL; //INF to LL

/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/

struct BIT {
    int n, LOGN = 0;
    vector<ll> bit;

    BIT(int nn){
        n = nn + 10;
        bit.resize(n + 10, 0);
        while( (1LL << LOGN) <= n ) LOGN++;
    }

    ll query(int x){
        x++;
        ll ans = 0;
        while(x > 0){
            ans += bit[x];
            x -= (x & (-x));
        }
        return ans;
    }

    void update(int x, ll val){
        x++;
        while(x < (int)bit.size()){
            bit[x] += val;
            x += (x & (-x));
        }
    }

    int findkth(int k){
        //kth smallest, O(logN)
        //use position i to count how many times value 'i' appear
        int sum = 0, pos = 0;
        for(int i = LOGN; i >= 0; i--){
            if(pos + (1LL << i) < n && sum + bit[pos + (1LL << i)] < k){
                sum += bit[pos + (1LL << i)];
                pos += (1LL << i);
            }
        }
        return pos;
    }
/*
    int findkth(int k){
        //kth smallest, O(log^2(N))
        //use position i to count how many times value 'i' appear
        int x = 0, mx = 200;
        for(int b = n; b > 0 && mx > 0; b /= 2){
            while( x+b < n && query(x+b) < k && mx-- > 0 ){
                x += b;
            }
        }
        return x+1;
    }
*/
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    BIT bit(n);
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        bit.update(i, arr[i]);
    }
    int k, a, b;
    for(int i = 0; i < q; i++){
        cin >> k >> a >> b;
        if(k == 1){
            bit.update(a-1, b - arr[a-1]);
            arr[a-1] = b;
        } else {
            cout << bit.query(b-1) - bit.query(a-2) << "\n";
        }
    }   
    
}