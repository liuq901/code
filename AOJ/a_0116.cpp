#include <cstdio>
#include <algorithm>
using namespace std;
char a[510][510];
int f[510][510];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                f[i][j]=a[i][j]=='*'?0:f[i-1][j]+1;
                int now=1<<30;
                for (int k=j;k;k--)
                {
                    now=min(now,f[i][k]);
                    ans=max(ans,now*(j-k+1));
                }
            }
        printf("%d\n",ans);
    }
    return(0);
}

