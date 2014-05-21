#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int tot,S,T,b[210],a[1000000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[210],q[210];
bool build()
{
    int l,r;
    q[l=r=1]=S;
    memset(d,0,sizeof(d));
    d[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y] || !a[i][1])
                continue;
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==T)
                return(true);
        }
    }
    return(false);
}
int dinic(int x,int flow)
{
    if (x==T)
        return(flow);
    int k=flow;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (d[y]!=d[x]+1 || !a[i][1])
            continue;
        int t=dinic(y,min(k,a[i][1]));
        k-=t;
        a[i][1]-=t;
        a[i^1][1]+=t;
        if (k==0)
            break;
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int sqr(int x)
{
    return(x*x);
}
int X[110],Y[110],on[110],capa[110];
bool jump[110][110];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n;
        double D;
        scanf("%d%lf",&n,&D);
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&X[i],&Y[i],&on[i],&capa[i]);
            sum+=on[i];
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                jump[i][j]=sqrt(sqr(X[i]-X[j])+sqr(Y[i]-Y[j]))-D<1e-8;
        vector <int> p;
        for (T=1;T<=n;T++)
        {
            memset(b,0,sizeof(b));
            tot=1;
            for (int i=1;i<=n;i++)
            {
                add(S,i,on[i]);
                add(i,i+n,capa[i]);
                for (int j=i+1;j<=n;j++)
                    if (jump[i][j])
                    {
                        add(i+n,j,inf);
                        add(j+n,i,inf);
                    }
            }
            int ans=0;
            while (build())
                ans+=dinic(S,inf);
            if (ans==sum)
                p.push_back(T-1);
        }
        static int id=0;
        printf("Case %d:",++id);
        if (p.empty())
            printf(" -1\n");
        else
        {
            for (int i=0;i<p.size();i++)
                printf(" %d",p[i]);
            printf("\n");
        }
    }
    return(0);
}

