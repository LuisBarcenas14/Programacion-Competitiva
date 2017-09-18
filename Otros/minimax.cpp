#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAX = 10;

bool gano(char c, char tablero[MAX][MAX],int n){
    bool horizontal;
    for(int i=0; i<n; i++){
        horizontal=true;
        for(int j=0; horizontal && j<n; j++){
            if(tablero[i][j] != c)
                horizontal=false;
        }
        if(horizontal)
            return true;
    }
    bool vertical;
    for(int i=0; i<n; i++){
        vertical=true;
        for(int j=0; vertical && j<n; j++){
            if(tablero[j][i] != c)
                vertical=false;
        }
        if(vertical)
            return true;
    }
    bool diagonal1=true,diagonal2=true;
    for(int i=0, j=n-1; i<n; i++, j--){
        if(tablero[i][i]!=c)
            diagonal1=false;
        if(tablero[i][j]!=c)
            diagonal2=false;
    }
    return (diagonal1 || diagonal2);
}

bool lleno(int n,char tablero[MAX][MAX]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            if(tablero[i][j]=='_')
                return false;
    }
    return true;
}

int esFin(int n, char tablero[MAX][MAX]){
    if(gano('x', tablero, n))
        return 1; //cout<<"Gano X"<<endl;
    else if(gano('o', tablero, n))
        return 2; //cout<<"Gano O"<<endl;
    else if(lleno(n, tablero))
        return 0; //cout<<"empate"<<endl;
    else
        return -1;//cout<<"Juego en progreso"<<endl;
}

void dibujarTablero(int n, char tablero[MAX][MAX]){
    for(int i=0; i<n; i++){
        cout<<tablero[i][0];
        for(int j=1; j<n; j++)
            cout<<" | "<<tablero[i][j];

        cout<<endl;
        for(int k=0; k<n; k++)
            cout<<"---";
        cout<<endl;
    }
}

void reiniciar(int n, char tablero[MAX][MAX]){
    //tablero={{',',',',','},{',',',',','},{',',',',','}};
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            tablero[i][j]='_';
}

int main(){
    int n=3;
    char tablero[MAX][MAX];
    reiniciar(n, tablero);
    //esFin(n,tablero);
    bool jugar=true;
    int x,y,num,fin=-1;
    cout<<"El gato funciona de la siguiente forma:\nEn cada turno debe introducir un número del 1 al "<<n*n;
    cout<<" que no haya sido marcado.\nSiendo que la esquina superior izquierda es 1 y la esquina inferior derecha es "<<n*n<<endl;
    string s;
    while(jugar){
        for(int i=0; i<n*n; i++){
            cout<<"Introduzca un número de 1 a "<<n*n<<": ";

            while(cin>>num){
                num--;
                y=num%n;
                x=num/n;
                if(tablero[x][y] == '_')
                    break;
                cout<<"MARCADO teclee otro número: ";
            }
            if(i%2==0){
                tablero[x][y]='x';
            }else{
                tablero[x][y]='o';
            }
            //cout<<"hi"<<endl;
            fin = esFin(n, tablero);
            //cout<<"fin esFin xd"<<endl;
            dibujarTablero(n, tablero);
            if(fin>=0){
                if(fin==0)
                    cout<<"Empate"<<endl;
                else if(fin==1)
                    cout<<"Gano X"<<endl;
                else if(fin==2)
                    cout<<"Gano O"<<endl;
                break;
            }
        }
        cout<<"Desea iniciar una nueva partida? S/N ";
        cin>>s;
        if(!(s=="s" || s=="S"))
            jugar=false;
        reiniciar(n, tablero);
    }
    return 0;
}

