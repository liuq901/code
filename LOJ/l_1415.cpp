#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r,height;
    ll value,ans;
};
tree a[530000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].value=a[x].ans=a[x].height=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void updata(int x)
{
    if (a[x].height)
    {
        a[x].ans=a[x].value+a[x].height;
        if (a[x].l!=a[x].r)
        {
            int ls=x<<1,rs=ls+1;
            a[ls].height=a[rs].height=a[x].height;
        }
        a[x].height=0;
    }
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls),updata(rs);
    a[x].value=min(a[ls].value,a[rs].value);
    a[x].ans=min(a[ls].ans,a[rs].ans);
}
void fill(int x,int l,int r,int height)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].height=height;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        fill(ls,l,r,height);
    else if (l>mid)
        fill(rs,l,r,height);
    else
    {
        fill(ls,l,mid,height);
        fill(rs,mid+1,r,height);
    }
    update(x);
}
void insert(int x,int pos,ll value)
{
    if (a[x].l==a[x].r)
    {
        a[x].value=value;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    pos<=mid?insert(ls,pos,value):insert(rs,pos,value);
    update(x);
}
ll query(int x,int l,int r)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
        return(a[x].ans);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
        return(min(query(ls,l,mid),query(rs,mid+1,r)));
}
int h[200010],left[200010],pos[200010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        build(1,1,n);
        stack <int> s;
        memset(pos,0,sizeof(pos));
        for (int i=1;i<=n;i++)
        {
            int type;
            scanf("%d%d",&type,&h[i]);
            while (!s.empty() && h[i]>=h[s.top()])
                s.pop();
            int p=s.empty()?1:s.top()+1;
            s.push(i);
            fill(1,p,i,h[i]);
            left[i]=max(pos[type]+1,left[i-1]);
            pos[type]=i;
            ll value=query(1,left[i],i);
            if (i==n)
            {
                static int id=0;
                printf("Case %d: %lld\n",++id,value);
            }
            else
                insert(1,i+1,value);
        }
    }
    return(0);
}

