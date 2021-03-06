#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int tot=1,S,T,id[1010],b[2010],e[1010][3],a[1000000][4];
vector <int> v;
void add(int x,int y,int v,int c)
{
    a[++tot][0]=y,a[tot][1]=v,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
queue <int> Q;
int d[2010],p[2010],pre[2010];
bool in[2010];
bool spfa()
{
    memset(d,63,sizeof(d));
    int inf=d[0];
    Q.push(S);
    d[S]=0;
    in[S]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+a[i][2]<d[y])
            {
                d[y]=d[x]+a[i][2];
                pre[y]=x;
                p[y]=i;
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
    if (d[T]==inf)
        return(false);
    int flow=inf;
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        flow=min(flow,a[x][1]);
    }
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        a[x][1]-=flow;
        a[x^1][1]+=flow;
    }
    return(true);
}
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
        v.push_back(e[i][0]);
        v.push_back(e[i][0]+e[i][1]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int m=v.size();
    S=0,T=m;
    add(S,1,K,0);
    for (int i=1;i<m;i++)
        add(i,i+1,K,0);
    for (int i=1;i<=n;i++)
    {
        int x=lower_bound(v.begin(),v.end(),e[i][0])-v.begin()+1;
        int y=lower_bound(v.begin(),v.end(),e[i][0]+e[i][1])-v.begin()+1;
        id[i]=tot+1;
        add(x,y,1,-e[i][2]);
    }
    while (spfa());
    for (int i=1;i<=n;i++)
        printf("%d%c",1-a[id[i]][1],i==n?'\n':' ');
    return(0);
}

