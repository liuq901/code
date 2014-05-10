#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[110];
double b[110],f[10010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double P;
        int n,m=0;
        scanf("%lf%d",&P,&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%lf",&a[i],&b[i]);
            if (b[i]==1)
            {
                i--,n--;
                continue;
            }
            b[i]=log(1-b[i]);
            m+=a[i];
        }
        for (int i=0;i<=m;i++)
            f[i]=-1e100;
        f[0]=0;
        for (int i=1;i<=n;i++)
            for (int j=m;j>=a[i];j--)
                f[j]=max(f[j],f[j-a[i]]+b[i]);
        for (int i=m;i>=0;i--)
        {
            double now=1-exp(f[i]);
            if (now<=P)
            {
                static int id=0;
                printf("Case %d: %d\n",++id,i);
                break;
            }
        }
    }
    return(0);
}

