#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const string yes="Suiting Success",no="Lonesome Willy";
const int inf=1<<30;
int tot,S,T,px[110],py[110],pr[110],pp[110],qx[410],qy[410],qp[410],b[510],d[510],q[510],a[1000000][3];
bool in[110][410];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
bool build()
{
    int l,r;
    memset(d,0,sizeof(d));
    d[S]=1,q[l=r=1]=S;
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
        if (!k)
            return(flow);
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int sqr(int x)
{
    return(x*x);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d%d%d%d",&px[i],&py[i],&pp[i],&pr[i]);
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&qx[i],&qy[i],&qp[i]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                in[i][j]=sqr(px[i]-qx[j])+sqr(py[i]-qy[j])<=sqr(pr[i]);
        for (int i=1;i<=m;i++)
            if (in[1][i])
                pp[1]+=qp[i];
        bool flag=true;
        for (int i=2;i<=n;i++)
            if (pp[i]>pp[1])
            {
                flag=false;
                break;
            }
        if (!flag)
            printf("%s\n",no.c_str());
        else
        {
            tot=1;
            memset(b,0,sizeof(b));
            S=0,T=n+m+1;
            for (int i=2;i<=n;i++)
                for (int j=1;j<=m;j++)
                    if (!in[1][j] && in[i][j])
                        add(i,j+n,inf);
            for (int i=2;i<=n;i++)
                add(S,i,pp[1]-pp[i]);
            int ans=0;
            for (int i=1;i<=m;i++)
            {
                if (in[1][i])
                    continue;
                bool flag=false;
                for (int j=2;j<=n;j++)
                    if (in[j][i])
                    {
                        flag=true;
                        break;
                    }
                if (flag)
                {
                    add(i+n,T,qp[i]);
                    ans+=qp[i];
                }
            }
            while (build())
                ans-=dinic(S,inf);
            printf("%s\n",!ans?yes.c_str():no.c_str());
        }
    }
    return(0);
}

