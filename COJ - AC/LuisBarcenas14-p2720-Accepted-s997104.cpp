#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 1010
#define endl '\n'

int i,j;
bool criba[MAX];
int f[MAX];
vector<int> primos;

void generarPrimos(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i)
                criba[j]=true;
        }
    }
    primos.push_back(0);
}

void generarK(){
    i=0;
    j=primos[i];
    i++;
    int s,j2;
    j2=primos[i];
    i++;
    f[0]=f[1]=0;
    while(j2!=0){
        s=j+j2+1;
        if(s<MAX && criba[s]==false){
            //cout<<j<<" + "<<j2<<" = "<<s<<endl,
            f[s]=1;
        }
        j=j2;
        j2=primos[++i];
    }

    for(i=2;i<MAX;i++){
        if(f[i]==0){ f[i]=f[i-1]; }else{ f[i]=f[i-1]+1; }
    }
}


int main()
{
    generarPrimos();
    generarK();
    int n,k;
    scanf("%d%d",&n,&k);
    if(k<=f[n]){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}

