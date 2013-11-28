#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=(1ULL<<63)-1;
ll a[4000000],s[4000000];
int main()
{
    int n;
    for (int i=1;;i++)
    {
        ll x=ll(i)*(i+1)>>1;
        if (inf-s[i-1]<x)
        {
            s[n=i]=inf;
            break;

        }
        s[i]=s[i-1]+x;
    }
    for (int i=1;i<=n;i++)
        a[i]=a[i-1]+i;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll m;
        scanf("%lld",&m);
        int layer=lower_bound(s+1,s+n+1,m)-s;
        m-=s[layer-1];
        int row=lower_bound(a+1,a+layer+1,m)-a;
        m-=a[row-1];
        printf("%d %d %d\n",layer,row,int(m));
    }
    return(0);
}

