#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int n,i = 0;

vector< vector<int> > arr(110, vector<int>());
vector< int > ans;
vector< pii > inter(110);

int mark[110];

int comp(int &a, int &b){
    return inter[a].ss > inter[b].ss;
}

void dfs(int p){

    if(mark[p])
        return;

    mark[p] = 1;

    inter[p].ff = i;
    i++;

    for(auto x: arr[p]){
        dfs(x);
    }

    inter[p].ss = i;
    i++;
}

int main() {
    int m,a,b;
    while(cin >> n >> m, n || m){

        arr.resize(n+1);
        ans.resize(n+1);
        arr.clear();
        ans.clear();
        inter.clear();

        for(int i = 1; i <= n; i++){
            mark[i] = 0;
            ans.push_back(i);
        }

        for(int j = 0; j < m; j++){
            cin >> a >> b;
            arr[a].push_back(b);
        }

        for(int i = 1; i <= n; i++)
            dfs(i);

        sort(ans.begin(), ans.end(), comp);

        for(int i = 0; i < ans.size()-1; i++)
            cout << ans[i] << " ";
        cout << ans.back() << endl;

    }
}
