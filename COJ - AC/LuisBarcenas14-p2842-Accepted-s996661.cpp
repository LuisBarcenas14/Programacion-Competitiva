#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 10000010
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

bool criba[MAX];
short f[MAX];
lli i,j;

bool esPalindromo(lli n){
    if(n<10){
        return true;
    }
    int i=10000000,j=1;
    while(n/i==0){
        i/=10;
    }
    //cout<<"Comienzo N: "<<n<<" I: "<<i<<" J: "<<j<<endl;
    for(;i>=j;i/=10,j*=10){
        //cout<<(n/i)%(i/(i/10))<<" "<<n%(j*10)/(j)<<endl;
        //if(n/i!= n%(j*10)){ return false; }
        if((n/i)%(i/(i/10)) != n%(j*10)/(j)){ return false; }
    }
    return true;
    /*
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]){ return false; }
    }
    return true;
    */
}

void generarPrimos(){
    f[0]=0;
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            bool band= esPalindromo(i);
            if(band){ f[i]=f[i-1]+1; }else{ f[i]=f[i-1]; }
            for(j=i*i;j<MAX;j+=i){
                criba[j]=true;
            }
        }else{
            f[i]=f[i-1];
        }
    }
}

int main()
{
    ios;
    //freopen("in","r",stdin);
    generarPrimos();
    int q,a,b;
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<f[b]-f[a-1]<<endl;
    }
    //cout << "Hello world!" << endl;
    //bool t= esPalindromo(12355321);
    //cout<<"band: "<<t<<endl;
    return 0;
}
