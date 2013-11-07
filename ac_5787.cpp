#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct frac
{
    ll a,b;
    frac(int x=0,int y=1)
    {
        ll t=__gcd(x,y);
        a=x/t,b=y/t;
    }
};
struct arm
{
    int dl,dr,l,r,f;
    frac wei;
};
inline frac operator +(const frac &a,const frac &b)
{
    return(frac(a.a*b.b+a.b*b.a,a.b*b.b));
}
inline frac operator *(const frac &a,const frac &b)
{
    return(frac(a.a*b.a,a.b*b.b));
}
inline frac operator /(const frac &a,const frac &b)
{
    return(frac(a.a*b.b,a.b*b.a));
}
vector <arm> a;
int f[100000];
frac wei[100000];
inline frac &weight(int x)
{
    if (x<0)
        return(wei[-x]);
    else
        return(a[x].wei);
}
void dfs(int x,int know)
{
    if (x<0)
        return;
    if (x==know)
    {
        weight(a[x].l)=a[x].wei*a[x].dr/(a[x].dl+a[x].dr);
        weight(a[x].r)=a[x].wei*a[x].dl/(a[x].dl+a[x].dr);
        dfs(a[x].l,a[x].l);
        dfs(a[x].r,a[x].r);
        return;
    }
    if (a[x].l==know)
    {
        weight(a[x].r)=weight(a[x].l)*a[x].dl/a[x].dr;
        dfs(a[x].r,a[x].r);
    }
    else
    {
        weight(a[x].l)=weight(a[x].r)*a[x].dr/a[x].dl;
        dfs(a[x].l,a[x].l);
    }
    a[x].wei=weight(a[x].l)+weight(a[x].r);
    dfs(a[x].f,x);
}
int main()
{
    while (1)
    {
        int n,m=0;
        scanf("%d",&n);
        if (n==0)
            break;
        a.resize(n+1);
        for (int i=1;i<=n;i++)
            a[i].f=-1;
        for (int i=1;i<=n;i++)
        {
            char s[10],t[10];
            scanf("%d%d%s%s%d%d",&a[i].dl,&a[i].dr,s,t,&a[i].l,&a[i].r);
            if (s[0]=='A')
                a[a[i].l].f=i;
            else
            {
                m=max(m,a[i].l);
                f[a[i].l]=i;
                a[i].l=-a[i].l;
            }
            if (t[0]=='A')
                a[a[i].r].f=i;
            else
            {
                m=max(m,a[i].r);
                f[a[i].r]=i;
                a[i].r=-a[i].r;
            }
        }
        int id;
        scanf("%d",&id);
        wei[id]=1;
        dfs(f[id],-id);
        ll ans=wei[1].b;
        for (int i=2;i<=m;i++)
        {
            int t=__gcd(wei[i].b,ans);
            ans=ans/t*wei[i].b;
        }
        int limit;
        scanf("%d",&limit);
        ll tmp=limit/ans*ans;
        if (tmp<limit)
            tmp+=ans;
        ll sum=0;
        for (int i=1;i<=m;i++)
            sum+=tmp/wei[i].b*wei[i].a;
        static int Id=0;
        printf("Case %d: %lld\n",++Id,sum);
    }
    return(0);
}

