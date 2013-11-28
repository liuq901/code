#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,x,len;
};
tree a[1100000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=-1;
    if (a[x].l==a[x].r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void insert(int x,int l,int r,int value,int len)
{
    if (a[x].l==l && a[x].r==r)
    {
        if (a[x].x==-1 || len<a[x].len)
            a[x].x=value,a[x].len=len;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        insert(ls,l,r,value,len);
    else if (l>mid)
        insert(rs,l,r,value,len);
    else
    {
        insert(ls,l,mid,value,len);
        insert(rs,mid+1,r,value,len);
    }
}
int query(int x,int pos)
{
    if (a[x].l==a[x].r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    int ret=pos<=mid?query(ls,pos):query(rs,pos);
    if (ret==-1)
        ret=a[x].x;
    return(ret);
}
vector <int> X;
inline int get(int x)
{
    return(lower_bound(X.begin(),X.end(),x)-X.begin()+1);
}
int l[100010],r[100010],c[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        X.push_back(l[i]);
        X.push_back(r[i]);
    }
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&c[i]);
        X.push_back(c[i]);
    }
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    build(1,1,X.size());
    for (int i=1;i<=n;i++)
        insert(1,get(l[i]),get(r[i]),i,r[i]-l[i]);
    for (int i=1;i<=m;i++)
        printf("%d\n",query(1,get(c[i])));
    return(0);
}

