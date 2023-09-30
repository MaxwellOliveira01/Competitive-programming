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

struct Mex {

    vector<int> occur;
    set<int> q;

    Mex(int MAXVAL){
        occur.resize(MAXVAL + 1);
        for(int i = 0; i <= MAXVAL + 1; i++)
            q.insert(i);
    };

    void add(int val){
        if(++occur[val] == 1) {
            q.erase(val);
        }
    }

    void rem(int val){
        if(--occur[val] == 0) {
            q.insert(val);
        }
    }

    void update(int oldV, int newV) {
        add(newV);
        rem(oldV);
    }

    int query(){
        assert(q.size());
        return *q.begin();
    }

};

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
