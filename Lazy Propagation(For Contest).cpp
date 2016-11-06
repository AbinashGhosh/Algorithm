/**************************************************
    _|||||_     -||||||||_    -|||    |||-   _|
   _||    ||_    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||___||-     |||____|||   |||
   ||||||||||    |||---||_     |||----|||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
  _|||    |||_  _||||||||-    _|||    |||_  |-
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

#define MAX 100007
#define EPS 1e-9

int arr[MAX],tree[MAX*3],prop[MAX*3];
void init(int n,int b,int e)
{
    prop[n]=0;
    if(b==e){
        tree[n]=arr[b];
        return;
    }
    int l=n<<1;
    int m=(b+e)/2;
    init(l,b,m);
    init(l+1,m+1,e);
    tree[n]=tree[l]+tree[l+1];
}
int query(int n,int b,int e,int i,int j,int c=0)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return tree[n]+(e-b+1)*c;
    int l=n<<1;
    int m=(b+e)/2;
    return query(l,b,m,i,j,c+prop[n])
          +query(l+1,m+1,e,i,j,c+prop[n]);
}

void update(int n,int b,int e,int i,int j,int v)
{
    if(i>e||j<b)return;
    if(b>=i&&e<=j){
        tree[n]+=(e-b+1)*v;
        prop[n]+=v;
        return;
    }
    int l=n<<1;
    int m=(b+e)/2;
    update(l,b,m,i,j,v);
    update(l+1,m+1,e,i,j,v);
    tree[n]=tree[l]+tree[l+1]+(e-b+1)*prop[n];
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n,q,qt,a,b,v;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        FOR(i,1,n)scanf("%d",&arr[i]);
        init(1,1,n);
        mem(tree,0);
        FOR(i,1,q)
        {
            scanf("%d",&qt);
            if(qt==0)
            {
                scanf("%d%d%d",&a,&b,&v);
                update(1,1,n,a,b,v);
            }
            else
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,1,n,a,b));
            }
        }
    }
    return 0;
}
/*
10 5
0 0 0 0 0 0 0 0 0 0
0 1 10 10
1 2 7
0 4 8 2
0 5 6 1
1 6 6

20 3
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 11 13 1
1 12 13
1 20 20
*/

