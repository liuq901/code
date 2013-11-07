#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int tot,m,p[30],trip[30],c[30][210],f[30][210],pre[30][210][2];
vector <int> route[30];
queue <int> Q;
bool in[210];
map <int,int> M;
int hash(int x)
{
    if (!M.count(x))
        M[x]=M.size();
    return(M[x]);
}
void spfa(int id)
{
    for (int i=1;i<=tot;i++)
    {
        in[i]=true;
        Q.push(i);
    }
    while (!Q.empty())
    {
        int x=Q.front();
        in[x]=false;
        Q.pop();
        for (int i=1;i<=m;i++)
        {
            if (route[i][0]!=x)
                continue;
            for (int j=0;j<route[i].size();j++)
            {
                int y=route[i][j];
                if (f[id][x]+p[i]<f[id][y])
                {
                    f[id][y]=f[id][x]+p[i];
                    pre[id][y][0]=id;
                    pre[id][y][1]=x;
                    c[id][y]=i;
                    if (!in[y])
                    {
                        in[y]=true;
                        Q.push(y);
                    }
                }
            }
        }
    }
}
void print(int x,int y)
{
    if (x==1 && y==trip[1])
        return;
    print(pre[x][y][0],pre[x][y][1]);
    printf(" %d",c[x][y]);
}
int main()
{
    while (1)
    {
        scanf("%d",&m);
        if (m==0)
            break;
        M.clear();
        for (int i=1;i<=m;i++)
        {
            int K;
            scanf("%d%d",&p[i],&K);
            route[i].resize(K);
            for (int j=0;j<K;j++)
            {
                int x;
                scanf("%d",&x);
                route[i][j]=hash(x);
            }
        }
        tot=M.size();
        static int id=0;
        id++;
        int T,id2=0;
        scanf("%d",&T);
        while (T--)
        {
            int n;
            scanf("%d",&n);
            for (int i=1;i<=n;i++)
            {
                int x;
                scanf("%d",&x);
                trip[i]=hash(x);
            }
            memset(f,63,sizeof(f));
            f[1][trip[1]]=0;
            for (int i=1;i<=n;i++)
            {
                spfa(i);
                for (int j=1;j<=tot;j++)
                    for (int k=1;k<=m;k++)
                    {
                        if (route[k][0]!=j)
                            continue;
                        int t=i+1;
                        for (int l=0;l<route[k].size();l++)
                        {
                            if (t<=n && route[k][l]==trip[t])
                                t++;
                            if (t-1>i && f[i][j]+p[k]<f[t-1][route[k][l]])
                            {
                                f[t-1][route[k][l]]=f[i][j]+p[k];
                                pre[t-1][route[k][l]][0]=i;
                                pre[t-1][route[k][l]][1]=j;
                                c[t-1][route[k][l]]=k;
                            }
                        }
                    }
            }
            printf("Case %d, Trip %d: Cost = %d\n",id,++id2,f[n][trip[n]]);
            printf("  Tickets used:");
            print(n,trip[n]);
            printf("\n");
        }
    }
    return(0);
}

