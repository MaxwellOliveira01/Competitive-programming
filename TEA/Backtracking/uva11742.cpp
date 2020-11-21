#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
vector< pair<int,pii> > regras;
vector<int> grupo;
int confere(){
    int posiA, posiB;
    for(auto x: regras){

       for(int j = 0; j < grupo.size(); j++){
           if(grupo[j] == x.ss.ff) posiA = j;
           if(grupo[j] == x.ss.ss) posiB = j;
       }

       if(x.ff > 0){
           if(abs(posiA-posiB) > x.ff) return 0;
       } else {
           if(abs(posiA-posiB) < -x.ff) return 0;
       }
   }
   return 1;
}

int main() {
    int n,m,a,b,c;
    while(cin >> n >> m, n || m){
        for(int i = 0; i < n; i++) grupo.push_back(i);
        while(m--){
            cin >> a >> b >> c;
            regras.push_back({c,{a,b}});
        }
        int ans = 0;
        do{
            if(confere()) ans++;
        } while(next_permutation(grupo.begin(),grupo.end()));

        cout << ans << endl;
        grupo.clear(); regras.clear();
    }

}
