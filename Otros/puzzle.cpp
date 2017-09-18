#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    freopen("outP", "w", stdout);
    char A[9];
    int a,b;
    char a2;
    int t=20;
    //cout<<"\' \'";
    while(true){
        //cout<<"Cambiar: ";
        cin>>a>>b;
        //1ra parte
        bool band=false,band2=false;
        cout<<"s(tablero(";
        for(int i=1; i<=9 || !band; i++){
            if(i==a){ cout<<"\' \'"; band=true; }
            else printf("%c",((i-1-band)+'A'));
            if(i==b) a2=(i-1-band)+'A';
            if(i<9) cout<<", ";
        }
        cout<<"), ";

        //2da parte
        cout<<"tablero(";
        for(int i=1; i<=9; i++){
            //if(i==a) printf("%c",( (b-2)+'A'));
            if(i==a) {band2=true; printf("%c",a2); }
            else if(i==b) cout<<"\' \'";
            else printf("%c", ( (i-1-band2)+'A')) ;
            if(i<9) cout<<", ";
        }
        cout<<")).\n";
    }

}


