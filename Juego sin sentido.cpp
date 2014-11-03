#include <iostream>
#include <algorithm>

using namespace std;
bool bolitas[130];
int n;
int m;
int contador;
void busca( int r, int d, int t){
    if( r == 0 && t == m  ){
        bool correcto = true;
        int anterior = 0;
        int i = 1;

        while( correcto && i <= n ){
            for( int j = (i+1); j <= n; j++ ){
                if( bolitas[i] && bolitas[j] ){
                    if( bolitas[i+j] ){
                        correcto = false;
                        break;
                    }
                }
            }
            i++;
        }
        if( correcto ){
                contador++;
        }
    }
    if( t > m ){
        return;
    }
    if( d > r ){
        return;
    }
    bolitas[d] = true;
    busca( r-d, d+1, t+1 );
    bolitas[d] = false;
    busca( r,d+1,t);
}
int main(){
    cin>>n;
    cin>>m;
    busca(n,1,0);
    cout<<contador<<endl;
}
