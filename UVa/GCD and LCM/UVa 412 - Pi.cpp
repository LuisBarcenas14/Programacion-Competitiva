#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int num[51];

int main(){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int a, n, c;
    while(scanf("%d", &n) && n){
        c=0;
        for(int i=0; i<n; i++){
            scanf("%d",&num[i]);
        }
        for(int i=0,j=1; i<=n-2; ){
            //printf("*%d %d %d\n",num[i], num[j], __gcd(num[i], num[j]));
            if(__gcd(num[i], num[j])==1){ c++; }
            j++;
            if(j==n){ i++; j=i+1; }
        }
        //printf("c: %d nC2: %d\n",c, (n*(n-1)/2));
        double nC2 =double(n*(n-1)/2);
        double x = sqrt(6*nC2/c);
        if(c==0)
            printf("No estimate for this data set.\n");
        else
            printf("%.6f\n",x);
    }
    return 0;
}



