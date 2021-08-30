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

struct Trie{

    int nxt = 1, sz, maxLet = 26; //tamanho do alfabeto
    vector< vector<int> > trie;
    bitset<(int)1e7> finish; //modificar esse valor pra ser >= n
    //garantir que vai submeter em cpp 64

    Trie(int n){
        sz = n;
        trie.assign(sz, vector<int>(maxLet,0));
    }

    void add(string &s){
        int cur = 0;
        for(auto c: s){
            //alterar esse azinho dependendo da entrada!!
            if(trie[cur][c-'a'] == 0){
                trie[cur][c-'a'] = nxt++;
                cur = trie[cur][c-'a'];
            } else {
                cur = trie[cur][c-'a'];
            }
        }
        finish[cur] = 1;
    }

    int search(string& s){
        int cur = 0;
        for(auto c: s){
            if(trie[cur][c - 'a'] == 0){
                return 0;
            }
            cur = trie[cur][c-'a'];
        }
        return finish[cur];
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Trie trie(50);
    vector<string> arr = {"there", "the", "their", "therefore","thereafter"};
    for(auto t : arr)
        trie.add(t);
    for(auto t: arr)
        cout << trie.search(t) << endl;
    
    string pq = "abc", pq2 = "ther";
    cout << trie.search(pq) << endl;
    cout << trie.search(pq2) << endl;
}
