#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;
#define MAX 1000010
#define mod 10000000000
#define endl "\n"

int criba[MAX];
lli f[MAX];
int primos[MAX];
lli i, j,q, p;
int a,k,n2,n3,z;
char digitos[10];


void generarPrimos(){
    f[1]=1; f[2]=2;
    p=2;
    for(i=2,z=0;i<MAX;i++){
        q=p-1;
        if(!criba[i]){
            f[p]=(i*f[q])%mod; //PRIMORIAL
            primos[z++]=i;
            for(j=i*i;j<MAX;j+=i){
                criba[j] = 1;
            }
        }else{
            f[p] = f[q];
        }
        p++;
    }
}

int main()
{
    generarPrimos();
    scanf("%d",&k);
    while(k--){
        scanf("%d",&a);
        if(a>=31){
            printf("%010lld\n",f[a]);
        }else{
            printf("%lld\n",f[a]);
        }
    }
    return 0;
}