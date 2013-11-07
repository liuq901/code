#include <cstdio>
#include <cstdlib>
typedef long long ll;
const int N=250010;
int tot,a[N],l[N],r[N],v[N],c[N],s[N];
void right(int &x)
{
    int t=l[x];
    l[x]=r[t];
    r[t]=x;
    s[x]=s[l[x]]+s[r[x]]+1;
    s[t]=s[l[t]]+s[r[t]]+1;
    x=t;
}
void left(int &x)
{
    int t=r[x];
    r[x]=l[t];
    l[t]=x;
    s[x]=s[l[x]]+s[r[x]]+1;
    s[t]=s[l[t]]+s[r[t]]+1;
    x=t;
}
void insert(int &x,int value)
{
    if (x==0)
    {
        x=++tot;
        l[tot]=r[tot]=0;
        v[tot]=value;
        c[tot]=rand();
        s[tot]=1;
        return;
    }
    if (value<=v[x])
    {
        insert(l[x],value);
        s[x]++;
        if (c[l[x]]<c[x])
            right(x);
    }
    else
    {
        insert(r[x],value);
        s[x]++;
        if (c[r[x]]<c[x])
            left(x);
    }
}
void del(int &x,int value)
{
    if (value<v[x])
    {
        del(l[x],value);
        s[x]--;
        return;
    }
    if (value>v[x])
    {
        del(r[x],value);
        s[x]--;
        return;
    }
    if (!l[x] || !r[x])
    {
        x=l[x]+r[x];
        return;
    }
    if (c[l[x]]<c[r[x]])
    {
        right(x);
        del(r[x],value);
        s[x]--;
    }
    else
    {
        left(x);
        del(l[x],value);
        s[x]--;
    }
}
int get(int x,int K)
{
    if (K==s[l[x]]+1)
        return(v[x]);
    if (K<=s[l[x]])
        return(get(l[x],K));
    return(get(r[x],K-s[l[x]]-1));
}
int main()
{
    int seed,mul,add,n,K;
    scanf("%d%d%d%d%d",&seed,&mul,&add,&n,&K);
    a[1]=seed;
    for (int i=2;i<=n;i++)
        a[i]=(ll(a[i-1])*mul+add)%65536;
    int root=0;
    for (int i=1;i<=K;i++)
        insert(root,a[i]);
    ll ans=get(root,K+1>>1);
    for (int i=K+1;i<=n;i++)
    {
        insert(root,a[i]);
        del(root,a[i-K]);
        ans+=get(root,K+1>>1);
    }
    printf("%lld\n",ans);
    return(0);
}

