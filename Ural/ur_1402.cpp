#include <cstdio>
#include <cstring>
class bignum
{
    int a[30];
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
    while (x)
    {
        c[++c[0]]=x%10;
        x/=10;
    }
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
int main()
{
    int n;
    scanf("%d",&n);
    bignum ans=0;
    for (int i=2;i<=n;i++)
    {
        bignum now=1;
        for (int j=1;j<=i;j++)
            now=now*(n-j+1);
        ans=ans+now;
    }
    ans.print();
    return(0);
}

