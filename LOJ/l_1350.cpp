#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int S,T,tot,b[160],a[1000000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[160],q[160];
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
char get(int x)
{
    if (x<=26)
        return('a'+x-1);
    x-=26;
    return('A'+x-1);
}
char p[10010][30];
int begin[60],end[60],value[60];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,t,c,e;
        scanf("%d%d%d%d",&n,&t,&c,&e);
        vector <int> slot;
        slot.push_back(1);
        slot.push_back(e);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&begin[i],&end[i],&value[i]);
            slot.push_back(begin[i]);
            slot.push_back(end[i]);
        }
        sort(slot.begin(),slot.end());
        slot.erase(unique(slot.begin(),slot.end()),slot.end());
        S=n+slot.size()+1,T=S+1,tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<slot.size();i++)
            add(i+n,T,(slot[i]-slot[i-1])*t*c);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int l=lower_bound(slot.begin(),slot.end(),begin[i])-slot.begin()+1;
            int r=lower_bound(slot.begin(),slot.end(),end[i])-slot.begin()+1;
            for (int j=l;j<r;j++)
                add(i,j+n,slot[j]-slot[j-1]);
            ans+=value[i];
            add(S,i,value[i]);
        }
        while (build())
            ans-=dinic(S,1<<30);
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"No":"Yes");
        if (!ans)
        {
            memset(p,'.',sizeof(p));
            for (int i=1;i<slot.size();i++)
            {
                int x=i+n,l=slot[i-1],r=slot[i],col=1,row=l;
                for (int j=b[x];j;j=a[j][2])
                {
                    int y=a[j][0];
                    if (y==T)
                        continue;
                    int cnt=a[j][1];
                    for (int k=1;k<=cnt;k++)
                    {
                        p[row][col]=get(y);
                        row++;
                        if (row==r)
                            row=l,col++;
                    }
                }
            }
            for (int i=1;i<e;i++)
                for (int j=1;j<=t*c;j++)
                {
                    printf("%c",p[i][j]);
                    if (j%c==0)
                        printf("%c",j==t*c?'\n':'|');
                }
        }
    }
    return(0);
}

