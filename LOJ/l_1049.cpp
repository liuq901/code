#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[110],a[210][3];
int dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (y==1)
            return(a[i][1]);
        return(a[i][1]+dfs(y,x));
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=0,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        int ans=1<<30;
        for (int i=b[1];i;i=a[i][2])
        {
            int y=a[i][0];
            ans=min(ans,a[i][1]+dfs(y,1));
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

