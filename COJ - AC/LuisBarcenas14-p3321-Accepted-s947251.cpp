#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define MAX 1000010
#define mod 10000000000
#define endl "\n"

bool criba[MAX];
lli f[MAX];
vi primos;
lli i, j,q, p;
int a,k,n2,n3;
char digitos[10];


void generarPrimos(){
    f[1]=1; f[2]=2;
    p=2;
    for(i=2;i<MAX;i++){
        q=p-1;
        if(!criba[i]){
            f[p]=(i*f[q])%mod; //PRIMORIAL
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i){
                criba[j] = true;
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