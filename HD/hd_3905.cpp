#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010],s[1010],f[1010][1010],g[1010][1010];
int main()
{
    int n,m,L;
    while (scanf("%d%d%d",&n,&m,&L)==3)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        for (int i=0;i<=m;i++)
        {
            f[i][0]=g[i][0]=-1<<30;
            if (i==0)
                f[i][0]=g[i][0]=0;
            for (int j=1;j<=n;j++)
            {
                f[i][j]=-1<<30;
                if (i>=1)
                    f[i][j]=max(f[i][j],f[i-1][j-1]);
                if (j>=L)
                    f[i][j]=max(f[i][j],g[i][j-L]+s[j]-s[j-L]);
                g[i][j]=max(g[i][j-1]+a[j],f[i][j]);
            }
        }
        printf("%d\n",f[m][n]);
    }
    return(0);
}

