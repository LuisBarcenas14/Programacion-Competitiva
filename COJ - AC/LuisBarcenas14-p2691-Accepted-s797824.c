#include <stdio.h>

int main()
{
    int n,m,i,s1=0,s2=0,t1,t2,j;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++){
        scanf("%d",&t1);
        s1 = s1 + t1;
    }
    for(j=0;j<m;j++){
        scanf("%d",&t2);
        s2 = s2 + t2;
    }
    if(s1>s2) printf("first win");
        else
            if(s1<s2) printf("second win");
        else
            printf("tie");
    return 0;
}