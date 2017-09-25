#include <stdio.h>
#include <math.h>

int main()
{
    int k,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &k);
        printf("%.0f\n",pow(2, k)-1);
    }
    return 0;
}
