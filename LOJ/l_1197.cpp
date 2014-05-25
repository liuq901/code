#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
bool f[50010];
int m,p[50010];
void init()
{
    const int n=50000;
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
}
bool ans[1000010];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==1)
            a=2;
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=m;i++)
        {
            if (ll(p[i])*p[i]>b)
                break;
            int t=a/p[i];
            if (t<p[i])
                t=p[i];
            while (ll(t)*p[i]<=b)
            {
                if (t*p[i]>=a)
                    ans[t*p[i]-a]=true;
                t++;
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,count(ans,ans+b-a+1,false));
    }
    return(0);
}

