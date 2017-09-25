#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
//typedef vector<p> vp;
#define endl "\n"
#define MAX 1010
#define mp make_pair
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXM 169

bool criba[MAX];
lli i,j,k,z,e,et,pr;
vi primos;
//lli et,e,pr,sa,sb,sc,sd,sm,ta,tb,tc,td,tae,tbe,tce,tde,z;
int a,b,n2,mod;
lli ma1[MAXM][2];
lli mb1[MAXM][2];
lli mc1[MAXM][2];
lli md1[MAXM][2];
bool b1,b2;

//40 999 1000 3000000
void generarPrimos(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i){
                criba[j] = true;
            }
        }
    }
}

void imprimir(lli m[MAXM][2]){
    for(i=0;m[i][0]!='\0';i++){
        cout<<m[i][0]<<" "<<m[i][1]<<endl;
    }
    cout<<endl;
}

void prim(int a, lli m[MAXM][2]){
    j=0;
    pr = primos[j];
    e = 0;
    while(pr<=a){
        e=0;
        while(a%pr==0){
            a/=pr;
            e++;
        }
        m[j][0] = pr;
        m[j][1] = e;
        //vt.push_back(mp(pr,e));
        pr=primos[++j];
    }
}

void calculoM2(lli ma[MAXM][2], lli mb[MAXM][2],lli mc[MAXM][2]){
    for(i=0;i<MAXM;i++){
        mc[i][0]='\0';
        mc[i][1]='\0';
    }
    b1=b2=false;
    for(i=0,j=0,k=0;;){
        //cout<<"I: "<<i<<" "<<ma[i][0]<<" "<<ma[i][1]<<" J: "<<j<<" "<<mb[j][0]<<" "<<mb[j][1]<<endl;
        if(ma[i][0]==mb[j][0]){
            if(ma[i][1]+mb[j][1]>0){mc[k][0]= ma[i][0];mc[k][1]= ma[i][1]+mb[j][1];k++;}
            if(!b1){i++;}
            if(!b2){j++;}
        }else if((ma[i][0]<mb[j][0] && !b1) || (b2)){
            if(ma[i][1] > 0){mc[k][0]= ma[i][0]; mc[k][1]= ma[i][1]; k++;}
            if(!b1){i++;}
        }else if(mb[j][0]!='\0'){
            if(mb[j][1] > 0){mc[k][0]= mb[j][0]; mc[k][1]= mb[j][1]; k++;}
            if(!b2){j++;}
        }
        if(ma[i][0]=='\0' && !b1){b1=true;}
        if(mb[j][0]=='\0' && !b2){b2=true;}
        //cout<<"B1: "<<b1<<" B2: "<<b2<<endl;
        if(b1&&b2){break;}
    }
}

void factores(int n,int a, int b){
    for(i=0;i<MAXM;i++){
        ma1[i][0]='\0';
        ma1[i][1]='\0';
        mb1[i][0]='\0';
        mb1[i][1]='\0';
    }
    prim(a, ma1);
    prim(b, mb1);
    calculoM2(ma1,mb1,mc1);
    /*
    cout<<"MOD: 0"<<endl;
    imprimir(ma1);
    cout<<"MOD: 1"<<endl;
    imprimir(mb1);
    cout<<"MOD: 2"<<endl;
    imprimir(mc1);
    */
    if(n==2){
        imprimir(mc1);
    }else if(n>=3){
        for(z=3;z<=n;z++){
            mod = z%3;
            //cout<<"MOD: "<<z<<endl;
            switch(mod){
                case 0:
                    calculoM2(mb1,mc1,md1);
                    //imprimir(md1);
                break;
                case 1:
                    calculoM2(mc1,md1,mb1);
                    //imprimir(mb1);
                break;
                case 2:
                    calculoM2(md1,mb1,mc1);
                    //imprimir(mc1);
                break;
            }
        }
        mod = (z-1)%3;
            switch(mod){
                case 0:
                    imprimir(md1);
                break;
                case 1:
                    imprimir(mb1);
                break;
                case 2:
                    imprimir(mc1);
                break;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios;
    generarPrimos();
    int k;
    cin>>k;
    while(k--){
        cin>>n2>>a>>b;
        factores(n2,a,b);
        //cout<<"-----------------------"<<endl;
    }
    return 0;
}
