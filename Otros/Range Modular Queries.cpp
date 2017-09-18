#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 40005;
const int B = 205;
int n , m , a[N];
vector<int> V[B][B] , W[N];

int count(vector<int> &v , int l , int r) {
  return upper_bound(v.begin() , v.end() , r) -
      lower_bound(v.begin() , v.end() , l);
}

int main() {
  scanf("%d%d" , &n , &m);
  for (int i = 0 ; i < n ; ++ i) {
    int x;
    scanf("%d" , &x);
    for (int j = 1 ; j <= B ; ++ j) {
      V[j][x % j].push_back(i);
    }
    W[x].push_back(i);
  }

  for (int i = 0 ; i < m ; ++ i) {
    int l , r , x , y;
    scanf("%d%d%d%d" , &l , &r , &x , &y);
    int res = 0;
    if (x <= B) {
      res = count(V[x][y] , l , r);
    } else {
      for (int k = y ; k < N ; k += x) {
        res += count(W[k] , l , r);
      }
    }
    printf("%d\n" , res);
  }
}
