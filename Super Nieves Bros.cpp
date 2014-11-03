#include <iostream>

using namespace std;
struct Cuarto{
    char tipo;
    bool visitado;
};
Cuarto tablero[51][51];
int f;
int c;
int n;
int m;
bool busca(int i, int j, int e ){
    if( i < 0 || i >= n || j < 0 || j >= m ){
        return false;
    }
    if( tablero[i][j].visitado ){
        return false;
    }
    if( i == (f-1) && j == (c-1) ){
        return true;
    }
    if( tablero[i][j].tipo == '.' ){
        return false;
    }
    tablero[i][j].visitado = true;
    bool encontrado = busca(i,j-1,e) || busca(i,j+1,e);
    for( int s = e; s >= 1; s--  ){
        encontrado = encontrado || busca(i-s,j,e);
        encontrado = encontrado || busca(i+s,j,e);
    }
    return encontrado;
}
int main()
{
    cin>>n;
    cin>>m;
    cin>>f;
    cin>>c;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            cin>>tablero[i][j].tipo;
        }
    }
    bool encontrado = false;
    for( int e = 0; e <= n; e++ ){
            
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                tablero[i][j].visitado = 0;
            }
        }
        encontrado = busca( n-1,0, e);
        if( encontrado ){
            cout<<e<<endl;
            break;
        }
    }
}
