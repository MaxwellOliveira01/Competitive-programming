#include <bits/stdc++.h>
using namespace std;

int main() {
    int quant; cin >> quant;
    while(quant--){
        int n,s,q,a,b,posi=0,tempo=0;
        cin >> n >> s >> q;
        stack<int> move;
        queue<int> plataformB[101];
        for(int j = 0; j < n; j++){
            cin >> a;
            while(a--){
                cin >> b;
                plataformB[j].push(b-1);
            }
        }

        while(1){

            while(move.size() > 0 && (move.top() == posi || plataformB[posi].size() < q)){
                if(move.top() != posi) plataformB[posi].push(move.top());
                move.pop();
                tempo++;
            }

            while(move.size() < s && plataformB[posi].size() > 0){
                move.push(plataformB[posi].front());
                plataformB[posi].pop();
                tempo++;
            }

            int fim = 0;
            for(int i = 0; i < n; i++){
                fim += plataformB[i].size();
            }

            if(!fim && !move.size()) break;


            posi == n-1 ? posi = 0 : posi++; // [1,n]
            tempo+=2;
        }
        cout << tempo << endl;
        tempo = 0;
    }
}
