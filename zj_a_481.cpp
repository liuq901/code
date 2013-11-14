#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100010;
int total,lq[N],lc[N],rc[N],fa[N],Sum[N],value[N],Rev[N],List[N];
inline bool isroot(int x)
{
    if (fa[x]==0)
        return(true);
    return(x!=lc[fa[x]] && x!=rc[fa[x]]);
}
inline void update(int x)
{
    Sum[x]=Sum[lc[x]]+Sum[rc[x]]+value[x];
}
inline void Reverse(int x)
{
    if (Rev[x])
    {
        if (lc[x])
            Rev[lc[x]]^=1;
        if (rc[x])
            Rev[rc[x]]^=1;
        swap(lc[x],rc[x]);
        Rev[x]=0;
    }
}
inline void right(int x,int y)
{
    lc[y]=rc[x];
    if (lc[y])
        fa[lc[y]]=y;
    rc[x]=y;
    fa[x]=fa[y];
    if (fa[y])
        if (y==lc[fa[y]])
            lc[fa[x]]=x;
        else if (y==rc[fa[y]])
            rc[fa[x]]=x;
    fa[y]=x;
    update(y);
    update(x);
}
inline void left(int x,int y)
{
    rc[y]=lc[x];
    if (rc[y])
        fa[rc[y]]=y;
    lc[x]=y;
    fa[x]=fa[y];
    if (fa[y])
        if (y==lc[fa[y]])
            lc[fa[x]]=x;
        else if (y==rc[fa[y]])
            rc[fa[x]]=x;
    fa[y]=x;
    update(y);
    update(x);
}
void splay(int t)
{
    List[total=1]=t;
    for (int x=t;!isroot(x);x=fa[x])
        List[++total]=fa[x];
    for (;total;total--)
        if (Rev[List[total]])
            Reverse(List[total]);
    for (;!isroot(t);)
    {
        int f=fa[t];
        if (isroot(f))
            if (t==lc[f])
                right(t,f);
            else
                left(t,f);
        else
        {
            int ff=fa[f];
            if (f==lc[ff])
                if (t==lc[f])
                {
                    right(f,ff);
                    right(t,f);
                }
                else
                {
                    left(t,f);
                    right(t,ff);
                }
            else if (t==rc[f])
            {
                left(f,ff);
                left(t,f);
            }
            else
            {
                right(t,f);
                left(t,ff);
            }
        }
    }
}
int Expose(int u)
{
    int v=0;
    for (;u;u=fa[u])
    {
        splay(u);
        rc[u]=v;
        update(u);
        v=u;
    }
    for (;lc[v];v=lc[v]);
    return(v);
}
void Join(int x,int y)
{
    int fx=Expose(x);
    int fy=Expose(y);
    if (fx!=fy)
    {
        Expose(x);
        splay(x);
        rc[x]=0;
        fa[x]=y;
        Rev[x]=true;
        Reverse(x);
        update(x);
    }
}
void Cut(int x,int y)
{
    int fx=Expose(x);
    int fy=Expose(y);
    if (fx==fy)
    {
        Expose(x);
        splay(x);
        bool flag=false;
        if (lc[x])
        {
            int k;
            for (k=lc[x];rc[k];k=rc[k]);
            if (k==y)
                flag=true;
        }
        if (flag)
        {
            fa[lc[x]]=0;
            lc[x]=0;
            update(x);
        }
        else
        {
            Expose(y);
            splay(y);
            fa[lc[y]]=0;
            lc[y]=0;
            update(y);
        }
    }
}
void Modify(int x,int co)
{
    splay(x);
    value[x]=co;
    update(x);
}
void Query(int x,int y)
{
    int fx=Expose(x);
    int fy=Expose(y);
    for (int u=x,v=0;u;u=fa[u])
    {
        splay(u);
        if (fa[u]==0)
        {
            int cnt=Sum[rc[u]]+Sum[v]+value[u];
            printf("%d\n",cnt);
            return;
        }
        rc[u]=v;
        update(u);
        v=u;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (i!=1)
        {
            Join(x,i);
            lq[i]=x;
        }
        Modify(i,y);
    }
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if (op==1)
            Query(x,y);
        else if (op==2)
            Modify(x,y);
        else
        {
            Cut(x,lq[x]);
            Join(x,y);
            lq[x]=y;
        }
    }
    return(0);
}

