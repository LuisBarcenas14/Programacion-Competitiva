#include<stdio.h>
#include<vector>
#include<iostream>
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAX 101

using namespace std;

typedef vector<int> vi;


int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
char mapa[MAX][MAX];
int R,C;


bool esValido(int r, int c){
	return (r>=0 && r < R && c >= 0 && c < C);
}

int floodfill(int r, int c, char c1, char c2){ //Retorna el tamaño del CC
	if(!esValido(r,c)) return 0; //Fuera de la cuadrícula
	if(mapa[r][c] != c1) return 0; //No es de color c1
	int ans = 1; //Suma 1 a ans porque el vérice (r,c) es de color c1
	mapa[r][c] = c2; //Colorea el vértice con c2, para evitar ciclos
	for(int d = 0; d < 8; d++)
		ans+= floodfill(r+dr[d],c+dc[d],c1,c2);
	return ans;
}

int main(){
    int i,j;
    while(cin>>R && R){
    C=R;
    for(i=0;i<R;i++){
        for(j=0;j<R;j++){
            cin >> mapa[i][j];
        }
    }
    int p,mini=2000000,maxi=0,islas=0;
    for(i=0;i<R;i++){
        for(j=0;j<R;j++){
            if(mapa[i][j]=='l'){
                p = floodfill(i, j, 'l', 's');
                if(p<mini){
                    mini = p;
                }
                if(p>maxi){
                    maxi=p;
                }
                islas++;
            }
        }
    }
    if(islas==0){
        printf("%d 0 %d\n",islas,maxi);
    }else{
        printf("%d %d %d\n",islas,mini,maxi);
    }

    }
    return 0;
}
