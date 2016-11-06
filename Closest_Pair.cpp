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
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
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
pii pnt[100005],py[100005];
bool comy(pii a,pii b)
{
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
inline double Distance(pii a,pii b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double closest_pair(int l,int r)
{
    //FOR(i,l,r)pr2(pnt[i].x,pnt[i].y);puts("END\n");
    if(l>=r)return 10000000;
    if(l+1==r)return Distance(pnt[l],pnt[r]);
    int mid=(l+r)/2;
    double dl=closest_pair(l,mid);
    double dr=closest_pair(mid+1,r);
    double d=min(dl,dr);
    int k=0;
    FOR(i,l,r)
        if(abs(pnt[i].x-pnt[mid].x)<d)
           py[k++]=pnt[i];
    //FOR(i,0,k-1)pr2(py[i].x,py[i].y);puts("END\n");
    sort(py,py+k,comy);
    FOR(i,0,k-1)
       for(int j=i+1;j<k&&(py[j].y-py[i].y)<d;j++)
         d=min(d,Distance(py[i],py[j]));
    return d;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int N;
    int  a,b;
    while(scanf("%d",&N))
    {
        FOR(i,0,N-1)
        {
            scanf("%d%d",&a,&b);
            pnt[i]=mp(a,b);
        }
        sort(pnt,pnt+N);
        double ans=closest_pair(0,N-1);
        pr(ans);
    }
    return 0;
}
