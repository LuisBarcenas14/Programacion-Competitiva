#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MAX 100001
#define x 17//x  1000003
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int i,j,n,m,a;
bool b1, b2;
double l1, l2, lt;
int r;

int main()
{
    ios;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n;
    l1=l2=0;
    for(i=0;i<n;i++){
        cin>>a;
        lt = log(a);
        l1 += lt;
        //cout<<"LT: "<<lt<<" L1: "<<l1<<endl;
    }
    l1 = l1/log(x);
    //cout<<"L1: "<<l1<<endl;
    cin>>m;
    for(i=0;i<m;i++){
        cin>>a;
        lt = log(a);
        l2 += lt;
        //cout<<"LT: "<<lt<<" L2: "<<l2<<endl;
    }
    l2 = l2/log(x);
    //cout<<"L2: "<<l2<<endl;
    if(l1==l2){
        cout<<"="<<endl;
    }else if(l1>l2){
        cout<<">"<<endl;
    }else{
        cout<<"<"<<endl;
    }
    return 0;
}
