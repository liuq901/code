#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int N=100010,m=17;
int q[N],b[N],sum[N],dep[N],w[N],a[2*N][3],fa[N][18];
bool vis[N];
vector <pair <int,int> > c[N];
vector <int> odd[N],even[N];
inline bool cmp(const pair <int,int> &a,const pair <int,int> &b)
{
    return(a.first>b.first || a.first==b.first && a.second<b.second);
}
void init(int n)
{
    memset(vis,0,sizeof(vis));
    int l,r;
    q[l=r=1]=1;
    vis[1]=true;
    dep[1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (!vis[y])
            {
                vis[y]=true;
                q[++r]=y;
                fa[y][0]=x;
                dep[y]=dep[x]+1;
            }
        }
    }
    for (int i=n;i;i--)
    {
        int x=q[i];
        sum[x]=0;
        for (int j=b[x];j;j=a[j][2])
        {
            int y=a[j][0];
            if (y==fa[x][0])
                continue;
            sum[x]+=sum[y]+a[j][1];
            w[y]=sum[y]+a[j][1];
        }
    }
    for (int i=1;i<=n;i++)
    {
        int x=q[i];
        for (int j=1;j<=m;j++)
            fa[x][j]=fa[fa[x][j-1]][j-1];
        c[x].clear();
        for (int j=b[x];j;j=a[j][2])
        {
            int y=a[j][0];
            if (y==fa[x][0])
                c[x].push_back(make_pair(sum[1]-sum[x],y));
            else
                c[x].push_back(make_pair(sum[y]+a[j][1],y));
        }
        sort(c[x].begin(),c[x].end(),cmp);
        odd[x].resize(c[x].size());
        even[x].resize(c[x].size());
        odd[x][0]=c[x][0].first;
        even[x][0]=0;
        for (int i=1;i<c[x].size();i++)
        {
            odd[x][i]=odd[x][i-1];
            even[x][i]=even[x][i-1];
            if (i&1)
                even[x][i]+=c[x][i].first;
            else
                odd[x][i]+=c[x][i].first;
        }
    }
}
int lca(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    for (int i=m;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y)
        return(x);
    for (int i=m;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return(fa[x][0]);
}
inline int ancester(int x,int p)
{
    for (int i=0;i<=m;i++)
        if (p>>i&1)
            x=fa[x][i];
    return(x);
}
inline int haha(const vector <int> &a,int l,int r)
{
    int ret=a[r];
    if (l!=0)
        ret-=a[l-1];
    return(ret);
}
inline int query(int x,int l,int r,bool first)
{
    if (l>r)
        return(0);
    if (l%2==0 && first || l%2==1 && !first)
        return(haha(odd[x],l,r));
    else
        return(haha(even[x],l,r));
}
int calc(int x,int p,int q,bool alice)
{
    int ret=0,wp,wq;
    if (p==0)
        p=-1;
    else if (p==fa[x][0])
        wp=sum[1]-sum[x];
    else
        wp=w[p];
    if (p!=-1)
        ret+=wp;
    if (q==0)
        q=-1;
    else if (q==fa[x][0])
        wq=sum[1]-sum[x];
    else
        wq=w[q];
    if (p!=-1)
        p=lower_bound(c[x].begin(),c[x].end(),make_pair(wp,p),cmp)-c[x].begin();
    if (q!=-1)
        q=lower_bound(c[x].begin(),c[x].end(),make_pair(wq,q),cmp)-c[x].begin();
    if (p>q)
        swap(p,q);
    bool flag1,flag2;
    flag1=alice;
    if (p-1>=0 && p%2==1)
        flag1=!flag1;
    flag2=flag1;
    if (q-1>=p+1 && (q-p-1)%2==1)
        flag2=!flag2;
    return(ret+query(x,0,p-1,alice)+query(x,p+1,q-1,flag1)+query(x,q+1,c[x].size()-1,flag2));
}
int query(int x,int y)
{
    int p=lca(x,y),len=dep[x]+dep[y]-2*dep[p];
    int la=(len+1)/2,lb=len-la,t;
    if (la<=dep[x]-dep[p])
        t=ancester(x,la);
    else
        t=ancester(y,lb);
    int aa,bb;
    if (x==t)
        aa=0;
    else if (la<=dep[x]-dep[p])
        aa=ancester(x,la-1);
    else
        aa=fa[t][0];
    if (y==t)
        bb=0;
    else if (lb<=dep[y]-dep[p])
        bb=ancester(y,lb-1);
    else
        bb=fa[t][0];
    return(calc(t,aa,bb,la==lb));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        init(n);
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x,y));
        }
    }
    return(0);
}

