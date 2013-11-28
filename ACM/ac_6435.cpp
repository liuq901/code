#include <cstdio>
#include <cstring>
const int mod=1000000009;
int a[50010],b[50010],f[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,D;
        scanf("%d%d%d",&n,&m,&D);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<m;i++)
            scanf("%d",&b[i]);
        a[n]=b[m]=1<<30;
        memset(f,0,sizeof(f));
        f[0]=1;
        int p=0;
        for (int i=0;i<=n;i++)
        {
            for (int j=p;j<=m;j++)
                if (b[j]<a[i]+D)
                {
                    f[j+1]+=f[j];
                    if (f[j+1]>=mod)
                        f[j+1]-=mod;
                }
                else
                    break;
            while (b[p]<=a[i]-D)
                f[p++]=0;
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,f[m]);
    }
    return(0);
}

