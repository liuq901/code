#include <cstdio>
#include <algorithm>
using namespace std;
int s[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
        }
    int ans=-1<<30;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int x=i;x<=n;x++)
                for (int y=j;y<=n;y++)
                    ans=max(ans,s[x][y]-s[i-1][y]-s[x][j-1]+s[i-1][j-1]);
    printf("%d\n",ans);
    return(0);
}

