#include <iostream>
using namespace std;
typedef long long int lli;
#define MAX 1000001
#define mod 1000003
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

lli p[MAX];
int i, a, t;

void perm(){
	p[0] = 0;
	p[1] = 1;
	for(i=2;i<MAX;i++){
		p[i] = (p[i-1] * i + 1)%mod;
	}
}

int main(){
	ios;
	perm();
	cin>>t;
	while(t--){
		cin>>a;
		cout<<p[a]<<endl;
	}
	return 0;
}