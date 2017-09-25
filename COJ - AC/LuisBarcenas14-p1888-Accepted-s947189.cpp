#include <string>
#include <iostream>
using namespace std;
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

string s;
int t,a,i,l;
bool b1,b2,b3;

void evil(string s){
    t=0;
    b1=b2=b3=false;
    if(s[0]!='-'){t+= (s[0]-48);}
    if(s[0]=='6'){b1=true;}
    for(i=1;s[i]!='\0';i++){
        if(s[i]=='6'){b1=true;}else{t += (s[i]-48);}
    }
    if(t%6==0){
        b2=true;
    }
    l = s.size()-1;
    if(t%3==0 && (s[l]=='0'||s[l]=='2'||s[l]=='4'||s[l]=='6'||s[l]=='8')){b3=true;}
    //cout<<b1<<" "<<b2<<" "<<b3<<endl;
    if(b1&&b2&&b3){cout<<"EVIL"<<endl;}else{cout<<"GOOD"<<endl;}
}

int main()
{
    ios;
    while(cin>>s){
        evil(s);
    }
    return 0;
}
