#include <iostream>

using namespace std;
long long int memo[33][33];
int n;
int m;
int main(){
    cin>>n;
    cin>>m;
    n += 1;
    m += 1;
    memo[n][m] = 1;
    for( int i = n; i >= 0; i-- ){
        for( int j = m; j >= 0 ; j-- ){
            if( (i+1) <= n ){
                memo[i][j] += memo[i+1][j];
            }
            if( (j+1) <= m ){
                memo[i][j] += memo[i][j+1];
            }
        }
    }
    cout<<memo[1][1];
}
