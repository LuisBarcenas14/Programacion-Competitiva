#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define endl '\n'
#define MAX 1000001

void SlidingWindow4(int A[], int n, int K){
    deque<ii> window;
    for(int i=0; i<n; i++){
        //cout<<"I: "<<i<<endl;

        //Eliminar anterior en caso que sea mayor al elemento actual
        while(!window.empty() && window.back().first >= A[i]){
            //cout<<"Elimina atras: "<<window.back().first<<endl;
            window.pop_back();
        }


        window.push_back(ii(A[i], i));

        //Eliminar último en caso que sea más grande que lo permitido
        while(window.front().second <= i-K){
            //cout<<"Elimina adelante: "<<window.front().first<<endl;
            window.pop_front();
        }


        if(i+1 >= K)
            printf("%d\n",window.front().first);
    }
}

void SlidingWindow2(int A[], int n, int K){
    deque<ii> window;
    int f[n+1];
    memset(f, 0, sizeof f);
    int minL=1<<30,r=0, s=0;
    for(int i=0; i<n; i++){
        //cout<<"I: "<<i<<endl;

        window.push_back(ii(A[i], i));
        f[A[i]]++;
        s++;
        if(f[A[i]]==1 && A[i]<=K){ r++; }


        //Eliminar último en caso que sea más grande que lo permitido
        while( window.front().first>K || ( K==r && f[window.front().first]-1>=1 ) ){
            //cout<<"Elimina 1 adelante: "<<window.front().first<<endl;
            if(A[i]<=K){
                f[window.front().first]--;
            }
            s--;
            window.pop_front();
        }

        if(s<minL && r==K){ minL=s; }

        /*if(i+1 >= K)
            printf("r: %d front: %d minL: %d\n",r,window.front().first, minL);*/
    }

    if(minL==1<<30)
        cout<<"sequence nai"<<endl;
    else
        cout<<minL<<endl;
}

void generateSequence(int A[], int n, int m){
    for(int i=3;i<n;i++){
        A[i]=(A[i-3]+A[i-2]+A[i-1])%m+1;
    }
}

int main(){
    //int A[]={1,3,5,7};
    //int A[]={8,6,4,2};
    //int A[]={1, 2, 3, 7, 1, 12, 9, 11, 9, 6, 3, 7, 5, 4, 5, 3, 1, 10, 3, 3};
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    int A[]={ 0,5,5,3,10,0,4};
    int n=7, k=3;
    SlidingWindow4(A, n, k);
    return 0;
}
