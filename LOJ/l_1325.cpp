#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
const int mod=100000007,m=10000;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        map <int,int> M;
        int now=1;
        for (int i=0;i<m;i++)
        {
            if (!M.count(now))
                M[now]=i;
            now=ll(now)*a%mod;
        }
        int tmp=1;
        for (int i=0;;i++)
        {
            int t=ll(b)*power(tmp,mod-2)%mod;
            if (M.count(t))
            {
                static int id=0;
                printf("Case %d: %d\n",++id,i*m+M[t]);
                break;
            }
            tmp=ll(tmp)*now%mod;
        }
    }
    return(0);
}

