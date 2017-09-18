#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define endl '\n'

int A[100001];

void SlidingWindow(int A[], int n, int s, int K=0, int sum=0){
    //cout<<"n: "<<n<<" s: "<<s<<endl;
    deque<ii> window;
    int minK=1<<30;
    for(int i=0; i<n; i++){
        //cout<<"I: "<<i<<endl;
        /*
        //Eliminar anterior en caso que sea mayor al elemento actual
        while(!window.empty() && window.back().first >= A[i]){
            cout<<"Elimina atras: "<<window.back().first<<endl;
            window.pop_back();
        }
        */

        window.push_back(ii(A[i], i));
        K++;
        sum+=A[i];
        //cout<<"Agrega: "<<window.back().first<<endl;


        //Eliminar último en caso que sea más grande que lo permitido
        while( (sum-window.front().first) >= s){
            //cout<<"Elimina adelante: "<<window.front().first<<endl;
            sum-=window.front().first;
            window.pop_front();
            K--;
        }
        //cout<<"sum: "<<sum<<endl;
        if(K<minK && sum>=s){ minK=K; }

        //if(i+1 >= K)
        //  printf("%d\n",window.front().first);
    }
    if(minK==1<<30)
        cout<<"0\n";
    else
        cout<<minK<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int A[]={1,3,5,7};
    //int A[]={8,6,4,2};
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n,s;

    while(cin>>n>>s){
        for(int i=0;i<n;i++)
            cin>>A[i];
        SlidingWindow(A, n, s);
    }

    return 0;
}
