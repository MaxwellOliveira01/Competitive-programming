#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
#define INF 1e3
using namespace std;

void floyd(vector<vi>& arr){

    for(int k = 1; k < arr.size(); k++){
        for(int i = 1; i < arr.size(); i++){
            for(int j = 1; j < arr.size(); j++){
                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }


}

double solve(vector<vi>& arr){
    floyd(arr);

    double ans = 0,quant = 0;

    for(int i = 1; i < arr.size(); ++i)
        for(int j = 1; j < arr.size(); ++j)
            if (i != j && arr[i][j] != INF){
                    ans += arr[i][j];
                    quant++;
            }

    return ans/quant;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,caso=1;

    cout.precision(3);
    cout.setf(ios::fixed);

    while(cin >> a >> b, a || b){
        vector<vi> arr(101, vi(101,INF));
        map<int,int> mark;
        int posi = 1,cont=0;
        double ans;

        do{

            if(mark[a] == 0)
                mark[a] = posi++;


            if(mark[b] == 0)
                mark[b] = posi++;


            arr[mark[a]][mark[b]] = 1;
            cont++;

        } while(cin >> a >> b, a || b);

        for(int i = 0; i < 100; i++)
            arr[i][i] = 0;

        arr.resize(posi);

        for(int i = 0; i < posi; i++)
            arr[i].resize(posi);

        ans = solve(arr);

        cout << "Case " << caso++ << ": average length between pages = "
         << ans << " clicks" <<  endl;

    }
}
