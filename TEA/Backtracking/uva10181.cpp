#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define vii vector<int>
#define ff first
#define ss second

using namespace std;
vector<vii> puzzle(4);
vector<vii> puzz(4);
map<pii, char> ans;
map<int, pii> posicoes;
int di[4] = {-1, 1, 0,0}, dj[4] = {0, 0, -1, 1};
vector<pii> moves;
string answer = "";
int tamAtual = 50;

int contInv()
{
    int cont = 0, puzzv[16], pos = 0;
    //guardar os elementos em uma dimensão só
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            puzzv[pos++] = puzzle[i][j];
        }
    }
    //inversão se: val[i] > val[j] e i < j
    for (int i = 0; i < 15; i++)
    {
        for (int j = i + 1; j < 16; j++)
        {
            if (puzzv[i] == 0 || puzzv[j] == 0)
                continue;
            if (puzzv[i] > puzzv[j])
                cont++;
        }
    }
    return cont;
}

int coordX()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!puzzle[i][j])
                return 4 - i;
        }
    }
    return -1; //nao vai chegar aqui
}

int solvable()
{
    int inver = contInv(), posi = coordX();
    int teste = inver % 2;
    if (posi % 2 != 0)
        return !teste;
    else
        return teste;
}

int verifica(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (i > 3 || j > 3)
        return 0;

    return 1;
}

int foraPosi()
{
    int cont = 0;
    pii p;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (puzzle[i][j] != puzz[i][j] && puzzle[i][j]!=0)
            {
                p = posicoes[puzzle[i][j]];
                cont += abs(i - p.ff) + abs(j - p.ss); //manhattan
            }
        }
    }
    return cont;
}

string getAns()
{
    string resp = "";
    for (int x = 0; x < moves.size(); x++)
    {
        resp += ans[{moves[x].ff, moves[x].ss}];
    }
    return resp;
}


void solve(int i, int j,int c)
{

    if(c> tamAtual) return;
    int h = foraPosi();
    if(h==0 && c < tamAtual){
        answer = getAns();
        tamAtual = c;
    }

    if(h+c>tamAtual){
        return;
    }

    int iAt, jAt;

    for (int p = 0; p < 4; p++)
    {
        iAt = i + di[p];
        jAt = j + dj[p];
        if (!verifica(iAt, jAt))
            continue;

        if (moves.size() > 0)
        {
            if (moves.back().ff + di[p] == 0 && moves.back().ss + dj[p] == 0)
                continue;
        }

        swap(puzzle[iAt][jAt], puzzle[i][j]);

        moves.push_back({di[p], dj[p]});

        solve(iAt, jAt,c+1);

        moves.pop_back();
        swap(puzzle[iAt][jAt], puzzle[i][j]);
    }
}

void iniciaMap()
{
    ans[{0, 1}] = 'R';
    ans[{0, -1}] = 'L';
    ans[{-1, 0}] = 'U';
    ans[{1, 0}] = 'D';
    //inicia o map com as posicoes certas
    int cont = 1;
    puzz.assign(4, vector<int>(4, 0));
    int k = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            posicoes[k++] = {i, j};
            puzz[i][j] = (i * 4 + j + 1) % 16;
        }
    }
    posicoes[0] = {3, 3};
}

int main()
{
    int q, coordI, coordJ, recebe;
    cin >> q;
    iniciaMap();
    puzzle.clear();
    while (q--)
    {
        for (int i = 0; i < 4; i++)
        {
            puzzle.push_back(vector<int>());
            for (int j = 0; j < 4; j++)
            {
                int r;
                scanf("%d",&r);
                puzzle[i].push_back(r);
                if (!puzzle[i][j])
                {
                    coordI = i;
                    coordJ = j;
                }
            }
        }
        if (solvable())
        {
            solve(coordI, coordJ,0);
            //if (answer != "")
            cout << answer << endl;
        }
        else
        {
             printf("This puzzle is not solvable.\n");
        }

        answer.clear();
        tamAtual = 50;
        moves.clear();
        puzzle.clear();

    }
}
