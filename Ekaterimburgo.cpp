#include <stdio.h>
#include <queue>

using namespace std;
struct Nodo{
    int num;
    int peso;
    int padres[25];
    int cont = -1;
    void agregaPadre( int peso ){
        padres[++cont] = peso;
    }
};
bool operator<(Nodo a, Nodo b){
    if( a.peso == b.peso ){
        int inicio1 = a.cont;
        int inicio2 = b.cont;
        while( inicio1 >= 0 && inicio2 >= 0 ){
        	if( inicio1 < 0 ) inicio1 = 0;
        	if( inicio2 < 0 ) inicio2 = 0;
        	if( a.padres[inicio1] == b.padres[inicio2] ){
        		inicio1--;
        		inicio2--;
        	}else if( a.padres[inicio1] < b.padres[inicio2]){
        		return false;
        	}else{
        		return true;
        	}
        }
        /*printf("Pesos iguales: %d %d: \n", a.num, b.num);
        for( int i = 0; i <= a.cont; i++  ){
           printf(" %d ", a.padres[i] );
        }
        printf("\n");
        for(int i = 0; i <= b.cont; i++  ){
            printf(" %d ", b.padres[i] );
        }
        printf("\n");
        return true;*/
    }
    return a.peso > b.peso;
}
priority_queue<Nodo> mont;
int n;
int numNodos;
int main()
{
   scanf("%d",&n);
   numNodos = (1<<n)-1;
   Nodo temp;
   temp.num = 0;
   temp.peso = 0;
   mont.push(temp);
   while(mont.size() != 0){
       temp = mont.top();
       mont.pop();
       printf("%d\n", temp.num);
       if( (temp.num<<1)+1 < numNodos ){
           Nodo izq;
           izq.num = (temp.num<<1)+1;
           izq.peso = temp.peso+1;
           for( int i = 0; i <=  temp.cont; i++ ){
           		izq.agregaPadre(temp.padres[i]);
           }
           izq.agregaPadre(temp.peso);
           mont.push(izq);
       }
       if( (temp.num<<1)+2 < numNodos ){
           Nodo der;
           der.num = (temp.num<<1)+2;
           der.peso = temp.peso+2;
           for( int i = 0; i <=  temp.cont; i++ ){
           		der.agregaPadre(temp.padres[i]);
           }
           der.agregaPadre(temp.peso);
           mont.push(der);
       }
   }
   
   return 0;
}
