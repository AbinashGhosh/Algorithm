//Abinash Ghosh
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
#include <ctime>
#include <cassert>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define ppr(a) cout<<a.x<<" "<<a.y<<"\n"
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

#define MAX 100007
#define EPS 1e-9
///Rotate a point CCW alpha radian w.r.t. origin(0,0)
inline pdd rotatePoint(double alpha , pdd a)
{
    if(fabs(alpha)<EPS)alpha=0.0;
    pdd r;
    r.x=a.x*cos(alpha)-a.y*sin(alpha);
    r.y=a.x*sin(alpha)+a.y*cos(alpha);
    return r;
}
///Rotate point a CCW alpha radian w.r.t. b
inline pdd rotatePointByB(double alpha , pdd a,pdd b)
{
    if(fabs(alpha)<EPS)alpha=0.0;
    pdd r;
    a.x-=b.x;
    a.y-=b.y;
    r.x=b.x+a.x*cos(alpha)-a.y*sin(alpha);
    r.y=b.y+a.x*sin(alpha)+a.y*cos(alpha);
    return r;
}
/// Rotate a line CCW alpha radian
inline void rotateLine(double alpha,pdd a,pdd b,pdd &c,pdd &d)
{
    pdd m;
    m.x=(a.x+b.x)/2;
    m.y=(a.y+b.y)/2;
    a.x-=m.x,a.y-=m.y;
    b.x-=m.x,b.y-=m.y;
    c=rotatePoint(alpha,a);
    d=rotatePoint(alpha,b);
    c.x+=m.x,c.y+=m.y;
    d.x+=m.x,d.y+=m.y;
}
/// angle from line ab to  x-axis(on point a) CCW
double angleofLine(pdd a,pdd b)
{
    return atan2(b.y-a.y,b.x-a.x);
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    pdd a=rotatePointByB(PI/4,mp(4.0,4.0),mp(1.0,1.0));
    double b=angleofLine(mp(1.0,1.0),mp(4.0,4.0));
    ppr(a);
    pr(b*180/PI);
    b=angleofLine(mp(3.0,9.0),mp(7.0,5.0));
    pr(b*180/PI);
    b=angleofLine(mp(7.0,5.0),mp(3.0,9.0));
    pr(b*180/PI);

    return 0;
}






