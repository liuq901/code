#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[60][1010];
int f[60][1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j].first);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j].second);
        for (int i=1;i<=n;i++)
            sort(a[i]+1,a[i]+m+1);
        memset(f,63,sizeof(f));
        for (int i=1;i<=m;i++)
        {
            f[0][i]=0;
            a[0][i].first=K;
        }
        for (int i=1;i<=n;i++)
        {
            int mi=1<<30,now=1;
            a[i][m+1].first=a[i][m].first;
            for (int j=1;j<=m;j++)
            {
                mi+=a[i][j].first-a[i][j-1].first;
                while (now<=m && a[i-1][now].first<=a[i][j].first)
                {
                    mi=min(mi,f[i-1][now]+a[i][j].first-a[i-1][now].first);
                    now++;
                }
                f[i][j]=min(f[i][j],mi+a[i][j].second);
            }
            mi=1<<30,now=m;
            for (int j=m;j;j--)
            {
                mi+=a[i][j+1].first-a[i][j].first;
                while (now>0 && a[i-1][now].first>=a[i][j].first)
                {
                    mi=min(mi,f[i-1][now]+a[i-1][now].first-a[i][j].first);
                    now--;
                }
                f[i][j]=min(f[i][j],mi+a[i][j].second);
            }
        }
        int ans=1<<30;
        for (int i=1;i<=m;i++)
            ans=min(ans,f[n][i]);
        printf("%d\n",ans);
    }
    return(0);
}

