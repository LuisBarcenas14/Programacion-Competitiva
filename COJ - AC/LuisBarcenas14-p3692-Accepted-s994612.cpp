#include <bits/stdc++.h>

using namespace std;

int i,j;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int main()
{
    ios;
    int n;
    int mod, coc;
    string par[9]={"11","22","33","44","55","66","77","88","99"};
    string impar[9]={"1098","209","319","429","539","649","759","869","979"};
        //"1098"
    while(cin>>n && n){
        switch(n){
            case 1:
            case 3:
            case 5:
            case 7:
            case 9:
                cout<<"-1"<<endl;
                break;
            default:
                if(n%2==0){
                    n-=2;
                    n/=2;
                    mod=n%9;
                    coc=n/9;
                    if(coc==0){
                        cout<<par[mod]<<endl;
                    }else{
                        cout<<par[mod];
                        for(i=0; i<coc; i++){ cout<<"99";}
                        cout<<endl;
                    }
                }else{
                    if(n<27){
                        n-=11;
                        n+=2;
                        n/=2;
                        cout<<impar[n]<<endl;
                    }else{
                        n-=9;
                        n/=2;
                        mod=n%9;
                        coc=n/9;
                        if(mod==0){
                            cout<<impar[mod];
                            cout<<"9";
                            for(i=1; i<coc; i++){ cout<<"99";}
                            cout<<endl;
                        }else{
                            cout<<impar[mod];
                            for(i=0; i<coc; i++){ cout<<"99";}
                            cout<<endl;
                        }
                    }
                }
                break;
        }
    }
    return 0;
}
