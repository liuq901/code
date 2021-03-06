#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> c;
int S,T,tot,l[100010],r[100010],v[100010],b[1000010],a[1000010][4];
void add(int x,int y,int v,int id)
{
    a[++tot][0]=y,a[tot][1]=v,a[tot][2]=id,a[tot][3]=b[x],b[x]=tot;
}
int d[1000010],f[1000010],pre[1000010],p[1000010],q[1000010];
bool vis[1000010];
void spfa()
{
    int l,r;
    l=0,r=1;
    q[1]=S;
    memset(d,63,sizeof(d));
    vis[S]=true;
    d[S]=0;
    f[S]=0;
    while (l!=r)
    {
        l=l==1000000?1:l+1;
        int x=q[l];
        vis[x]=false;
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (d[x]+a[i][1]<d[y])
            {
                d[y]=d[x]+a[i][1];
                f[y]=f[x]+(a[i][2]!=0);
                pre[y]=x;
                p[y]=i;
                if (!vis[y])
                {
                    vis[y]=true;
                    r=r==1000000?1:r+1;
                    q[r]=y;
                    int k=l==1000000?1:l+1;
                    if (d[q[r]]<d[q[k]])
                        swap(q[r],q[k]);
                }
            }
        }
    }
    printf("%d\n%d\n",d[T],f[T]);
}
void print(int x)
{
    if (x==0)
        return;
    print(pre[x]);
    int id=a[p[x]][2];
    if (id!=0)
        printf("%d\n",id);
}
int main()
{
    int n,L;
    scanf("%d%d",&n,&L);
    for (int i=1;i<=n;i++)
    {
        int x,d,t,p;
        scanf("%d%d%d%d",&x,&d,&t,&p);
        l[i]=x-p,r[i]=x+d,v[i]=p+t;
        if (l[i]<0)
            continue;
        c.push_back(l[i]);
        c.push_back(r[i]);
    }
    c.push_back(0);
    c.push_back(L);
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for (int i=1;i<c.size();i++)
    {
        int x=c[i-1],y=c[i];
        add(i-1,i,y-x,0);
        add(i,i-1,y-x,0);
    }
    for (int i=1;i<=n;i++)
    {
        if (l[i]<0)
            continue;
        int x=lower_bound(c.begin(),c.end(),l[i])-c.begin();
        int y=lower_bound(c.begin(),c.end(),r[i])-c.begin();
        add(x,y,v[i],i);
    }
    S=0,T=c.size()-1;
    spfa();
    print(T);
    return(0);
}

