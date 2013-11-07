#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010],b[1010],ans[1010];
bool vis[1010];
void getans(int *a,int n,int m)
{
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;i++)
    {
        int k=0;
        for (int j=1;j<=n;j++)
            if (!vis[j] && a[j]>a[k])
                k=j;
        vis[k]=true;
        ans[i]=k;
    }
    sort(ans+1,ans+m+1);
    for (int i=1;i<=m;i++)
        printf("%d%c",ans[i],i==m?'\n':' ');
}
int main()
{
    int n,m,K,L,D;
    scanf("%d%d%d%d%d",&n,&m,&K,&L,&D);
    for (int i=1;i<=D;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (y1==y2)
            a[min(x1,x2)]++;
        else
            b[min(y1,y2)]++;
    }
    getans(a,n,K);
    getans(b,m,L);
    return(0);
}

