#include <cstdio>
#include <cstring>
class bignum
{
    int a[110];
public:
    bignum(int x=0)
    {
        memset(a,0,sizeof(a));
        while (x)
        {
            a[++a[0]]=x%10;
            x/=10;
        }
        if (a[0]==0)
            a[0]=1;
    }
    void print()
    {
        for (int i=a[0];i;i--)
            printf("%d",a[i]);
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
    c[0]=a[0]>b[0]?a[0]:b[0];
    int x=0;
    for (int i=1;i<=c[0];i++)
    {
        c[i]=a[i]+b[i]+x;
        x=c[i]/10;
        c[i]%=10;
    }
    if (x)
        c[++c[0]]=x;
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
            c[i]+=10;
            c[i+1]--;
        }
    }
    while (c[c[0]]==0 && c[0]>1)
        c[0]--;
    return(c);
}
bignum operator *(const bignum &a,int b)
{
    bignum c;
    c[0]=a[0];
    int x=0;
    for (int i=1;i<=c[0];i++)
    {
        c[i]=a[i]*b+x;
        x=c[i]/10;
        c[i]%=10;
    }
    while (x)
    {
        c[++c[0]]=x%10;
        x/=10;
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
        int t=x*10+a[i];
        c[i]=t/b;
        x=t%b;
    }
    while (c[c[0]]==0 && c[0]>1)
        c[0]--;
    return(c);
}
int operator %(const bignum &a,int b)
{
    int x=0;
    for (int i=a[0];i;i--)
        x=(x*10+a[i])%b;
    return(x);
}
int T;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        if (n==1)
        {
            printf("%d\n",K);
            continue;
        }
        bignum p=1,ans=0;
        int digit=0;
        for (int i=1;i<=100;i++)
        {
            p=p*10;
            digit++;
            bignum a=(p-n)*K;
            if (a%(10*n-1)!=0)
                continue;
            bignum x=a/(10*n-1);
            if (x[0]==digit)
            {
                ans=x*10+K;
                break;
            }
        }
        ans.print();
    }
    return(0);
}

