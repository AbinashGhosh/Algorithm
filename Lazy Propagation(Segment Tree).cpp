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
#define MAX 100007
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
int arr[MAX];
struct info
{
    int prop,sum;
}tree[MAX*3];
void init(int node ,int b,int e)
{
    tree[node].prop=0;                          //clear previous case info
    if(b==e)                                    // if we found a leaf of the tree
    {
        tree[node].sum=arr[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e||j<b)return;                          //Is segment not a relevent segment
    if(b>=i&&e<=j)                               // Relevent segment
    {
        tree[node].sum+=((e-b+1)*x);             //add propagate value for all leaf of the segment
        tree[node].prop+=x;                      // Store the propagate value
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j) return tree[node].sum+(e-b+1)*carry;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
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
