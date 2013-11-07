#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int m=10000;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline bool operator ==(const point &a,const point &b)
{
    return(a.x==b.x && a.y==b.y);
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
class bignum
{
    int a[10];
public:
    bignum(int x=0)
    {
        memset(a,0,sizeof(a));
        while (x)
        {
            a[++a[0]]=x%m;
            x/=m;
        }
        a[0]=max(a[0],1);
    }
    void print()
    {
        printf("%d",a[a[0]]);
        for (int i=a[0]-1;i;i--)
            printf("%04d",a[i]);
        printf("\n");
    }
    int &operator [](int x)
    {
        return(a[x]);
    }
    int operator [](int x) const
    {
        return(a[x]);
    }
};
bignum operator +(const bignum &a,const bignum &b)
{
    bignum c;
    c[0]=max(a[0],b[0]);
    int x=0;
    for (int i=1;i<=c[0];i++)
    {
        c[i]=a[i]+b[i]+x;
        x=c[i]/m;
        c[i]%=m;
    }
    while (x)
    {
        c[++c[0]]=x%m;
        x/=m;
    }
    return(c);
}
bignum operator -(const bignum &a,const bignum &b)
{
    bignum c;
    c[0]=a[0];
    for (int i=1;i<=c[0];i++)
    {
        c[i]+=a[i]-b[i];
        if (c[i]<0)
        {
            c[i+1]--;
            c[i]+=m;
        }
    }
    while (c[0]>1 && !c[c[0]])
        c[0]--;
    return(c);
}
bignum operator *(const bignum &a,ll b)
{
    bignum c;
    c[0]=a[0];
    ll x=0;
    for (int i=1;i<=c[0];i++)
    {
        ll t=ll(a[i])*b+x;
        c[i]=t%m;
        x=t/m;
    }
    while (x)
    {
        c[++c[0]]=x%m;
        x/=m;
    }
    return(c);
}
bignum operator /(const bignum &a,int b)
{
    bignum c;
    c[0]=a[0];
    int x=0;
    for (int i=c[0];i;i--)
    {
        x=x*m+a[i];
        c[i]=x/b;
        x%=b;
    }
    while (c[0]>1 && !c[c[0]])
        c[0]--;
    return(c);
}
ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
point a[1010],b[1010];
int work(int n)
{
    int m=0;
    a[0]=a[n];
    a[n+1]=a[1];
    for (int i=1;i<=n;i++)
    {
        if (det(a[i+1]-a[i],a[i]-a[i-1])==0)
            continue;
        b[++m]=a[i];
    }
    for (int i=1;i<=m;i++)
        a[i]=b[i];
    return(m);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        int tot=1;
        for (int i=2;i<=n;i++)
        {
            if (a[i]==a[tot])
                continue;
            a[++tot]=a[i];
        }
        if (a[1]==a[tot])
            tot--;
        n=work(tot);
        static int id=0;
        if (n<3)
        {
            printf("Case %d: 0\n",++id);
            continue;
        }
        ll s=0,b=0;
        int k=0;
        a[0]=a[n];
        for (int i=1;i<=n;i++)
        {
            s+=det(a[i],a[i-1]);
            int p=__gcd(abs(a[i].y-a[i-1].y),abs(a[i].x-a[i-1].x));
            b+=p;
            k=__gcd(k,p);
        }
        s=abs(s);
        s/=ll(k)*k;
        b/=k;
        bignum ans;
        ans=(bignum(m)*(m+1)*(2*m+1)/6*s+2*m-bignum(m)*(m+1)/2*b)/2;
        printf("Case %d: ",++id);
        ans.print();
    }
    return(0);
}

