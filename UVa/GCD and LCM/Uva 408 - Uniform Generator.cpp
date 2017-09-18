#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main(){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    //5    Good Choice
    int a,b,g;
    while(scanf("%d %d", &a, &b) ==2){
        if(__gcd(a,b)==1)
            printf("%10d%10d    Good Choice\n\n",a,b);
        else
            printf("%10d%10d    Bad Choice\n\n",a,b);
    }
    return 0;
}


