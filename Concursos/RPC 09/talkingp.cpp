#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    //cin>>n;
    //getline(cin, n);
    cin>>n;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        for(int i=0; s[i]!='\0'; i++){
            if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')
                cout<<'p'<<s[i]<<'p';
            else
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
