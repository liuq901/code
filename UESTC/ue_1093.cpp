#include <cstdio>
#include <cstring>
const int m=10000;
struct bignum
{
    int a[60];
    bignum(int x=0)
    {
        memset(a,0,sizeof(a));
        while (x)
        {
            a[++a[0]]=x%m;
            x/=m;
        }
        if (!a[0])
            a[0]=1;
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
bignum power(int n,int m)
{
    bignum ret=1,now=n;
    for (;m;m>>=1)
    {
        if (m&1)
            ret=ret*now;
        now=now*now;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        power(n,m).print();
    }
    return(0);
}

