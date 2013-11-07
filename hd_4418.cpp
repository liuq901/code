#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int N,m,n;
bool escape[210],vis[210];
int q[210],p[210];
bool bfs(int X)
{
    int l,r;
    q[l=r=1]=X;
    memset(vis,0,sizeof(vis));
    vis[X]=true;
    while (l<=r)
    {
        int x=q[l++];
        if (escape[x])
            continue;
        for (int i=1;i<=m;i++)
        {
            if (p[i]==0 || vis[(x+i)%(2*N-2)])
                continue;
            q[++r]=(x+i)%(2*N-2);
            vis[q[r]]=true;
        }
    }
    for (int i=0;i<2*N-2;i++)
        if (escape[i] && vis[i])
            return(true);
    return(false);
}
double *a[210],b[210],c[210][210];
void gauss()
{
    for (int i=1;i<=n;i++)
        a[i]=c[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
            if (fabs(a[j][i])>fabs(a[i][i]))
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            double p=a[j][i]/a[i][i];
            for (int k=i;k<=n;k++)
                a[j][k]-=a[i][k]*p;
            b[j]-=b[i]*p;
        }
    }
}
int id[210];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Y,X,D;
        scanf("%d%d%d%d%d",&N,&m,&Y,&X,&D);
        for (int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        if (N==1)
        {
            printf("0.00\n");
            continue;
        }
        if (D==1)
            X=2*N-X-2;
        memset(escape,0,sizeof(escape));
        escape[Y]=escape[2*N-Y-2]=true;
        if (!bfs(X))
            printf("Impossible !\n");
        else
        {
            n=0;
            for (int i=0;i<2*N-2;i++)
                if (vis[i])
                    id[i]=++n;
            memset(c,0,sizeof(c));
            memset(b,0,sizeof(b));
            for (int i=0;i<2*N-2;i++)
            {
                if (!vis[i])
                    continue;
                int x=id[i];
                c[x][x]+=1;
                if (escape[i])
                    continue;
                for (int j=1;j<=m;j++)
                {
                    if (p[j]==0)
                        continue;
                    int y=id[(i+j)%(2*N-2)];
                    c[x][y]-=p[j]/100.0;
                    b[x]+=p[j]*j/100.0;
                }
            }
            gauss();
            printf("%.2f\n",b[id[X]]/a[id[X]][id[X]]);
        }
    }
    return(0);
}

