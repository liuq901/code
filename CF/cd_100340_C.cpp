#include <cstdio>
#include <algorithm>
using namespace std;
bool have[110][210];
int to[110],send[110],request[110],ans[110],cnt[110],provide[210],a[110][110];
int main()
{
    freopen("epig.in","r",stdin);
    freopen("epig.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    fill(provide+1,provide+m+1,1);
    fill(have[1]+1,have[1]+m+1,true);
    cnt[1]=m;
    int tot=1;
    for (int t=1;;t++)
    {
        fill(request+1,request+n+1,-1);
        for (int i=1;i<=n;i++)
        {
            if (cnt[i]==m)
                continue;
            for (int j=1;j<=m;j++)
            {
                if (have[i][j])
                    continue;
                if (request[i]==-1 || provide[j]<provide[request[i]])
                    request[i]=j;
            }
        }
        fill(send+1,send+n+1,-1);
        for (int i=1;i<=n;i++)
        {
            if (cnt[i]==m)
                continue;
            int x=request[i];
            for (int j=1;j<=n;j++)
            {
                if (!have[j][x])
                    continue;
                if (send[i]==-1 || cnt[j]<cnt[send[i]])
                    send[i]=j;
            }
        }
        fill(to+1,to+n+1,-1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (send[j]!=i)
                    continue;
                if (to[i]==-1 || a[j][i]>a[to[i]][i] || a[j][i]==a[to[i]][i] && cnt[j]<cnt[to[i]])
                    to[i]=j;
            }
        for (int i=1;i<=n;i++)
        {
            if (to[i]==-1)
                continue;
            have[to[i]][request[to[i]]]=true;
            provide[request[to[i]]]++;
            a[i][to[i]]++;
            if (++cnt[to[i]]==m)
            {
                ans[to[i]]=t;
                tot++;
            }
        }
        if (tot==n)
            break;
    }
    for (int i=2;i<=n;i++)
        printf("%d%c",ans[i],i==n?'\n':' ');
    return(0);
}

