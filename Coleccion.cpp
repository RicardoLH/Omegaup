#include <iostream>

using namespace std;
struct Carta{
    unsigned short int precio;
    unsigned short int puntaje;
};
Carta cartas[505];
int memo[10005];
unsigned short int d;
unsigned short int n;
int main()
{
    cin>>d;
    cin>>n;
    for( unsigned short int i = 1; i <= n; i++ ){
        cin>>cartas[i].precio;
        cin>>cartas[i].puntaje;
    }
    int toma = 0;
    unsigned short int i = 1;
    unsigned short int j = 1;
    for(  i = 1; i <= d; i++ ){
        for( j = d; j >= 1; j-- ){
            toma = 0;
            if( j >= cartas[i].precio ){
                toma = memo[j-cartas[i].precio] + cartas[i].puntaje;
            }
            memo[j] = max( memo[j], toma );
        }
    }
    cout<<memo[d];
    

    return 0;
}
