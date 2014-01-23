#include <cstdio>
#include <algorithm>
using namespace std;
int a[110][110],s[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
        }
    int ans=-1<<30;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int k=i;k<=n;k++)
                for (int l=j;l<=n;l++)
                    ans=max(ans,s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1]);
    printf("%d\n",ans);
    return(0);
}

