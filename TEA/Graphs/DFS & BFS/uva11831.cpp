#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,s;
    string ins;

    char arr[] = {'N','L','S','O'};
    map<char,pii> move;

    move['N'] = {-1,0};
    move['S'] = {1,0};
    move['L'] = {0,1};
    move['O'] = {0,-1};

    while(cin >> n >> m >> s, n || m || s){
        int ans = 0;
        pii posi;
        char mapa[n][m],orien;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++ ){
                cin >> mapa[i][j];
                if(mapa[i][j] != '.' && mapa[i][j] != '*' && mapa[i][j] != '#'){
                    orien = mapa[i][j];
                    posi.ff = i;
                    posi.ss = j;
                }
            }
        }

        cin >> ins;

        for(auto x: ins){
            if(x == 'F'){
                auto k = move[orien];

                int iAt = posi.ff + k.ff, jAt = posi.ss + k.ss;

                if(iAt >= n || iAt < 0 || jAt >= m
                || jAt < 0) continue;

                if(mapa[iAt][jAt] == '#') continue;

                posi.ff = iAt;
                posi.ss = jAt;

                if(mapa[iAt][jAt] == '*'){
                    ans += 1;
                    mapa[iAt][jAt] = '.';
                }
            }

            else {
                int p = 0,r=1;
                for(int i = 0; i < 4; i++)
                    if(arr[i] == orien)
                        p = i;

                if(x == 'E') r = -1;

                if(p == 0 && r == -1) orien = arr[3];
                else orien = arr[(p+r)%4];

            }

        }

        cout << ans << endl;

    }
}
