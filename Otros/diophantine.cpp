#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl '\n'

int x,y,d;

void extendEuclid(int a, int b){
    if(b==0){ x=1; y=0; d=a; return; }
    extendEuclid(b, a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int main(){
    int a,b,c,c2,t;
    while(cin>>a>>b>>c){
        extendEuclid(a,b);
        c2=c/d;
        x*=c2;
        y*=c2;
        cout<<x<<" "<<y<<endl;
        if(x<0){
            t=x/b - (x%b==0 ? 0 : 1);
            x-=t*b;
            y+=t*a;
        }
        //cout<<x<<" "<<y<<endl;
        if(y<0){
            t=y/a- (y%a==0 ? 0 : 1);
            x+=t*b;
            y-=t*a;
        }
        cout<<x<<" "<<y<<endl;
        //min x
        if(x>b){
            t=x/b-(x%b==0 ? 1 : 0);
            if(t!=0){
                x-=t*b;
                y+=t*a;
            }
        }
        cout<<x<<" "<<y<<endl;
        //min y
        if(y>a){
            t=y/a-(y%a==0 ? 1 : 0);
            if(t!=0){
                x+=t*b;
                y-=t*a;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
