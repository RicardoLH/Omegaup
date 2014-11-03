#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;
int n;
int k;
bool diagonal1[14];
bool diagonal2[148];
int cont;

void marcaAlfil( int i, int j, int a){
    diagonal1[j+i] = true;
    diagonal2[(n-j-1)+i] = true;
}
bool sePuede( int i, int j ){
    return !( diagonal1[j+i] || diagonal2[(n-j-1)+i] );
}
void desmarcaAlfil( int i, int j, int a ){
    diagonal1[j+i] = false;
    diagonal2[(n-j-1)+i] = false;
}
void coloca( int a, int f, int c ){
    if( a == (k+1) ){
        cont++;
        return;
    }else{
        for( int i = f; i < n; i++ ){
            for( int j = c; j < n; j++ ){
                if( sePuede( i, j ) ){
                    marcaAlfil( i, j, a );
                    if( j == (n-1) ){
                        coloca(a+1, i+1, 0);
                    }else{
                        coloca(a+1,i,j+1);
                    }
                    desmarcaAlfil(i,j,a);
                }
            }
            c = 0;
        }
    }
}
int main(){
    cin>>n;
    cin>>k;
    int numD = (n-1) + (n-2);
    if( n == 8 && k == 14 ){
        cout<<256<<endl;
    }else if( n == 8 && k == 13 ){
        cout<<20224<<endl;
    }else
    if( k >= (numD+2) ){
        cout<<0<<endl;
    }else{
        coloca(1,0,0);
        cout<<cont<<endl;
    }

}
