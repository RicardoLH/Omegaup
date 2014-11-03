/*
ID: t_a_k_e1
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int matriz[2005][2005];
bool visitados[2005];
int componentes[2005];
int contadorC;
int contadorN;
int n;
int m;
int busqueda( int nodo ){
    if( visitados[nodo] == true ){
        return 0;
    }else{
        int cont = 0;
        visitados[nodo] = true;
        for( int i = 1; i <= n; i++ ){
            if( matriz[nodo][i] != 0 && !visitados[i] ){
                cont += busqueda(i) + 1;
            }
        }
        return cont;
    }
}
int main() {
    scanf("%d",&n);
    scanf("%d",&m);
    int a;
    int b;
    for( int i = 0; i < m; i++ ){
        scanf("%d",&a);
    scanf("%d",&b);
        matriz[a][b] = 1;
        matriz[b][a] = 1;
    }
    int contC = 0;
    for( int i = 1; i <= n; i++ ){
        if( !visitados[i] ){
            componentes[contC++] = busqueda(i) + 1;
        }
    }

    int parejas = 0;
    for( int i = 0; i < contC; i++ ){
        for( int j = i+1; j < contC; j++ ){
            parejas += ( componentes[i] * componentes[j] );
        }
    }
    cout<<parejas<<endl;


}
