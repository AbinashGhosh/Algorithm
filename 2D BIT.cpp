/**************************************************
    _¦¦¦¦¦¦_    ¯¦¦¦¦¦¦¦¦_    ¯¦¦¦    ¦¦¦¯   _¦
   _¦¦    ¦¦_    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦___¦¦¯     ¦¦¦____¦¦¦   ¦¦¦
   ¦¦¦¦¦¦¦¦¦¦    ¦¦¦¯¯¯¦¦_     ¦¦¦¯¯¯¯¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
  _¦¦¦    ¦¦¦_  _¦¦¦¦¦¦¦¦¯    _¦¦¦    ¦¦¦_  ¦¯
***************************************************/
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
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
#include <limits>
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

#define MAX 1007
#define EPS 1e-9

///1-index
int tree[MAX][MAX];
int query(int x,int y1)
{
    int sum=0;
    while(x>0)
    {
        int y=y1;
        while(y>0)
        {
            sum+=tree[x][y];
            y-=y&(-y);
        }
        x-=x&(-x);
    }
    return sum;
}
void update(int x,int y1,int val,int n,int m)
{
    while(x<=n)
    {
        int y=y1;
        while(y<=m)
        {
            tree[x][y]+=val;
            y+=y&(-y);
        }
        x+=x&(-x);
    }
}
int rec_query(int x1,int y1,int x2,int y2)
{
   return  (query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1));
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,m,q,val,qtype;
    int x1,x2,y1,y2;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        mem(tree,0);
        scanf("%d%d%d",&n,&m,&q);
        FOR(i,1,n)
        {
            FOR(j,1,m)
            {
                scanf("%d",&val);
                update(i,j,val,n,m);
            }
        }
        FOR(i,1,q)
        {
            scanf("%d",&qtype);
            // For add val in pos index
            if(qtype==0)
            {
                scanf("%d%d%d",&x1,&y1,&val);
                update(x1,y1,val,n,m);
            }
            //For sum of all value  pos to nextpos(npos)
            else if(qtype==1)
            {
                scanf("%d%d",&x1,&y1);
                scanf("%d%d",&x2,&y2);
                int ans=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

