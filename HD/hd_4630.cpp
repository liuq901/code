#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,x;
};
tree a[131100];
int pos[50010],ans[50010];
vector <pair <int,int> > b[50010];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r;
    if (l==r)
    {
        a[x].x=b[l].empty()?-1:b[l].back().first;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    a[x].x=max(a[ls].x,a[rs].x);
}
int get(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r));
    else if (l>mid)
        return(get(rs,l,r));
    return(max(get(ls,l,mid),get(rs,mid+1,r)));
}
int find(int x,int pos,int value)
{
    if (a[x].l==a[x].r)
        return(a[x].l);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (pos<=mid)
        return(find(ls,pos,value));
    return(a[ls].x==value?find(ls,pos,value):find(rs,pos,value));
}
void modify(int x,int pos)
{
    if (a[x].l==a[x].r)
    {
        a[x].x=b[pos].empty()?-1:b[pos].back().first;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    pos<=mid?modify(ls,pos):modify(rs,pos);
    a[x].x=max(a[ls].x,a[rs].x);
}
void calc(int l,int r,int gcd)
{
    while (1)
    {
        int ma=get(1,1,l);
        if (ma<r)
            break;
        int pos=find(1,l,ma);
        ans[b[pos].back().second]=gcd;
        b[pos].pop_back();
        modify(1,pos);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            pos[x]=i;
            b[i].clear();
        }
        int Q;
        scanf("%d",&Q);
        for (int i=1;i<=Q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            b[l].push_back(make_pair(r,i));
            ans[i]=0;
        }
        for (int i=1;i<=n;i++)
            sort(b[i].begin(),b[i].end());
        build(1,1,n);
        for (int i=n;i;i--)
        {
            int m=n/i;
            vector <int> lq;
            for (int j=1;j<=m;j++)
                lq.push_back(pos[i*j]);
            sort(lq.begin(),lq.end());
            for (int j=1;j<lq.size();j++)
            {
                int l=lq[j-1],r=lq[j];
                calc(l,r,i);
            }
        }
        for (int i=1;i<=Q;i++)
            printf("%d\n",ans[i]);
    }
    return(0);
}

