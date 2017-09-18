#include<bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef long long ll;
#define endl '\n'

bool solucion(vvc g){
	for(int i=0; i<4; i++){
		if(g[0][i]!='R') return false;
		if(g[1][i]!='G') return false;
		if(g[2][i]!='B') return false;
		if(g[3][i]!='Y') return false;
	}
	return true;
}

void copia(char g[4][4], char _g[4][4]){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++)
			g[i][j]=_g[i][j];
	}
}

vvc giroFila(vvc g, int i, int inc){
	char t, t2;
	int j;
	if(inc < 0)
		t=g[i][3], j=2, g[i][3]=g[i][0];
	else
		t=g[i][0], j=1, g[i][0]=g[i][3];

	for(; j<4 && j>=0; j+=inc){
		t2=g[i][j];
		g[i][j]=t;
		t=t2;
	}
	return g;
}

vvc giroCol(vvc g, int j, int inc){
	char t, t2;
	int i;
	if(inc < 0)
		t=g[3][j], i=2, g[3][j]=g[0][j];
	else
		t=g[0][j], i=1, g[0][j]=g[3][j];

	for(; i<4 && i>=0; i+=inc){
		t2=g[i][j];
		g[i][j]=t;
		t=t2;
	}
	return g;
}



void imprimirG(vvc g){
	cout<<"-------------------------------------\n";
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
}

int res=-1;

int rubik(vvc g, int nivel){
	if(solucion(g)){
		cout<<"Resuelto\n";
		cout<<"nivel: "<<nivel<<endl;
		//imprimirG(g);
		return nivel;
	}else if(nivel>2)
		return -1;

	for(int i=0; i<4; i++){
		//cout<<"n1\n";
		int n;
		if( res==-1 && (n = ( rubik(giroCol(g , i,  1), nivel+1) ) ) != -1){ res=n; return n; }
		if( res==-1 && (n = ( rubik(giroFila(g, i,  1), nivel+1) ) ) != -1){ res=n; return n; }
		if( res==-1 && (n = ( rubik(giroFila(g, i, -1), nivel+1) ) ) != -1){ res=n; return n; }

		if( res==-1 && (n = ( rubik(giroCol(g , i, -1), nivel+1) ) ) != -1){ res=n; return n; }
	}

	return -1;
}

int main(){
	freopen("in.txt", "r", stdin);
	vvc g;
	char c;
	vc vv;
	for(int i=0; i<4; i++){
		g.push_back(vv);
		for(int j=0; j<4; j++){
			cin>>c;
			g[i].push_back(c);
		}
	}
	imprimirG(g);
	imprimirG(giroCol(g, 3, 1));
	//cout<<rubik(g, 0)<<endl;
	return 0;
}
