#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[100010],c[100010],d[100010],a[200010][3];
void dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        d[y]=d[x]+a[i][1];
        dfs(y,x);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<=n;i++)
            scanf("%d",&c[i]);
        memset(b,0,sizeof(b));
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
            sum+=z;
        }
        sum<<=1;
        dfs(0,-1);
        int ans=2147483647;
        for (int i=0;i<=n;i++)
            ans=min(ans,sum-d[i]+c[i]);
        printf("%d\n",ans);
    }
    return(0);
}

