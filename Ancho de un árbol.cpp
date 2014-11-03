
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
struct Nodo{
    int der;
    int izq;
    int posicion;
};
Nodo arbol[1005];
int n;
struct Nivel{
    int minimo;
    int maximo;
    int distancia;
};
Nivel niveles[1005];
int cont;
void comprueba( int nivel, int posicion ){
    if( niveles[nivel].minimo == 0 ){
        niveles[nivel].minimo = posicion;
    }else if( niveles[nivel].maximo < posicion ){
        niveles[nivel].maximo = posicion;
    }
}
void busca( int nodo, int nivel ){
    if( arbol[nodo].izq == -1 && arbol[nodo].der == -1 ){
        comprueba(nivel, ++cont );
        arbol[nodo].posicion = cont;
    

    }else{
        if( arbol[nodo].izq != -1 ){
            busca(arbol[nodo].izq, nivel +1 );
        }
        comprueba(nivel, ++cont );
        arbol[nodo].posicion = cont;
    
        if( arbol[nodo].der != -1 ){
            busca(arbol[nodo].der, nivel +1 );
        }

    }
}
int main() {
    cin>>n;
    int nodo = 0;
    int nIzq = 0;
    int nDer = 0;
    for( int i = 1; i <= n; i++ ){
        cin>>nodo;
        cin>>nIzq;
        cin>>nDer;
        arbol[nodo].izq = nIzq;
        arbol[nodo].der = nDer;
    }
    busca(1,1);
    int nivel = 1;
    int maximo = 0;
    for( int i = 1; i <= n; i++ ){
        int distancia = ( niveles[i].maximo  - niveles[i].minimo );
        if( distancia > maximo ){
            maximo = distancia;
            nivel = i;
        }
    }
    cout<<nivel<< " "<<maximo+1<<endl;;

}
