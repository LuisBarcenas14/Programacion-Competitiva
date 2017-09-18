#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;

int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    char s[50];
    long long a,b,b1,b2,acum,t;
    while( gets(s) ){
        if(sscanf(s,"%lld%lld",&a,&b)==2){
            if(a<0){ a=-a; }
            if(b<0){ b=-b; }
            acum=0;
            if(a>b){ t=a; a=b; b=t; }
            if(a&1){ a++; }
            while(a<=b){
                if(a%4!=0)
                    acum++;
                a+=2;
            }
            printf("%lld\n",acum);
        }else{
            bool band=false;
            if(a<0){ a=-a; band=true; }
            if(a==0){ printf("2 2\n"); continue; }
            if((a&1)||(a%4==0)){
                if(a&1){
                    b1=a/2;
                    b2=a/2+1;
                }else{
                    b1=a/4-1;
                    b2=a/4+1;
                }
                if(!band)
                    swap(b1,b2);
                printf("%lld% lld\n",b1,b2);
            }else{
                printf("Bachelor Number.\n");
            }

        }
    }
    return 0;
}
