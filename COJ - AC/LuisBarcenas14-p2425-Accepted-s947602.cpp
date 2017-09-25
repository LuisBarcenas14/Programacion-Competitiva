#include <iostream>
#include <math.h>
#define x 17//1009
#define MAX 245010
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;
int a, b, n, i, li;
double l,lm;
int f[MAX][2];


int main()
{
    ios;
    while(cin>>n && n){
        i=li=lm=0;
        while(n--){
            cin>>a>>b;
            f[i][0]=a;
            f[i][1]=b;
            l = b*log(a) / log(x);
            if(l>lm){ lm = l; li = i; }
            i++;
        }
        cout<<f[li][0]<<" "<<f[li][1]<<endl;
    }
    return 0;
}