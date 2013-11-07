#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N=4000000;
int root[100010<<2];
namespace splay
{
    int tot,id,key[N],v[N],l[N],r[N],f[N],ma[N];
    void update(int x)
    {
        ma[x]=max(v[x],max(ma[l[x]],ma[r[x]]));
    }
    void up(int x,bool right)
    {
        int t=f[x],p;
        if (right)
        {
            p=r[x];
            r[x]=t;
            l[t]=p;
        }
        else
        {
            p=l[x];
            l[x]=t;
            r[t]=p;
        }
        if (f[t]==0)
            root[id]=x;
        else if (t==l[f[t]])
            l[f[t]]=x;
        else
            r[f[t]]=x;
        f[x]=f[t],f[p]=t,f[t]=x;
        update(t);
        update(x);
    }
    void Splay(int x,int fa)
    {
        while (f[x]!=fa)
        {
            if (x==l[f[x]])
                up(x,true);
            else
                up(x,false);
        }
    }
    int find(int x,int y)
    {
        if (y==key[x])
            return(x);
        if (y<key[x])
            return(find(l[x],y));
        return(find(r[x],y));
    }
    int node(int fa,int k,int value)
    {
        tot++;
        key[tot]=k;
        v[tot]=ma[tot]=value;
        l[tot]=r[tot]=0;
        f[tot]=fa;
        return(tot);
    }
    void add(int x,int y,int value)
    {
        if (y<=key[x])
        {
            if (key[x]==y)
            {
                v[x]=max(v[x],value);
                update(x);
                return;
            }
            if (!l[x])
            {
                l[x]=node(x,y,value);
                Splay(l[x],0);
            }
            else
                add(l[x],y,value);
        }
        else if (!r[x])
        {
            r[x]=node(x,y,value);
            Splay(r[x],0);
        }
        else
            add(r[x],y,value);
        update(x);
    }
    void insert(int ID,int y,int value)
    {
        id=ID;
        if (root[id]==0)
            root[id]=node(0,y,value);
        else
            add(root[id],y,value);
    }
    void del(int p)
    {
        Splay(p,0);
        int t=r[p];
        if (!l[p])
        {
            f[t]=0;
            root[id]=t;
        }
        else
        {
            int q=l[p];
            while (r[q])
                q=r[q];
            Splay(q,p);
            r[q]=t;
            f[t]=q;
            f[q]=0;
            root[id]=q;
            update(q);
        }
    }
    int get(int ID,int ly,int ry)
    {
        id=ID;
        insert(id,ly,0);
        int p=find(root[id],ly);
        insert(id,ry,0);
        int q=find(root[id],ry);
        if (p==q)
            return(v[p]);
        Splay(p,0);
        Splay(q,p);
        int ans=max(ma[l[q]],max(v[p],v[q]));
        if (v[p]==0)
            del(p);
        if (v[q]==0)
            del(q);
        return(ans);
    }
}
struct state
{
    int x,y,w,l;
};
inline bool operator <(const state &a,const state &b)
{
    return(a.w<b.w);
}
state a[100010];
vector <int> X,Y;
void build(int t,int l,int r)
{
    root[t]=0;
    if (l==r)
        return;
    int mid=l+r>>1,ls=t<<1,rs=ls+1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
int get(int t,int l,int r,int lx,int rx,int ly,int ry)
{
    if (rx<X[l] || X[r]<lx)
        return(0);
    if (lx<=X[l] && X[r]<=rx)
        return(splay::get(t,ly,ry));
    int mid=l+r>>1,ls=t<<1,rs=ls+1;
    return(max(get(ls,l,mid,lx,rx,ly,ry),get(rs,mid+1,r,lx,rx,ly,ry)));
}
void insert(int t,int l,int r,int x,int y,int value)
{
    if (x<X[l] || X[r]<x)
        return;
    splay::insert(t,y,value);
    if (l==r)
        return;
    int mid=l+r>>1,ls=t<<1,rs=ls+1;
    insert(ls,l,mid,x,y,value);
    insert(rs,mid+1,r,x,y,value);
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
            int x,y;
            scanf("%d%d%d%d",&x,&y,&a[i].w,&a[i].l);
            a[i].x=x-y,a[i].y=x+y;
            X.push_back(a[i].x);
        }
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        build(1,0,X.size()-1);
        splay::tot=0;
        sort(a+1,a+n+1);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int now=get(1,0,X.size()-1,a[i].x-a[i].l,a[i].x+a[i].l,a[i].y-a[i].l,a[i].y+a[i].l)+1;
            insert(1,0,X.size()-1,a[i].x,a[i].y,now);
            ans=max(ans,now);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

