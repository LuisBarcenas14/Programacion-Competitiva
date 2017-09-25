#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vi::const_iterator viit;
#define MAX 1000010
#define w 78500
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

bool criba[MAX];
int f1[w][2];
int f2[w][2];
vi primos;
lli i,j,k;
lli r1,r2;

void generarPrimos(){
    k=0;
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            f1[k][0]=f2[k][0]=i;
            primos.push_back(i);
            k++;
            for(j=i*i;j<MAX;j+=i)
                criba[j]=true;
        }
    }
}

int binarySearch( const vector<int>& vec, int z)
{
    pair<vector<int>::const_iterator, vector<int>::const_iterator> bounds;

    bounds = equal_range(vec.begin(),vec.end(), z);

    if (bounds.first != vec.end())
       return (bounds.first -vec.begin());

    else
       return -1;
}

lli pot(lli b, lli e){
    lli r =1;
    while(e--){
        r*=b;
    }
    return r;
}

void fact(int n){
    i=0;
    j=primos[i];
    while(j*j<=n){
        if(n%j==0){
            k=0;
            while(n%j==0){
                k++;
                n/=j;
            }
            int m = binarySearch(primos,j);
            //cout<<"J: "<<j<<" M: "<<m<<" - "<<primos[m]<<endl;
            f1[m][1] +=k;
        }
        j=primos[++i];
    }
    if(n!=1){
        int m = binarySearch(primos,n);
        //cout<<"J: "<<j<<" M: "<<m<<" - "<<primos[m]<<endl;
        f1[m][1] +=1;
    }
}

void fact2(int n){
    i=0;
    j=primos[i];
    while(j*j<=n){
        if(n%j==0){
            k=0;
            while(n%j==0){
                k++;
                n/=j;
            }
            int m = binarySearch(primos,j);
            //cout<<"J: "<<j<<" M: "<<m<<" - "<<primos[m]<<endl;
            f2[m][1] +=k;
        }
        j=primos[++i];
    }
    if(n!=1){
        int m = binarySearch(primos,n);
        //cout<<"J: "<<j<<" M: "<<m<<" - "<<primos[m]<<endl;
        f2[m][1] +=1;
    }
}

void imp(){
    for(i=0;i<primos.size();i++){
        if(f1[i][1]!=0){
            cout<<f1[i][0]<<": "<<f1[i][1]<<endl;
        }
    }
}

void reset(){
    for(i=0;i<primos.size();i++){
        if(f1[i][1]!=0 && f2[i][1]!=0){
            //Restar exponentes
            if(f1[i][1] >= f2[i][1]){
                f1[i][1]-=f2[i][1];
                f2[i][1]=0;
            }else{
                f2[i][1]-=f1[i][1];
                f1[i][1]=0;
            }
            r1 *= pot(f1[i][0],f1[i][1]);
            r2 *= pot(f2[i][0],f2[i][1]);
        }else if(f1[i][1]!=0){
            r1 *= pot(f1[i][0],f1[i][1]);
        }else if(f2[i][1]!=0){
            r2 *= pot(f2[i][0],f2[i][1]);
        }
    }
    cout<<r1<<" / "<<r2<<endl;
    for(i=0;i<primos.size();i++){
        f1[i][1]=f2[i][1]=0;
    }

}

int main()
{
    ios;
    //freopen("in","r",stdin);
    generarPrimos();
    int t,a,b,x;
    cin>>t;
    for(int i=1;i<=t;i++){
        r1=r2=1;
        cin>>a>>b;
        cout<<"Case #"<<i<<": ";
        while(a--){
            cin>>x;
            fact(x);
        }
        while(b--){
            cin>>x;
            fact2(x);
        }
        //imp();
        reset();
    }
    return 0;
}



