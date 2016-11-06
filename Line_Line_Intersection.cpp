#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define READ(f) freopen(f, "r", stdin)
using namespace std;

typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef vector<pii> vpii;
pdd r;
bool LLI(pii a,pii b,pii c,pii d)
{
    int a1,b1,c1,a2,b2,c2;
    a1=b.y-a.y;
    b1=a.x-b.x;
    c1=a1*a.x+b1*a.y;
    a2=d.y-c.y;
    b2=c.x-d.x;
    c2=a2*c.x+b2*c.y;
    double det=a1*b2-a2*b1;
    if(det==0) return false;
    else
    {
        r.x=(b2*c1-b1*c2)/det;
        r.y=(a1*c2-a2*c1)/det;
    }
    return true;
}
int main()
{
    //READ("in.txt");
    int x,y,i;
    vpii p;
    for(i=1;i<=4;++i)
    {
        scanf("%d%d",&x,&y);
        p.pb(mp(x,y));
    }
    if(LLI(p[0],p[1],p[2],p[3]))
        printf("Intersect at (%lf,%lf)\n",r.x,r.y);
    else
        printf("Lines are parallel\n");
    return 0;
}




