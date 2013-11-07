#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct data
{
    int x,y,l,r,u,d;
};
struct state
{
    int x,y,z;
    state(){}
    state(int x,int y,int z):x(x),y(y),z(z){}
};
state ans[1000];
data a[500000];
int n,m,D,l[100],r[100],sum[400],p[400];
bool adj[100][100];
void build()
{
    m=n*(D+1);
    for (int i=1;i<=m;i++)
    {
        sum[i]=0;
        a[i].l=i-1;
        a[i].r=i+1;
        p[i]=i;
    }
    a[0].l=m;
    a[0].r=1;
    a[m].r=0;
    int t=0,tot=m;
    for (int i=1;i<=n;i++)
        for (int j=l[i];j<=r[i];j++)
            for (int k=j;k<=r[i];k++)
            {
                ans[++t]=state(i,j,k);
                vector <int> v;
                v.push_back(i);
                for (int l=j;l<=k;l++)
                    for (int y=1;y<=n;y++)
                    {
                        if (!adj[i][y])
                            continue;
                        v.push_back(l*n+y);
                    }
                int tmp=tot+1;
                for (int l=0;l<v.size();l++)
                {
                    int y=v[l];
                    tot++;
                    a[tot].x=t;
                    a[tot].y=y;
                    a[tot].l=tot-1;
                    a[tot].r=tot+1;
                    a[tot].u=p[y];
                    a[p[y]].d=tot;
                    p[y]=tot;
                    sum[y]++;
                }
                a[tot].r=tmp;
                a[tmp].l=tot;
            }
    for (int i=1;i<=n;i++)
    {
        ans[++t]=state(i,0,0);
        tot++;
        a[tot].x=t;
        a[tot].y=i;
        a[tot].l=tot;
        a[tot].r=tot;
        a[tot].u=p[i];
        a[p[i]].d=tot;
        p[i]=tot;
        sum[i]++;
    }
    for (int i=1;i<=m;i++)
    {
        a[p[i]].d=i;
        a[i].u=p[i];
    }
}
int here[1000];
void del(int x)
{
    a[a[x].l].r=a[x].r;
    a[a[x].r].l=a[x].l;
    for (int i=a[x].d;i!=x;i=a[i].d)
        for (int j=a[i].r;j!=i;j=a[j].r)
        {
            sum[a[j].y]--;
            a[a[j].u].d=a[j].d;
            a[a[j].d].u=a[j].u;
        }
}
void renew(int x)
{
    a[a[x].l].r=x;
    a[a[x].r].l=x;
    for (int i=a[x].u;i!=x;i=a[i].u)
        for (int j=a[i].l;j!=i;j=a[j].l)
        {
            sum[a[j].y]++;
            a[a[j].u].d=j;
            a[a[j].d].u=j;
        }
}
void print()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i==ans[here[j]].x)
            {
                printf("%d %d\n",ans[here[j]].y,ans[here[j]].z);
                break;
            }
}
bool DLX(int dep)
{
    if (a[0].r==0)
    {
        print();
        return(true);
    }
    int mi=1<<30,k;
    for (int i=a[0].r;i!=0;i=a[i].r)
        if (sum[i]<mi)
            mi=sum[k=i];
    del(k);
    for (int i=a[k].d;i!=k;i=a[i].d)
    {
        for (int j=a[i].r;j!=i;j=a[j].r)
            del(a[j].y);
        here[dep]=a[i].x;
        if (DLX(dep+1))
            return(true);
        for (int j=a[i].l;j!=i;j=a[j].l)
            renew(a[j].y);
    }
    renew(k);
    return(false);
}
int main()
{
    while (scanf("%d%d%d",&n,&m,&D)==3)
    {
        memset(adj,0,sizeof(adj));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            adj[x][y]=adj[y][x]=true;
        }
        for (int i=1;i<=n;i++)
        {
            adj[i][i]=true;
            scanf("%d%d",&l[i],&r[i]);
        }
        build();
        if (!DLX(1))
            printf("No solution\n");
        printf("\n");
    }
    return(0);
}

