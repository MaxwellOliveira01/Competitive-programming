#include <bits/stdc++.h>
using namespace std;
deque<int> fila;

void emer(int posi){
    for(int j = 0; j < fila.size(); j++){
        if(fila[j] == posi){
            fila.erase(fila.begin()+j);
            break;
        }
    }
}

int main() {
    int p,c,caso=1;
    while(cin >> p >> c, p || c){
        char com; int posi,aux;
        for(int j = min(p,1050); j > 0; j--) fila.push_front(j);
        cout << "Case " << caso << ":" << endl;
        caso++;
        while(c--){
            cin >> com;
            aux = fila.front();
            if(com == 'N'){
                cout << aux << endl;
                fila.pop_front();
                fila.push_back(aux);
            } else {
                cin >> posi;
                emer(posi);
                fila.push_front(posi);
            }
        }
        fila.clear();
    }
}

