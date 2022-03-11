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

const int block_size = 300; //yes, const value for the MAXN
// something near to sqrt(MAXN)

struct Query {
    int l, r, idx;
    Query(): l(0), r(0), idx(0) {};
    bool const operator<(Query& b) {
        if(l / block_size != b.l / block_size )
            return l < b.l;
        if(l / block_size & 1)
            return r < b.r;
        return  r > b.r;        
    }
};

const int MAXN = 1e6 + 10;

// ~ O((N+Q)sqrt(N))
vector<int> mos_algo(vector<Query>& queries, vector<int>& arr) {
    int n = (int)queries.size(), ans = 0;
    vector<int> ans_querie(n);
    sort(queries.begin(), queries.end());

    vector<int> c(MAXN); //some structure to make add/rem operations

    auto add = [&](int x){
        assert(x >= 0 && x < (int)arr.size());
        ans += (c[arr[x]] & 1);
        c[arr[x]]++;
    };

    auto rem = [&](int x){
        assert(x >= 0 && x < (int)arr.size());
        ans -= (c[arr[x]] % 2 == 0);
        c[arr[x]]--;
    };

    int l = 0, r = -1;
    for(auto q : queries) {
        while(l > q.l) {
            l--;
            add(l);
        }
        while(r < q.r) {
            r++;
            add(r);
        }
        while(l < q.l) {
            rem(l);
            l++;
        }
        while(r > q.r) {
            rem(r);
            r--;
        }
       ans_querie[q.idx] = ans;
    }
    return ans_querie;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x: arr) {
        cin >> x;
    }
    int q;
    cin >> q;
    vector<Query> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
        queries[i].l--;
        queries[i].r--;
    }
    vector<int> ans = mos_algo(queries, arr);
    for(auto &x: ans) {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

}
