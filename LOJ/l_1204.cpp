#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r,cover,cnt[11];
};
struct event
{
    int x,l,r,delta;
    event(int x,int l,int r,int delta):x(x),l(l),r(r),delta(delta){}
};
inline bool operator <(const event &a,const event &b)
{
    return(a.x<b.x);
}
vector <event> e;
vector <int> Y;
tree a[131100];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].cover=0;
    memset(a[x].cnt,0,sizeof(a[x].cnt));
    a[x].cnt[0]=Y[r]-Y[l-1];
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
int getans(int K)
{
    int ret=0;
    for (int i=K;i<=10;i++)
        ret+=a[1].cnt[i];
    return(ret);
}
void update(int x)
{
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        for (int i=0;i<=10;i++)
            a[x].cnt[i]=a[ls].cnt[i]+a[rs].cnt[i];
    }
    else
    {
        memset(a[x].cnt,0,sizeof(a[x].cnt));
        a[x].cnt[0]=Y[a[x].r]-Y[a[x].l-1];
    }
    if (a[x].cover==0)
        return;
    for (int i=9;i>=0;i--)
    {
        a[x].cnt[min(10,i+a[x].cover)]+=a[x].cnt[i];
        a[x].cnt[i]=0;
    }
}
void modify(int x,int l,int r,int delta)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].cover+=delta;
        update(x);
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,delta);
    else if (l>mid)
        modify(rs,l,r,delta);
    else
    {
        modify(ls,l,mid,delta);
        modify(rs,mid+1,r,delta);
    }
    update(x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        Y.clear();
        e.clear();
        for (int i=1;i<=n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x2++,y2++;
            Y.push_back(y1);
            Y.push_back(y2);
            e.push_back(event(x1,y1,y2,1));
            e.push_back(event(x2,y1,y2,-1));
        }
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        build(1,1,Y.size()-1);
        ll ans=0;
        sort(e.begin(),e.end());
        for (int i=0;i<e.size();i++)
        {
            if (i)
                ans+=ll(e[i].x-e[i-1].x)*getans(K);
            int l=lower_bound(Y.begin(),Y.end(),e[i].l)-Y.begin();
            int r=lower_bound(Y.begin(),Y.end(),e[i].r)-Y.begin();
            modify(1,l+1,r,e[i].delta);
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

