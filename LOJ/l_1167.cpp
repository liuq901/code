#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int tot,S,T,b[210],e[1000000][3],a[1000000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[210],q[210];
bool build()
{
    memset(d,0,sizeof(d));
    int l,r;
    q[l=r=1]=S;
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
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        n+=2;
        vector <int> value;
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            if (x>y)
                swap(x,y);
            e[i][0]=x,e[i][1]=y,e[i][2]=z;
            value.push_back(z);
        }
        int K;
        scanf("%d",&K);
        sort(value.begin(),value.end());
        value.erase(unique(value.begin(),value.end()),value.end());
        int l=0,r=value.size()-1,ans=-1;
        S=1+n,T=n;
        while (l<=r)
        {
            int mid=l+r>>1;
            memset(b,0,sizeof(b));
            tot=1;
            for (int i=1;i<=n;i++)
                add(i,i+n,1);
            for (int i=1;i<=m;i++)
            {
                int x,y,z;
                x=e[i][0],y=e[i][1],z=e[i][2];
                if (z<=value[mid])
                    add(x+n,y,1);
            }
            int sum=0;
            while (build())
            {
                sum+=dinic(S,1<<30);
                if (sum>=K)
                    break;
            }
            if (sum>=K)
                ans=value[mid],r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("no solution\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

