#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,tot,b[1000],a[1000000][3];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int q[1000],d[1000];
bool build()
{
    memset(d,0,sizeof(d));
    int l,r;
    q[l=r=1]=S,d[S]=1;
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
char s[2][1000];
int get(char *s)
{
    int n=strlen(s),ret=0;
    for (int i=1;i<n;i++)
        ret=ret*10+s[i]-'0';
    return(ret);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
        int C,D,V;
        scanf("%d%d%d",&C,&D,&V);
        S=0,T=C+D+V+1;
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=V;i++)
        {
            scanf("%s%s",s[0],s[1]);
            int x=get(s[0]),y=get(s[1]);
            if (s[0][0]=='D')
            {
                add(S,i,1);
                add(i,x+V,inf);
                add(i,y+V+D,inf);
            }
            else
            {
                add(i,T,1);
                add(y+V,i,inf);
                add(x+V+D,i,inf);
            }
        }
        int ans=V;
        while (build())
            ans-=dinic(S,inf);
        printf("%d\n",ans);
    }
    return(0);
}

