#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int inf,d[410],q[410],b[410],a[500000][2],e[500000][2];
vector <int> ans[410];
void bfs(int S)
{
    int l,r;
    q[l=r=1]=S;
    memset(d,63,sizeof(d));
    inf=d[0];
    d[S]=0;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (d[y]==inf)
            {
                d[y]=d[x]+1;
                q[++r]=y;
            }
        }
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
        int n,m,S,T;
        scanf("%d%d%d%d",&n,&m,&S,&T);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
            e[i][0]=x,e[i][1]=y;
        }
        bfs(S);
        if (d[T]==inf)
        {
            printf("%d\n",m);
            for (int i=1;i<=m;i++)
                printf("1 %d\n",i);
        }
        else
        {
            for (int i=1;i<=d[T];i++)
                ans[i].clear();
            for (int i=1;i<=m;i++)
            {
                int x=e[i][0],y=e[i][1];
                if (d[x]==inf)
                    ans[1].push_back(i);
                else
                {
                    int p=max(d[x],d[y]);
                    ans[p].push_back(i);
                }
            }
            printf("%d\n",d[T]);
            for (int i=1;i<=d[T];i++)
            {
                printf("%d",ans[i].size());
                for (int j=0;j<ans[i].size();j++)
                    printf(" %d",ans[i][j]);
                printf("\n");
            }
        }
        if (cas)
            printf("\n");
    }
    return(0);
}

