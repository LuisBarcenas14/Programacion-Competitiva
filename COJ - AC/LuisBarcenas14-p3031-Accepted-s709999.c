#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int n,d;
    do{
        scanf("%d",&n);
        scanf("%d",&d);
        if(d!=0)
        printf("%d %d / %d\n",n/d,n%d,d);
    }while((n!=0)||(d!=0));
    return (EXIT_SUCCESS);
}