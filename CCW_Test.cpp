#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define READ(f) freopen(f, "r", stdin)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef pair<ll , ll > pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction



int ccw(pii a,pii b,pii c)
{
    int r=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    if(r<0) return -1;//A->B->C is a right turn
    if(r>0) return  1;//A->B->C is a left turn
    return 0;//A->B->C is a straight line/collinear
}
int main()
{
    //READ("in.txt");
    int N,x,y;
    vpii p;
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;++i)
        {
            scanf("%d%d",&x,&y);
            p.pb(mp(x,y));
        }
        p.pb(p[0]);
        p.pb(p[1]);
        int cv=0;
        for(int i=0;i<N;++i)
            if(ccw(p[i],p[i+1],p[i+2])<0)cv++;
        if(cv==0||cv==N) printf("Convex\n");//0 for ccw order and N for cw order
        else printf("Concave\n");
        p.clear();
    }
    return 0;
}


