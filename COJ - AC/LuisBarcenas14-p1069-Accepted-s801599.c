#include <stdio.h>

int main()
{
    int n, i, e, f, c, r, rt, div, mod;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&e,&f,&c);
        r=0;
        e += f;
        div = e/c;
        mod = e%c;
        r += div;
        e = div + mod;
        while(div != 0){
            if(c==1){
                r=0;
                break;
            }
            div = e/c;
            mod = e%c;
            e = div + mod;
            r += div;
        }
        printf("%d\n",r);
    }
    return 0;
}