#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000000,m=10000;
class bignum
{
    int a[30];
public:
    bignum(int x=0)
    {
        memset(a,0,sizeof(a));
        while (x)
        {
            a[++a[0]]=x%m;
            x/=m;
        }
    }
    void print()
    {
        int ret=0;
        for (int i=1;i<=a[0];i++)
        {
            int x=a[i];
            while (x)
            {
                ret+=x%10;
                x/=10;
            }
        }
        printf("%d\n",ret);
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
bignum operator *(const bignum &a,const bignum &b)
{
    bignum c;
    c[0]=a[0]+b[0];
    for (int i=1;i<=a[0];i++)
        for (int j=1;j<=b[0];j++)
        {
            c[i+j-1]+=a[i]*b[j];
            c[i+j]+=c[i+j-1]/m;
            c[i+j-1]%=m;
        }
    while (c[0]>1 && !c[c[0]])
        c[0]--;
    return(c);
}
bool operator >(const bignum &a,const bignum &b)
{
    if (a[0]!=b[0])
        return(a[0]>b[0]);
    for (int i=a[0];i;i--)
        if (a[i]!=b[i])
            return(a[i]>b[i]);
    return(false);
}
bool operator ==(const bignum &a,const bignum &b)
{
    return(!(a>b) && !(b>a));
}
bignum p[N],q[N];
int a[N],g[N],h[N];
bool f[1010];
bignum work(int n)
{
    p[1]=1,p[0]=0;
    q[1]=0,q[0]=1;
    a[2]=1;
    while (a[2]*a[2]<=n)
        a[2]++;
    a[2]--;
    g[1]=0,h[1]=1;
    for (int i=2;;i++)
    {
        g[i]=-g[i-1]+a[i]*h[i-1];
        h[i]=(n-g[i]*g[i])/h[i-1];
        a[i+1]=(g[i]+a[2])/h[i];
        p[i]=a[i]*p[i-1]+p[i-2];
        q[i]=a[i]*q[i-1]+q[i-2];
        if (p[i]*p[i]==n*q[i]*q[i]+1)
            return(p[i]);
    }
}
int main()
{
    for (int i=1;i*i<=1000;i++)
        f[i*i]=true;
    bignum ans=0;
    int k;
    for (int i=1;i<=1000;i++)
    {
        if (f[i])
            continue;
        bignum p=work(i);
        if (p>ans)
        {
            ans=p;
            k=i;
        }
    }
    printf("%d\n",k);
    return(0);
}

