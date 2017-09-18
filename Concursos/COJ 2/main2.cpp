#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define pb push_back
#define MAX  1001
#define mod 1000000007


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    lli sum=0;
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            continue;
        }else{
            sum+=(s[i]-'a'+1);
        }

    }
    cout<<sum<<endl;

}

