#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans,a[10][10];
void dfs(int dep)
{
    if (dep==n+1)
    {
        int s[10]={0};
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                s[j]+=a[i][j];
        ans=min(ans,*max_element(s+1,s+n+1));
        return;
    }
    for (int i=1;i<=n;i++)
    {
        dfs(dep+1);
        rotate(a[dep]+1,a[dep]+2,a[dep]+n+1);
    }
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==-1)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        ans=1<<30;
        dfs(1);
        printf("%d\n",ans);
    }
    return(0);
}

