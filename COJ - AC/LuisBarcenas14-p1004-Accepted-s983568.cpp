#include <iostream>
using namespace std;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

bool p1, p2;

void res(int a, int b){
    p1= b%2==0;
    p2= a%2==0;
    if(a==1 && b==1){
        cout<<'R'<<endl;
    }else if(b==1){
        cout<<'D'<<endl;
    }else if(a==1){
        cout<<'R'<<endl;
    }else if(a==b){
        if(p1&&p2){
            cout<<'L'<<endl;
        }else{
            cout<<'R'<<endl;
        }
    }else if(a<b){
        if(p1){
            if(p2){ //11
                cout<<'L'<<endl;
            }else{ //10
                cout<<'R'<<endl;
            }
        }else{
            if(p2){ //01
                cout<<'L'<<endl;
            }else{ //00
                cout<<'R'<<endl;
            }
        }
    }else{
        if(p1){
            if(p2){ //11
                cout<<'U'<<endl;
            }else{ //10
                cout<<'U'<<endl;
            }
        }else{
            if(p2){ //01
                cout<<'D'<<endl;
            }else{ //00
                cout<<'D'<<endl;
            }
        }
    }
}

int main()
{
    ios;
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        res(a,b);
    }
    return 0;
}
