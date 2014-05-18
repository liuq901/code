#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r,cnt,sum;
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
tree a[131080];
vector <int> Y;
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].cnt=a[x].sum=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void update(int x)
{
    if (a[x].cnt!=0)
    {
        a[x].sum=Y[a[x].r]-Y[a[x].l-1];
        return;
    }
    if (a[x].l==a[x].r)
    {
        a[x].sum=0;
        return;
    }
    int ls=x<<1,rs=ls+1;
    a[x].sum=a[ls].sum+a[rs].sum;
}
void modify(int x,int l,int r,int value)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].cnt+=value;
        update(x);
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,value);
    else if (l>mid)
        modify(rs,l,r,value);
    else
    {
        modify(ls,l,mid,value);
        modify(rs,mid+1,r,value);
    }
    update(x);
}
vector <event> e;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        e.clear();
        Y.clear();
        for (int i=1;i<=n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            Y.push_back(y1);
            Y.push_back(y2);
            e.push_back(event(x1,y1,y2,1));
            e.push_back(event(x2,y1,y2,-1));
        }
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        sort(e.begin(),e.end());
        build(1,1,Y.size()-1);
        ll ans=0;
        for (int i=0;i<e.size();i++)
        {
            if (i)
                ans+=a[1].sum*ll(e[i].x-e[i-1].x);
            int l=lower_bound(Y.begin(),Y.end(),e[i].l)-Y.begin();
            int r=lower_bound(Y.begin(),Y.end(),e[i].r)-Y.begin();
            modify(1,l+1,r,e[i].delta);
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

