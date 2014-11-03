#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
char numero[11];
set<int> cadenas;
int longitud;
int convierte(){
    int sum = 0;
    int cont = 1;
    for( int i = longitud-1; i >= 0; i-- ){
        sum += ( cont * ( numero[i] - '0' ) );
        cont *= 10;
    }
    return sum;
}
bool alrevez( int a, int b ){
    return a > b;
}
void hazCopia( int a ){
    int cont = 0;
    int b = a;
    while( b > 0 ){
        cont++;
        b /= 10;
    }
    for( int i = cont-1; i >= 0; i-- ){
        numero[i] = (a % 10) + '0';
        a /= 10;
    }
    longitud = cont;
}
int main() {
    cin>>numero;
    for( ;numero[longitud];longitud++);
    while( !(longitud == 1 && numero[0] == '0') ){

        sort(numero,numero+longitud);
        int b =  convierte();
        sort(numero,numero+longitud, alrevez );
        int a = convierte();
        int diferencia = a - b;
        int ferret = 1;
        while( cadenas.count(diferencia) == 0 ){
            cadenas.insert(diferencia);
            hazCopia(diferencia);
            sort(numero,numero+longitud);
            b =  convierte();
            sort(numero,numero+longitud, alrevez );
            a = convierte();
            diferencia = a - b;
            ferret++;
        }
        cout<<"Chain length "<<ferret<<endl;
        ferret = 1;
        longitud = 0;
        cadenas.clear();
        cin>>numero;
        for( ;numero[longitud];longitud++);
    }
}
