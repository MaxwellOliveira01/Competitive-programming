#include <bits/stdc++.h>
#define debug(x) cout << "[" << #x << " = " << x << "] ";
#define debugendl(x) cout << "[" << #x << " = " << x << "]\n";
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

struct BIT2D {

    int n, m;
    vector<vector<int>> bit;

    BIT2D(int nn, int mm) { 
        //use as 0-indexed, but inside here I will use 1-indexed positions
        n = nn + 2;
        m = mm + 2;
        bit.assign(n, vector<int>(m));
    }

    void update(int x, int y, int p) {
        x++; y++;
        assert(x > 0 && y > 0 && x <= n && y <= m);
        for(; x < n; x += (x&(-x)))
            for(int j = y; j < m; j += (j&(-j)))
                bit[x][j] += p;
    }

    int sum(int x, int y) {
        int ans = 0; 
        for(; x > 0; x -= (x & (-x)))
            for(int j = y; j > 0; j -= (j&(-j)))
                ans += bit[x][j];
        return ans;
    }

    int query(int x, int y, int p, int q) {
        //x...p on line, y...q on column
        //sum from [x][y] to [p][q];
        x++; y++; p++; q++;
        assert(x > 0 && y > 0 && x <= n && y <= m);
        assert(p > 0 && q > 0 && p <= n && q <= m);
        return sum(p, q) - sum(x - 1, q) - sum(p, y - 1) + sum(x - 1, y - 1);
    }


};

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

}
