#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[110],c[110],a[110][110],b[110][110];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j]=a[i][j];
                if (b[i][j]==0)
                    b[i][j]=(1<<30)-1;
            }
        for (int i=1;i<=n;i++)
            b[i][i]=0;
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&c[i]);
            c[i]++;
        }
        memset(f,63,sizeof(f));
        f[1]=0;
        for (int i=2;i<=m;i++)
            for (int j=1;j<i;j++)
            {
                int S=c[j],T=c[i-1];
                bool flag=true;
                for (int k=j+1;k<i;k++)
                {
                    int x=c[k-1],y=c[k];
                    if (b[S][x]+a[x][y]+b[y][T]!=b[S][T])
                    {
                        flag=false;
                        break;
                    }
                }
                if (flag)
                    f[i]=min(f[i],f[j]+1);
            }
        int ans=1<<30;
        for (int i=1;i<=m;i++)
        {
            bool flag=true;
            for (int j=i+1;j<=m;j++)
            {
                int S=c[i],T=c[m],x=c[j-1],y=c[j];
                if (b[S][x]+a[x][y]+b[y][T]!=b[S][T])
                {
                    flag=false;
                    break;
                }
            }
            if (flag)
                ans=min(ans,f[i]);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

