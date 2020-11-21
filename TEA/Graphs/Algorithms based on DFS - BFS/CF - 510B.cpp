#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

vector<string> arr(55);
int mark[55][55], di[] = {0,0,1,-1}, dj[] = {1,-1,0,0}, ans = 0;
int l,c;

int v(int i, int j){
    return (i >= 0 && j >= 0 && i < l && j < c);
}

void dfs(int i, int j,int x, int y){

    if(mark[i][j]){
        ans = 1;
        return;
    }

    else mark[i][j] = 1;

    for(int p = 0; p < 4; p++){
        int iAt = i+di[p], jAt = j+dj[p];

        if(iAt == x && jAt == y)
            continue;

        if(!v(iAt,jAt))
            continue;

        if(arr[iAt][jAt] != arr[i][j])
            continue;

        dfs(iAt,jAt,i,j);

    }
}

int main() {
    cin >> l >> c;

    arr.resize(l);
    for(int i = 0; i < l; i++)
        cin >> arr[i];

    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            if(!mark[i][j])
                dfs(i,j,i,j);

    if(ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}
