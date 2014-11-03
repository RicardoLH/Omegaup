#include <math.h>
#include <iostream>

using namespace std;
unsigned long long int n;
unsigned long long int n2;
unsigned long long int bitsPotencias[51];
unsigned long long int trianguloPascal[52];
int main(){
    cin>>n;
    if( n % 2 != 0 ){
        n = n -1;
    }
    n2 = n;
    int potencia = -1;
    while( n2 > 0 ){
        n2 = n2 >> 1;
        potencia++;
    }
    trianguloPascal[0] = 1;
    unsigned long long int suma = 0;
    for( int i = 1; i <= potencia; i++ ){
        suma = 0;
        for( int j = i; j >= 1; j-- ){
            if( j == i ){
                trianguloPascal[j] = 1;
            }else{
                trianguloPascal[j] = trianguloPascal[j] + trianguloPascal[j-1];
            }
            suma += ( trianguloPascal[j] * j );
        }
        bitsPotencias[i] = suma + 1;
    }
    /*for( int i = 0; i <= potencia; i++ ){
        cout<<(i+1)<< " : "<< bitsPotencias[i]<<endl;
    }*/
    if( n == ( n &~ (n-1) ) ){
        cout<<bitsPotencias[potencia -1];
    }else{
        unsigned long long int respuesta = bitsPotencias[potencia] - 1;
        int cont = 0;
        unsigned long long int temp = n;
        while( temp > 0 ){
            temp -= (temp &~ (temp-1));
            cont++;
        }
        n = n >> 1;
        int espacios = 0;
        while( n > 0 ){

            if( n % 2 == 0 ){
                //cout<<"es par y restaremos el numero de unos a la derecha, por el numero de combinaciones " << cont+1 << " , "<<pow(2,espacios)<<endl;
                respuesta -= ( cont + 1 ) * pow(2,espacios);
                if( espacios != 0 ){
                    respuesta -= ( bitsPotencias[espacios] - 1 );
                    //cout<< " restando potencia: " <<bitsPotencias[espacios];
                }

            }else{
                cont--;
            }
            n = n >> 1;
            espacios++;
/*
            cout<<" ahora espacios es: " <<espacios<<endl;
            cout<<"bits prendidos "<<cont<<endl;*/
        }
        cout<<respuesta<<endl;
    }

}
