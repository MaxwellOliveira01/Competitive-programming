#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

vector<int> ft(200001);

void build(vector<int>& prefix){
    ft[0] = 0;
    for(int i = 1; i < prefix.size(); i++)
        ft[i] = prefix[i] - prefix[i - (i&-i)];

}

int measure(int posi){
    int sum = 0;
    while(posi>0){
        sum += ft[posi];
        posi -= (posi&-posi);
    }
    return sum;
}

void setValue(int posi, int delta){
    while(posi <= ft.size()){
        ft[posi] += delta;
        posi += (posi&-posi);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b,caso = 1;
    string command;
    while(cin >> n, n){

        if(caso != 1) cout << endl;

        vector<int> arr(n+1);
        vector<int> prefix(n+1);
        ft.resize(n+1);


        prefix[0] = 0;

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            prefix[i] = prefix[i-1]+arr[i];
        }

        build(prefix);

        cout << "Case " << caso++ << ":" << endl;

        while(cin >> command, command != "END"){
            cin >> a >> b;

            if(command == "S"){
                setValue(a,b-arr[a]);
                arr[a] = b;
            }

            else
                cout << measure(b) - measure(a-1) << endl;

        }

    }
}
