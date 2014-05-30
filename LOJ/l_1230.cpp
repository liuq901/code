#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
int b[1010],a[2010][2];
bool vis[1010];
pair <int,int> f[1010][2];
inline pair <int,int> best(const pair <int,int> &a,const pair <int,int> &b)
{
    return(a.first<b.first || a.first==b.first && a.second>b.second?a:b);
}
inline pair <int,int> update(const pair <int,int> &a,const pair <int,int> &b)
{
    return(make_pair(a.first+b.first,a.second+b.second));
}
void dp(int x,int father)
{
    vis[x]=true;
    f[x][0]=make_pair(0,0);
    f[x][1]=make_pair(1,0);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x);
        f[x][0]=update(f[x][0],f[y][1]);
        f[x][1]=update(f[x][1],best(f[y][0],update(f[y][1],make_pair(0,1))));
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(vis,0,sizeof(vis));
        pair <int,int> ans(0,0);
        for (int i=1;i<=n;i++)
            if (!vis[i])
            {
                dp(i,0);
                pair <int,int> now=best(f[i][0],f[i][1]);
                ans=update(ans,now);
            }
        static int id=0;
        printf("Case %d: %d %d %d\n",++id,ans.first,ans.second,m-ans.second);
    }
    return(0);
}

