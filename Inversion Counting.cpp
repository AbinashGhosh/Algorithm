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
/*
Inversion Counting :

In merge process, let i is used for indexing left sub-array and j for right sub-array.
At any step in merge(), if a[i] is greater than a[j], then there are (n1–i+1) inversions.
Because left and right subarrays are sorted, so all the remaining elements in left-subarray
(a[i],a[i+1],a[i+2] … a[n1]) will be greater than a[j].

*/
int data[105];
int L[105],R[105],inv;
void Merge(int p,int q,int r)
{
    int n1= q-p+1;
    int n2= r-q;
    FOR(i,1,n1) L[i]=data[p+i-1];
    FOR(j,1,n2) R[j]=data[q+j];
    L[n1+1]=R[n2+1]=MAX;
    int i=1,j=1;
    FOR(k,p,r)
    {
        if(L[i]<=R[j])data[k]=L[i++];
        else {
            data[k]=R[j++];
              inv+=n1-i+1;
        }
    }
}
void  Mergesort(int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        Mergesort(p,q);
        Mergesort(q+1,r);
        Merge(p,q,r);
    }
}
int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
        scanf("%d",&data[i]);
    inv=0;
    Mergesort(1,N);
    pr(inv);
//    for(i=1; i<=N; i++)
//        printf("%d ",data[i]);

    return 0;
}

