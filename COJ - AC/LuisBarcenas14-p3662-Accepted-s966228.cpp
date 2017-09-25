#include <iostream>

using namespace std;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int p28[] = {1,2,4,7,14};
int p496[] = {1,2,4,8,16,31,62,124,248};
int p8128[] = {1,2,4,8,16,32,64,127,254,508,1016,2032,4064};
int j =0,p,c,pt;
int a;

void generar(){
    j=0;
    p=primos[j];
    while(p*p<=c){
        pt=p;
        while(c%p==0){
             cout<<pt<<" "<<(c/p)<<endl;
             pt*=p;
             c/=p;
        }
        p=primos[++j];
    }
}

void imprimir(int p[20]){
    for(j=1;p[j]!='\0';j++){
        cout<<" + "<<p[j];
    }
    cout<<endl;
}

int main()
{
    ios;
    while(cin>>a && a!=-1){
        switch(a){
            case 6:
                cout<<a<<" = 1 + 2 + 3"<<endl;
            break;
            case 28:
                cout<<a<<" = "<<p28[0];
                imprimir(p28);
            break;
            case 496:
                cout<<a<<" = "<<p496[0];
                imprimir(p496);
            break;
            case 8128:
                cout<<a<<" = "<<p8128[0];
                imprimir(p8128);
            break;
            default:
                cout<<a<<" is NOT perfect."<<endl;
            break;
        }
    }
    return 0;
}
