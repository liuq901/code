#include <cstdio>
#include <cstring>
const int n=100,m=10000;
class bignum
{
    int a[60];
public:
    bignum(int x=0)
    {
        memset(a,0,sizeof(a));
        a[0]=26;
        a[a[0]]=x;
    }
    int digit()
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
        return(ret-a[1]%10);
    }
    void div()
    {
        for (int i=1;i<=a[0];i++)
        {
            if (!a[i])
                continue;
            if (a[i]==1)
            {
                a[i]=0;
                a[i-1]=1000;
            }
            else
                a[i]/=10;
            break;
        }
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
bool operator >(const bignum &a,const bignum &b)
{
    if (a[0]!=b[0])
        return(a[0]>b[0]);
    for (int i=a[0];i;i--)
        if (a[i]!=b[i])
            return(a[i]>b[i]);
    return(false);
}
bignum operator +(const bignum &a,const bignum &b)
{
    bignum c;
    c[0]=a[0]>b[0]?a[0]:b[0];
    int x=0;
    for (int i=1;i<=c[0];i++)
    {
        c[i]=a[i]+b[i]+x;
        x=c[i]/m;
        c[i]%=m;
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
    for (int i=26;i<=c[0];i++)
        c[i-25]=c[i];
    c[0]=26;
    return(c);
}
bool f[n+10];
int main()
{
    int ans=0;
    for (int i=1;i*i<=n;i++)
        f[i*i]=true;
    for (int i=1;i<=n;i++)
    {
        if (f[i])
            continue;
        bignum limit(i),one(1),now(0);
        for (int j=0;j<=100;j++)
        {
            while (1)
            {
                bignum tmp=now+one;
                if (tmp*tmp>limit)
                    break;
                now=now+one;
            }
            one.div();
        }
        ans+=now.digit();
    }
    printf("%d\n",ans);
    return(0);
}

