#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define MAX 1000010
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

bool criba[MAX];
int f[MAX];
lli i,j;
int a, b;
void generarPrimos(){
    f[0]=f[1]=0;
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            f[i]=f[i-1]+1;
            for(j=i*i;j<MAX;j+=i){
                criba[j]=true;
            }

        }else{
            f[i]=f[i-1];
        }
    }
}

int main()
{
    ios;
    generarPrimos();
    while(cin>>a>>b && a){
         printf("%d\n",f[b]-f[a-1]);
    }
    return 0;
}
