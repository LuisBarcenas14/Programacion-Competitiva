#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int n,w;

struct Point{
    ll x;
    ll y;

    Point(){ x=y=0;}
    Point(ll _x, ll _y) : x(_x), y(_y){}
};

ll distanceP(Point j, Point i){
    return abs(i.x - j.x)+abs(i.y - j.y);
}

ll res(vector<Point> points, Point destination){
    ll r=0;
    for(int j=0; j<n; j++){
        r += distanceP(points[j], destination);
    }
    return r;
}

int main(){
    //freopen("in-points", "r", stdin);
    ll x,y;
    vector<Point> points;
    cin>>n;
    for(int j=0; j<n; j++){
        cin>>x>>y;
        points.push_back(Point(x, y));
    }
    cin>>w;
    for(int j=0; j<w; j++){
        cin>>x>>y;
        Point destination = Point(x, y);
        //cout<<"des x:"<<destination.x<<" y: "<<destination.y<<endl;
        cout<<res(points, destination)<<endl;
    }
    return 0;
}
