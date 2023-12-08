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

struct Trie {

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


struct Trie {

    struct Node {
        map<char, Node> adj; // dá pra trocar por vector(26)
        ll finishHere;

        Node() {
            finishHere = 0;
        }

        bool find(char c) {
            return adj.find(c) != adj.end();
        }

    };

    Node mainNode;

    Trie(){
        mainNode = Node();
    }

    void add(string &s) {
        Node *curNode = &mainNode;

        for(auto &c : s) {
            
            if(!curNode->find(c)) {
                curNode->adj[c] = Node();
            }

            curNode = &curNode->adj[c];
        }

        curNode->finishHere += 1;
    }

    void dfs(Node& node) {
        for(auto &v : node.adj) {
            dfs(v.ss);
            // faz alguma coisa
        }
    }

    void dfs() {
        return dfs(mainNode);
    }

    bool search(string &s) {
        Node* curNode = &mainNode;

        for(auto &c : s) {
            if(!curNode->find(c))
                return false;

            curNode = &curNode->adj[c];
        }

        return curNode->finishHere > 0;
    }

    void debugRec(Node node, int depth) {
        for(auto &x : node.adj) {
            cout << string(3 * depth, ' ') << x.ff << " " << x.ss.finishHere << "\n";
            debugRec(x.ss, depth + 1);
        }
    }

    void debug() {
        debugRec(mainNode, 0);
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
