#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,f,s;
    bool reverse;
};
tree a[100010];
int n,root,v[100010],c[100010];
int build(int begin,int end)
{
    if (begin>end)
        return(0);
    int mid=begin+end>>1,x=v[mid];
    a[x].l=build(begin,mid-1);
    a[x].r=build(mid+1,end);
    a[a[x].l].f=a[a[x].r].f=x;
    a[x].s=a[a[x].l].s+a[a[x].r].s+1;
    a[x].reverse=false;
    return(x);
}
void zig(int x)
{
    int t=a[x].l,p=a[t].r;
    if (!a[x].f)
        root=t;
    else if (x==a[a[x].f].l)
        a[a[x].f].l=t;
    else
        a[a[x].f].r=t;
    a[t].r=x,a[x].l=p;
    a[t].f=a[x].f,a[x].f=t,a[p].f=x;
    a[t].s=a[x].s;
    a[x].s=a[p].s+a[a[x].r].s+1;
}
void zag(int x)
{
    int t=a[x].r,p=a[t].l;
    if (!a[x].f)
        root=t;
    else if (x==a[a[x].f].l)
        a[a[x].f].l=t;
    else
        a[a[x].f].r=t;
    a[t].l=x,a[x].r=p;
    a[t].f=a[x].f,a[x].f=t,a[p].f=x;
    a[t].s=a[x].s;
    a[x].s=a[p].s+a[a[x].l].s+1;
}
void update(int x)
{
    if (x==0)
        return;
    if (a[x].reverse)
    {
        swap(a[x].l,a[x].r);
        a[a[x].l].reverse=!a[a[x].l].reverse;
        a[a[x].r].reverse=!a[a[x].r].reverse;
        a[x].reverse=false;
    }
}
int get(int x,int pos)
{
    update(x);
    if (a[a[x].l].s+1==pos)
        return(x);
    else if (pos<=a[a[x].l].s)
        return(get(a[x].l,pos));
    else
        return(get(a[x].r,pos-a[a[x].l].s-1));
}
void splay(int x,int father)
{
    if (x==0)
        return;
    while (a[x].f!=father)
    {
        int p=a[x].f;
        update(p);
        update(x);
        if (x==a[p].l)
            zig(p);
        else
            zag(p);
    }
}
int work(int x)
{
    splay(x,0);
    int pos=a[a[x].l].s+1;
    splay(x-1,0);
    if (pos==n)
        splay(x,x-1);
    else
    {
        int y=get(root,pos+1);
        splay(y,x-1);
        splay(x,y);
    }
    a[x].reverse=!a[x].reverse;
    return(pos);
}
inline bool cmp(int x,int y)
{
    return(v[x]<v[y] || v[x]==v[y] && x<y);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp);
        for (int i=1;i<=n;i++)
            v[c[i]]=i;
        root=build(1,n);
        a[root].f=0;
        for (int i=1;i<=n;i++)
            printf("%d%c",work(i),i==n?'\n':' ');
    }
    return(0);
}

