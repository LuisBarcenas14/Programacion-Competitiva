#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX=1000010;

int digits(double n){
    int d=0;
    int entero= int(n);
    while(fabs(n - entero) > n * 1e-6){
        n*=10;
        entero= int(n);
        //cout<<n<<" "<<entero<<endl;
        ++d;
    }
    return d;
}

int pow(int n, int e){
    int res=1;
    while(e--){
        res*=n;
    }
    return res;
}

void res(int x, int j, int k, int d){
    int numerator, denominator;
    int g;
    if(j==0){
        numerator=x;
        denominator=pow(10, d);
    }else{
        numerator = x - x/pow(10, j);
        denominator = pow(10, d) - pow(10, k);
        //cout<<"num: "<<numerator<<" den: "<<denominator<<endl;
        //cout<<a<<" "<<b<<endl;

    }
    //printf("%d %d ",numerator,denominator);
    g=__gcd(numerator,denominator);
    numerator/=g;
    denominator/=g;
    printf("%d/%d\n",numerator,denominator);
}


int main(){
    //freopen("in", "r", stdin);
    //freopen("in", "r", stdin);
    int k,j,d,x,c=1;
    char s[10];
    while(scanf("%d", &j) && j!=-1){
        scanf(" 0.%s", s);
        //cout<<s<<endl;
        d=strlen(s);
        x=0;
        for(int i=0; i<d; i++){
            x= x*10 + (s[i]-'0');
        }
        k=d-j;
        //cout<<"d: "<<d<<" k: "<<k<<endl;
        printf("Case %d: ",c++);
        res(x, j, k, d);
    }
    return 0;
}

