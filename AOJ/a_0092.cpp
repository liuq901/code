#include <cstdio>
#include <algorithm>
using namespace std;
int f[1010][1010],l[1010][1010],u[1010][1010];
char a[1010][1010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (a[i][j]=='*')
                {
                    l[i][j]=f[i][j]=u[i][j]=0;
                    continue;
                }
                l[i][j]=l[i][j-1]+1;
                u[i][j]=u[i-1][j]+1;
                f[i][j]=min(f[i-1][j-1]+1,min(l[i][j],u[i][j]));
                ans=max(ans,f[i][j]);
            }
        printf("%d\n",ans);
    }
    return(0);
}

