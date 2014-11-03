#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int pila[1002];
int tope = -1;
int n;
int val;
int main() {
    cin>>n;
    cin>>val;
    pila[++tope] = 0;
    pila[++tope] = val;
    for( int i = 1; i < n; i++ ){
        cin>>val;
        pila[++tope] = val;
        int actual = pila[tope];
        while( pila[tope-1] == actual ){
            pila[--tope] = actual + actual;
            actual *= 2;
        }
    }
    cout<<tope<<endl;
    for( int i = tope; i > 0; i-- ){
        cout<<pila[i]<<endl;
    }


}
