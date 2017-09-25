#include <iostream>
#include <string>
using namespace std;
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int t,n,sum,i;
string s;

int tres(char a, char b){
    if(a=='0'){
        if(b=='0'){ return 0; }else{ return 1;}
    }else{
        if(b=='0'){ return 2; }else{ return 3;}
    }
}

void esDivisivle(string s){
    n = s.size();
    i=sum=0;
    if(n%2==1){
        if(s[0]=='1'){ sum++; }
        i++;
    }
    for(;i<n;i+=2){
        sum+=tres(s[i], s[i+1]);
    }
    if(sum%3==0){ cout<<"YES"<<endl; }else{ cout<<"NO"<<endl; }
}

int main()
{
    ios;
    cin>>t;
    while(t--){
        cin>>s;
        esDivisivle(s);
    }
    return 0;
}
