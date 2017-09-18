#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void hanoi(int n, char a, char b, char c){
    if(n==0){
        return;
    }
    hanoi(n-1, a, c, b);
    printf("%d de %c a %c\n",n,a,c);
    hanoi(n-1, b, a, c);
}

int main(){
    hanoi(25, 'A', 'B', 'C');
    return 0;
}
