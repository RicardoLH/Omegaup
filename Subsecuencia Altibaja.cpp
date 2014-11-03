#include <iostream>

using namespace std;
int n;
int num[1002];
int memo[1002][1002][2];
int maximo(int i, int j, int k ){
    if( i < 0  ){
        return 0;
    }
    if( memo[i][j][k] == 0 ){
        int toma = -100;
        int nToma = maximo(i-1,j,k);
        if( k == 0 && num[i] > num [j] ){
            toma = maximo(i-1,i,1);
        }else if( k == 1 && num[i] < num[j] ){
            toma = maximo(i-1,i,0);
        }
        memo[i][j][k] = max(nToma,toma + 1);
    }
    return memo[i][j][k];
}
int main()
{
    cin>>n;
    for( int i = 0; i < n; i++ ){
        cin>>num[i];
    }
    num[n] = num[n-1] - 1;
    int first = maximo(n-1,n,0);
    num[n] = num[n-1] + 1;
    int last = maximo(n-1,n,1);
    cout<<max(first,last);

    return 0;
}
