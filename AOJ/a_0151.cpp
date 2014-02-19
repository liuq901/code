#include <cstdio>
#include <algorithm>
using namespace std;
char a[300][300];
int b[300][300],c[300][300],d[300][300],e[300][300];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",a[i]+1);
            e[i][n+1]=0;
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (a[i][j]=='0')
                {
                    b[i][j]=c[i][j]=d[i][j]=e[i][j]=0;
                    continue;
                }
                b[i][j]=b[i-1][j]+1;
                c[i][j]=c[i][j-1]+1;
                d[i][j]=d[i-1][j-1]+1;
                e[i][j]=e[i-1][j+1]+1;
                ans=max(ans,max(max(b[i][j],c[i][j]),max(d[i][j],e[i][j])));
            }
        printf("%d\n",ans);
    }
    return(0);
}

