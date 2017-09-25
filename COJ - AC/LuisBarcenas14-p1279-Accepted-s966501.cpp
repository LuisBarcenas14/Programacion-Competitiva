#include <iostream>

using namespace std;
typedef long long int lli;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 1000010

lli i,j,f,s;
bool criba[MAX];
int fp[MAX];
int ff[MAX];
int a,b;

void generarPrimos(){
    f=0;
    s=1;
    criba[0]=criba[1]=true;
    ff[0]=ff[1]=fp[0]=fp[1]=0;
    ff[2]=ff[3]=ff[4]=s;
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            f++;
            fp[i]=f;
            if(i%4==1){ s++; }
            ff[i]=s;
            for(j=i*i;j<MAX;j+=i){
                criba[j]=true;
            }
        }else{
            fp[i]=f; ff[i]=s;
        }
    }
}

int main()
{
    ios;
    generarPrimos();
    while(cin>>a>>b && (a!=-1 || b!=-1)){
        if(a<=0){
            if(b<=0){ f=s=0; }else{ f=fp[b]; s=ff[b]; }
        }else{ f=(fp[b]-fp[a-1]); s=(ff[b]-ff[a-1]); }
        cout<<a<<" "<<b<<" "<<f<<" "<<s<<endl;
    }
    return 0;
}
