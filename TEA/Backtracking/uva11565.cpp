#include<stdio.h>
int a,b,c;
int confere(int x, int y, int z){
    if(x+y+z != a) return 0;
    if(x*y*z != b) return 0;
    if(x*x+y*y+z*z != c) return 0;
    if(x == y || y == z || x == z) return 0;
    return 1;
}

int main() {
    int t; scanf("%d",&t);
    while(t--){
        int x,y,z,ans=0;
        scanf("%d %d %d", &a,&b,&c);
        for(x = -100; x <= 100; x++){
            for(y = -100; y <= 100; y++){
                for(z = -100; z <= 100; z++){
                    if(confere(x,y,z)){
                        ans = 1;
                        break;
                    }
                }
            if(ans) break;
            }
        if(ans) break;
        }

        if(ans) printf("%d %d %d\n",x,y,z);
        else printf("No solution.\n");

    }
}
