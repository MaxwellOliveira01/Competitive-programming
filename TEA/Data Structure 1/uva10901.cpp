#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
queue<int> l, r;
int tempo, t,side_left;

void trocaLado(){
    if(side_left && ((l.size() == 0) || (tempo < l.front() && l.front() > r.front()
        && r.size() > 0))) {
            side_left = 0;
            tempo = max(tempo+t,r.front()+t);
            return;
        }
            //dir -> esq
    if(!side_left && ((r.size() == 0) || (tempo < r.front() && r.front() > l.front()
        && l.size() > 0))){
            side_left = 1;
            tempo = max(tempo+t,l.front()+t);
            return;
        }
}

int main() {
    int q; cin >> q;
    while(q--){
        int n,m,tC,posiAnsL=0,posiAnsR=0; cin >> n >> t >> m;
        string side;

        vector<pair<int,pii>> ansL,ansR,ans;
        for(int i = 0; i < m; i++){
            cin >> tC >> side;
            if(side == "left"){
                l.push(tC); ansL.push_back({i,{tC,0}});
            } else {
                r.push(tC); ansR.push_back({i,{tC,0}});
            }
        }


        side_left = 1;tempo=0;

        while(l.size() > 0 && r.size() > 0){
            trocaLado();
            if(side_left){
                tempo = max(tempo,l.front());
                int c = 1;
                while(l.size() > 0 && l.front() <= tempo && c <= n){
                    ansL[posiAnsL].ss.ss = tempo+t;
                    l.pop();
                    c++; posiAnsL++;
                }
                tempo+=t;
                side_left = 0;
            }

            else{

                tempo = max(tempo,r.front());
                int c = 1;
                while(r.size() > 0  && r.front() <= tempo && c <= n){
                    ansR[posiAnsR].ss.ss = tempo+t;
                    r.pop();
                    c++; posiAnsR++;
                }
                tempo += t;
                side_left = 1;
            }
        }

        while(r.size() > 0){
            trocaLado();

            if(side_left){
                tempo = max(tempo+t,r.front());
                side_left = 0;
            }

            else{
                //cout << tempo << " " << "?" <<  endl;
                tempo = max(tempo,r.front());
                int c = 1;
                while(r.size() > 0  && r.front() <= tempo && c <= n){
                    ansR[posiAnsR].ss.ss = tempo+t;
                    r.pop();
                    c++; posiAnsR++;
                }
                tempo += t;
                side_left = 1;
                //cout << tempo  << endl;
            }
        }

        while(l.size() > 0){
            trocaLado();

            if(side_left){
                tempo = max(tempo,l.front());
                int c = 1;
                while(l.size() > 0 && l.front() <= tempo && c <= n){
                    ansL[posiAnsL].ss.ss = tempo+t;
                    l.pop();
                    c++; posiAnsL++;
                }
                tempo+=t;
                side_left = 0;
            }

            else{
                tempo = max(tempo+t,l.front());
                side_left = 0;
            }

        }

        ans = ansL;
        for(int i = 0; i < ansR.size(); i++) ans.push_back(ansR[i]);
        sort(ans.begin(),ans.end());
        for(auto x: ans) cout << x.ss.ss << endl;
        if(q>0) cout << endl;

    }

}
