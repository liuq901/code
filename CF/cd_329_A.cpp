#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[110][110];
int ans[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    memset(ans,-1,sizeof(ans));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]=='.')
            {
                ans[i]=j;
                break;
            }
    if (count(ans+1,ans+n+1,-1)==0)
        for (int i=1;i<=n;i++)
            printf("%d %d\n",i,ans[i]);
    else
    {
        memset(ans,-1,sizeof(ans));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (a[j][i]=='.')
                {
                    ans[i]=j;
                    break;
                }
        if (count(ans+1,ans+n+1,-1)==0)
            for (int i=1;i<=n;i++)
                printf("%d %d\n",ans[i],i);
        else
            printf("-1\n");
    }
    return(0);
}

