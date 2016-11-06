//Abinash Ghosh(Om)
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
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

pii p0,pnt[1000],res[1000];
inline int sqDistance(pii a,pii b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline int cross(pii a, pii b, pii c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
inline bool comp(pii a,pii b)
{
    int d=cross(p0,a,b);
    if(d<0||(!d&&sqDistance(p0,a)>sqDistance(p0,b)))return false;
    return true;
}
void makeunique(int &np)
{
    sort(pnt,pnt+np);
    np=unique(pnt,pnt+np)-pnt;
}
void convexHull(int np,int &nc)
{
   /// Remove duplicate points if necesary
    int pos=0;
    FOR(i,0,np-1)
       if(pnt[i].y<pnt[pos].y||(pnt[i].y==pnt[pos].y&&pnt[i].x<pnt[pos].x))
           pos=i;
    swap(pnt[0],pnt[pos]);
    p0=pnt[0];
    sort(pnt+1,pnt+np,comp);
    int j=0;
    FOR(i,0,np-1)
    {
        //use <= to remove colinear points
        pr2(pnt[i].x,pnt[i].y);
        while(j>=2&&cross(res[j-2],res[j-1],pnt[i])<=0)j--;
        res[j++]=pnt[i];
    }
    nc=j;
}
double angleBvector(pii o,pii a,pii b)
{
    pii c=mp(a.x-o.x,a.y-o.y);
    pii d=mp(b.x-o.x,b.y-o.y);
    double theta=atan2(d.y,d.x)-atan2(c.y,c.x);
    if(theta<0)theta+=2*PI;
    return theta;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int point,Bpoint;
    scanf("%d",&point);
    FOR(i,0,point-1)
        scanf("%d %d",&pnt[i].x,&pnt[i].y);
    makeunique(point);
    //works for point>2
    convexHull(point,Bpoint);
    pr(Bpoint);
    FOR(i,0,Bpoint-1)
        printf("%d %d\n",res[i].x,res[i].y);
    return 0;
}

/*
13
0 3
1 1
2 2
3 1
4 4
0 0
1 2
3 1
0 0
3 3
4 4
5 5
2 2


8
1 2
4 3
4 4
5 2
6 3
9 2
10 4
11 2
4
1 2
5 2
9 2
11 2
*/
