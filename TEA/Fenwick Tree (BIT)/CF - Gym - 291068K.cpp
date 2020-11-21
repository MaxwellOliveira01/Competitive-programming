#include <bits/stdc++.h>
using namespace std;
int valores[1010][1010], prefix[1010][1010], ft[1010][1010];
int m,n;

void atualiza(int x, int y,int v){
    while(x <= m){
        ft[y][x] += v;
        x += (x&-x);
    }
}

int soma(int l, int posi){
    int s=0;
    while(posi > 0){
        s+=ft[l][posi];
        posi-=(posi&-posi);
    }
    return s;
}

int conta(int x1, int y1, int x2, int y2){
    int ans=0;
    for(int l = y1; l <= y2; l++) ans += soma(l,x2)-soma(l,x1-1);
    return ans;
}


int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d",&valores[i][j]);
            prefix[i][j] = prefix[i][j-1] + valores[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ft[i][j] = prefix[i][j] - prefix[i][j-(j&-j)];
        }
    }

    int move,c,x1,y1,x2,y2,v; cin >> move;
    while(move--){
        scanf("%d",&c);
        if(c==0){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            printf("%d\n",conta(x1,y1,x2,y2));
        } else {
            scanf("%d %d %d",&x1, &y1, &v);
            atualiza(x1,y1,v);
        }
    }
}
