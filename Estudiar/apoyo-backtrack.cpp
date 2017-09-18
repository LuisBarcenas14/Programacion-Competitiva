#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void khe(int *n){
    *n=3;
    cout<<n<<endl;
    cout<<*n<<endl;
}

void reversa(string s, int k){
    //cout<<"s."<<s[k]<<endl;
    if(s[k]=='\0'){
        cout<<s[k];
        //return;
    }else
        reversa(s, k+1);
        cout<<s[k];
}

bool esPalindromoR(string s, int i, int j){
    //cout<<i<<":"<<s[i]<<" "<<j<<":"<<s[j]<<endl;
    if(s[i]==s[j] &&s[i]!='\0'){
        esPalindromoR(s,i+1,j-1);

    }else{
        return false;
    }
    return true;
}

int main(){
    int n;
    //n=10;
    //cout<<n<<endl;
    //khe(&n);
    //cout<<n<<endl;
    reversa("123456789",0);
    string s;
    cout<<"Palindromos"<<endl;
    while(cin>>s){
        cout<<esPalindromoR(s,0,s.size()-1)<<endl;
    }
    return 0;
}
