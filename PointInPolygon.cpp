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
typedef vector<pdd> vpdd;
typedef vector<ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
vpdd p;
inline double cross(pdd A,pdd B,pdd C)
{
    return ((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
}
inline bool onsegment(pdd i,pdd j,pdd k)
{
    return (min(i.x,j.x)<=k.x&&k.x<=max(i.x,j.x)&&
            min(i.y,j.y)<=k.y&&k.y<=max(i.y,j.y));
}

bool PIP(pii r)
{
    int n=p.size();
    bool c=false;
    for (int i = 0, j = n-1; i < n; j = i++)
    {
        if(onsegment(p[i],p[j],r)&&!cross(p[i],p[j],r)) return true;//For the boundry case
        if (((p[i].y>r.y) != (p[j].y>r.y))&&
            (r.x<((p[j].x-p[i].x)*(r.y-p[i].y)/(p[j].y-p[i].y)+p[i].x)) )
            c = !c;
    }
    return c;
}
int main()
{
    //READ("in.txt");
    int N;
    double x,y;//number of point
    pdd r;

    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)break;
        for(int i=0; i<N; ++i)
        {
            scanf("%lf%lf",&x,&y);
            p.pb(mp(x,y));
        }
        scanf("%lf%lf",&x,&y);
        r=mp(x,y);
        if(PIP(r))
            printf("T\n",x,y);
        else
            printf("F\n",x,y);
        p.clear();
    }
    return 0;
}

