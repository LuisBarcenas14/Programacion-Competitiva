#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    int n,a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        if(a-b >= 0)
            printf("SI\n");
        else
            printf("NO\n");
    }
    return 0;
}
