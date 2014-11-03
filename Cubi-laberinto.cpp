#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct Cuarto{
    bool N;
    bool O;
    bool S;
    bool E;
    bool U;
    bool D;
    bool visitado;
};
struct Cola{
    int x;
    int y;
    int z;
    int t;
};

int n;
int k;
char libres[7];
Cuarto lab[105][105][105];
Cola cola[(105*105*105)];
int inicio = 0;
int fin = 0;
int xf;
int yf;
int zf;
bool termino(int i, int j, int z ){
    return ((xf == i) && (yf == j) && (zf == z));
}
Cola saca(){
    inicio++;
    return cola[inicio];
}
bool correcta(int c){
    return ( c >= 0 && c < n );
}
void mete( int x, int y, int z, int t ){
    lab[x][y][z].visitado = true;
    fin++;
    cola[fin].x = x;
    cola[fin].y = y;
    cola[fin].z = z;
    cola[fin].t = t;
}
int main(){

    cin>>n;
    cin>>k;
    cin>>xf;
    cin>>yf;
    cin>>zf;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            for( int z = 0; z < n; z++ ){
                cin>>libres;
                int l = strlen(libres);
                for( int g = 0; g < l; g++ ){
                    if( libres[g] == 'N' ){
                        lab[i][j][z].N = true;
                    }else if( libres[g] == 'O' ){
                        lab[i][j][z].O = true;
                    }else if( libres[g] == 'S' ){
                        lab[i][j][z].S = true;
                    }else if( libres[g] == 'E' ){
                        lab[i][j][z].E = true;
                    }else if( libres[g] == 'U' ){
                        lab[i][j][z].U = true;
                    }else if( libres[g] == 'D' ){
                        lab[i][j][z].D = true;
                    }
                }
            }
        }
    }
    mete(0,0,0,0);
    bool llego= false;
    Cola temp = saca();
    mete(0,0,0,0);
    while(!termino(temp.x, temp.y, temp.z)&&inicio<=fin){
            //cout<<"coodenadas actuales "<< temp.x <<" "<< temp.y <<" " <<temp.z<<endl;
            //cout<<"tiempo: " << temp.t<<endl;
            temp = saca();
            if(  lab[temp.x][temp.y][temp.z].E  && correcta(temp.x+1)   ){
                if( !lab[temp.x+1][temp.y][temp.z].visitado ){
                    mete(temp.x+1,temp.y,temp.z,temp.t+1 );
                }
            }
            if(  lab[temp.x][temp.y][temp.z].O  && correcta(temp.x-1)  ){
                if( !lab[temp.x-1][temp.y][temp.z].visitado ){
                    mete(temp.x-1,temp.y,temp.z,temp.t+1 );
                }
            }
            if(  lab[temp.x][temp.y][temp.z].N  && correcta(temp.y+1)  ){
                if( !lab[temp.x][temp.y+1][temp.z].visitado ){
                    mete(temp.x,temp.y+1,temp.z,temp.t+1 );
                }
            }
            if(  lab[temp.x][temp.y][temp.z].S  && correcta(temp.y-1)   ){
                if( !lab[temp.x][temp.y-1][temp.z].visitado ){
                    mete(temp.x,temp.y-1,temp.z,temp.t+1 );
                }
            }
            if(  lab[temp.x][temp.y][temp.z].U  && correcta(temp.z+1)   ){
                if( !lab[temp.x][temp.y][temp.z+1].visitado ){
                    mete(temp.x,temp.y,temp.z+1,temp.t+1 );
                }
            }
            if(  lab[temp.x][temp.y][temp.z].D  && correcta(temp.z-1)  ){
                if( !lab[temp.x][temp.y][temp.z-1].visitado ){
                    mete(temp.x,temp.y,temp.z-1,temp.t+1 );
                }
            }





    }
    if(temp.t>(k*2)||!termino(temp.x, temp.y, temp.z)){
        cout<<"Impossibru"<<endl;
    }else{

        if( temp.t % 2 == 0 ){
            cout<<(temp.t/2)<<endl;
        }else{
            cout<<(temp.t/2)<<".5"<<endl;
        }
    }

    return 0;
}
