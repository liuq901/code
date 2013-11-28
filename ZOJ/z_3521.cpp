#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r,cover;
};
struct event
{
    ll x,ly,ry;
    int id;
    event(ll x,ll ly,ll ry,int id):x(x),ly(ly),ry(ry),id(id){}
};
inline bool operator <(const event &a,const event &b)
{
    return(a.x<b.x || a.x==b.x && a.id>b.id);
}
int R,x[50010],y[50010],f[50010];
vector <ll> Y;
vector <event> b;
tree a[270010];
bool in[50010];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].cover=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
int get(int x,int pos)
{
    if (a[x].cover!=0)
        return(a[x].cover);
    if (a[x].l==a[x].r)
        return(0);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (pos<=mid)
        return(get(ls,pos));
    else
        return(get(rs,pos));
}
void modify(int x,int l,int r,int cover)
{
    if (a[x].l==l && a[x].r==r)
    {
        if (cover>0)
            a[x].cover=cover;
        else if (a[x].cover==-cover)
            a[x].cover=0;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,cover);
    else if (l>mid)
        modify(rs,l,r,cover);
    else
    {
        modify(ls,l,mid,cover);
        modify(rs,mid+1,r,cover);
    }
}
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
ll sqr(ll x)
{
    return(x*x);
}
bool inCircle(int id)
{
    ll dx=x[id]-x[0],dy=y[id]-y[0];
    return(sqr(dx)+sqr(dy)<=sqr(R));
}
int main()
{
    int n,L;
    while (scanf("%d%d%d",&n,&R,&L)==3)
    {
        L/=2;
        Y.clear();
        b.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            Y.push_back(2LL*y[i]-L);
            Y.push_back(2LL*y[i]+L);
            b.push_back(event(2LL*x[i]-L,2LL*y[i]-L,2LL*y[i]+L,i));
            b.push_back(event(2LL*x[i]+L,2LL*y[i]-L,2LL*y[i]+L,-i));
        }
        scanf("%d%d",&x[0],&y[0]);
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        build(1,1,Y.size());
        sort(b.begin(),b.end());
        for (int i=1;i<=n;i++)
            f[i]=i;
        for (int i=0;i<b.size();i++)
        {
            int l=upper_bound(Y.begin(),Y.end(),b[i].ly)-Y.begin();
            int r=upper_bound(Y.begin(),Y.end(),b[i].ry)-Y.begin();
            if (b[i].id>0)
            {
                int x=get(1,l);
                if (x!=0)
                    f[find(x)]=find(b[i].id);
                x=get(1,r);
                if (x!=0)
                    f[find(x)]=find(b[i].id);
            }
            modify(1,l,r,b[i].id);
        }
        memset(in,0,sizeof(in));
        for (int i=1;i<=n;i++)
            if (inCircle(i))
                in[find(i)]=true;
        int ans=0;
        for (int i=1;i<=n;i++)
            ans+=in[find(i)];
        printf("%d\n",ans);
    }
    return(0);
}

