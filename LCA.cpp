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
#define MAX 1007
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
vi g[MAX];
int T[MAX];
int P[MAX][22];
int L[MAX];
void DFS(int from,int u,int dep) {
    T[u]=from;
    L[u]=dep;
    FOR(i,0,(int)g[u].size()-1) {
        int v=g[u][i];
        if(from==v)continue;
        DFS(u,v,dep+1);
    }
}
int lca_query(int p,int q) {
    if(L[p]<L[q])swap(p,q);
    int log=1;
    while(1<<(log+1)<=L[p])log++;
    for(int i=log; i>=0; i--)
        if(L[p]-(1<<i)>=L[q])
            p=P[p][i];
    if(p==q)return p;
    for(int i=log; i>=0; i--)
        if(P[p][i]!=-1&&P[p][i]!=P[q][i])
            p=P[p][i],q=P[q][i];
    return T[p];
}
int lca_querydist(int p,int q) {
    int res=0;
    if(L[p]<L[q])swap(p,q);
    int log=1;
    while(1<<(log+1)<=L[p])log++;
    for(int i=log; i>=0; i--)
        if(L[p]-(1<<i)>=L[q])
            p=P[p][i],res+=(1<<i);
    if(p==q)return res;
    for(int i=log; i>=0; i--)
        if(P[p][i]!=-1&&P[p][i]!=P[q][i])
            p=P[p][i],q=P[q][i],res+=(1<<(i+1));
    if (p != q)res += 2;
    return res;
}
void lca_init(int n) {
    mem(P,-1);
    FOR(i,0,n-1) P[i][0]=T[i];
    for(int j=1; 1<<j<n; j++)
        FOR(i,0,n-1)
        if(P[i][j-1]!=-1)
            P[i][j]=P[P[i][j-1]][j-1];
}
int main() {
    int edges,N,n1,n2,Q;
    scanf("%d%d",&N,&edges);
    FOR(i,1,edges) {
        scanf("%d%d",&n1,&n2);
        g[n1].pb(n2);
    }
    DFS(0,0,0);
    lca_init(N);
    scanf("%d",&Q);
    FOR(i,1,Q) {
        scanf("%d%d",&n1,&n2);
        printf("%d\n",lca_query(n1,n2));
    }
    return 0;
}



