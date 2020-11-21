#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define MAXN 1000000
#define ff first
#define ss second
using namespace std;
vector< pair<int,int> > tasks;
void addRepete(int a, int b, int c){
    while(a <= MAXN){
        tasks.pb(mk(a,1));
        tasks.pb(mk(b,-1));
        a+=c; b+=c;
    }
}
int main() {
    int n,m,a,b,c;
    while(cin >> n >> m, n || m){
        while(n--){
            cin >> a >> b;
            tasks.pb(mk(a,1));
            tasks.pb(mk(b,-1));
        }
        while(m--){
            cin >> a >> b >> c;
            addRepete(a,b,c);
        }
        sort(tasks.begin(), tasks.end());
        int c=0;
        for(int j = 0; j < tasks.size(); j++){
            c+= tasks[j].ss;
            if(c>1) break;
        }

        if(!c) cout << "NO CONFLICT" << endl;
        else cout << "CONFLICT" << endl;

        tasks.clear();
    }
}
