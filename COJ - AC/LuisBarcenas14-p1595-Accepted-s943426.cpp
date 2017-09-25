#include <iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

char s[1001];
char s2[1001];
int a,b,i,j;
bool b1, b2;

void divisible9(char s[]){
    j=0;
    b1=true;
    b2=false;
    int z = 3;
    while(b1){
        b=0;
        for(i=0;s[i]!='\0';i++){
            b+=s[i]-'0';
        }
        if(b%9==0){
            j++;
            if(b==9){
                b1=false;
                b2=true;
            }
            sprintf(s,"%d",b);
        }else{
            b1=false;
        }
    }
    //999999999999999999999 is a multiple of 9 and has 9-degree 3.
    if(b2){
        cout<<" is a multiple of 9 and has 9-degree "<<j<<"."<<endl;
    }else{
        cout<<" is not a multiple of 9."<<endl;
    }
}


int main()
{
    ios;
    while(cin>>s && strcmp(s,"0")){
        cout<<s;
        divisible9(s);
    }
    return 0;
}

