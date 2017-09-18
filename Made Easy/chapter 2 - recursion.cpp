#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool isSorted(int A[], int n){
    if(n==1){
        return A[n]>=A[n-1];
    }
    bool band = A[n]>=A[n-1];
    return band &= isSorted(A, n-1);
}

char A[100];

void Binary(int n){
    if(n < 1){
        printf("%s",A);
    }else{
        A[n-1] = '0';
        Binary(n-1);
        A[n-1] = '1';
        Binary(n-1);
    }
}


/*
void kString(int n, int k){
    if(n<1)
        printf("%s", A);
    else{
        for(int j=0; j<k; j++){
            A[n-1] = j+'0';
            kString(n-1, k);
        }
    }
}
*/







void kString(int n, int k){
    if(n<1)
        printf("%s", A);
    else{
        for(int j=0; j<k; j++){
            A[n-1] = j+'0';
            kString(n-1, k);
        }
    }
}



int main(){
    int arr[5] = {2,4,6,7,7};
    //cout<<isSorted(arr, 5-1);
    //Binary(3);
    kString(2, 10);
    return 0;
}
