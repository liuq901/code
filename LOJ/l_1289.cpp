#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
bitset <100000010> f;
int m,p[6000000];
unsigned s[6000000];
void init()
{
    const int n=100000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
    s[0]=1;
    for (int i=1;i<=m;i++)
        s[i]=s[i-1]*p[i];
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        unsigned ans=s[upper_bound(p+1,p+m+1,n)-p-1];
        for (int i=1;i<=m;i++)
        {
            if (p[i]*p[i]>n)
                break;
            int cnt=-1,tmp=n;
            while (tmp>=p[i])
            {
                cnt++;
                tmp/=p[i];
            }
            for (int j=1;j<=cnt;j++)
                ans*=p[i];
        }
        static int id=0;
        printf("Case %d: %u\n",++id,ans);
    }
    return(0);
}

