#include <cstdio>
#include <algorithm>
using namespace std;
int l[1010],r[1010],a[1010],b[1010];
void insert(int x,int y)
{
    if (!l[x])
        l[x]=y;
    else
    {
        int p=l[x];
        while (r[p])
            p=r[p];
        r[p]=y;
    }
}
int f[1010][110];
void dp(int x)
{
    for (int i=l[x];i;i=r[i])
    {
        dp(i);
        for (int j=b[x];j>=0;j--)
            for (int k=0;k<=min(j,b[i]);k++)
                f[x][j]=max(f[x][j],f[x][j-k]+f[i][k]);
    }
    for (int i=b[x];i>=a[x];i--)
        f[x][i]=max(f[x][i],f[x][i-a[x]]+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int fa;
        scanf("%d%d%d",&fa,&a[i],&b[i]);
        insert(fa,i);
    }
    int ans=0;
    for (int i=l[0];i;i=r[i])
    {
        dp(i);
        ans+=f[i][b[i]];
    }
    printf("%d\n",ans);
    return(0);
}

