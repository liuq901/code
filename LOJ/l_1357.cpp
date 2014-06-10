#include <cstdio>
#include <cstring>
typedef long long ll;
ll ans;
int cnt[100010],b[100010],a[200010][2];
void dfs(int x,int father)
{
    cnt[x]=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dfs(y,x);
        ans+=ll(cnt[x])*cnt[y];
        cnt[x]+=cnt[y];
    }
    cnt[x]++;
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
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        ans=0;
        dfs(1,0);
        static int id=0;
        printf("Case %d: %d %lld\n",++id,n-1,ans);
    }
    return(0);
}

