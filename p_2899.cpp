#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,x,k;
};
struct event
{
    int x,y1,y2,k;
    event(){}
    event(int x,int y1,int y2,int k):x(x),y1(y1),y2(y2),k(k){}
};
tree a[2050];
event v[2010];
int n,X[1010],Y[1010];
inline bool operator <(const event &a,const event &b)
{
    return(a.x<b.x || a.x==b.x && a.k<b.k);
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=a[x].k=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void modify(int x,int l,int r,int value)
{
    if (l==a[x].l && r==a[x].r)
    {
        a[x].k+=value;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    a[ls].k+=a[x].k;
    a[rs].k+=a[x].k;
    a[x].k=0;
    if (r<=mid)
        modify(ls,l,r,value);
    else if (l>mid)
        modify(rs,l,r,value);
    else
    {
        modify(ls,l,mid,value);
        modify(rs,mid+1,r,value);
    }
    a[x].x=max(a[ls].x+a[ls].k,a[rs].x+a[rs].k);
}
int solve(int width,int height)
{
    for (int i=1;i<=n;i++)
    {
        v[i]=event(X[i],Y[i],min(1000,Y[i]+height),1);
        v[i+n]=event(X[i]+width+1,Y[i],min(1000,Y[i]+height),-1);
    }
    sort(v+1,v+n+n+1);
    build(1,1,1000);
    int ret=0;
    for (int i=1;i<=n+n;i++)
    {
        modify(1,v[i].y1,v[i].y2,v[i].k);
        ret=max(ret,a[1].x+a[1].k);
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int A;
        scanf("%d%d",&n,&A);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        if (A>=1000000)
        {
            printf("%d\n",n);
            continue;
        }
        int ans=0;
        for (int i=1;i*i<=A;i++)
            ans=max(ans,max(solve(i,A/i),solve(A/i,i)));
        printf("%d\n",ans);
    }
    return(0);
}

