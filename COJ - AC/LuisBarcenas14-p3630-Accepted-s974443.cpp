#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int a;
double s,s1,s2,s3,x,p;


void suma(int n){
    s = n*(n+1)-n;
    p = s/n;
    printf("%lf %.6lf\n",s,p);
}

void estandar(int n){
    s1 = n*(n+1);
    x=(s1-n)/n;
    s = 2*(s1*(2*n+1))/3-2*s1+n;
    //printf("%lf %.6lf\n",s,x);
    s-=2*x*(s1-n);
    //printf("%.6lf\n",s);
    s+=x*x*n;
    s= s/(n-1);
    s = sqrt(s);
    printf("%.6lf\n",s);
}

int main()
{
    ios;
    while(cin>>a && a){
        //suma(a);
        estandar(a);
    }
    return 0;
}