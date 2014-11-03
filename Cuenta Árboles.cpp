#include <iostream>

using namespace std;
unsigned long long int memo[1000];
int n;

unsigned long long int encuentra( int n ){
    if( memo[n] == 0 ){
        unsigned long long int izq = ( 2*(encuentra(n-1)%1000000) ) %1000000;
        unsigned long long int sumatoria = 0;
        for( int i = 0; i <= n-3; i++ ){
            sumatoria += ((encuentra(i+1)%1000000) * (encuentra(n-2-i)%1000000))%1000000;
        }
        memo[n] = ( izq + sumatoria)%1000000;
    }
    return memo[n] % 1000000;
    
}
int main()
{
   cin>>n;
   memo[0] = memo[1] = 1;
   memo[2] = 2;
   cout<<encuentra(n)<<endl;
   
   
   return 0;
}
