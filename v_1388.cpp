#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m=10000;
struct bignum
{
    int a[1010];
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
bignum operator *(const bignum &a,int b)
{
    bignum c;
    c[0]=a[0];
    int x=0;
    for (int i=1;i<=c[0];i++)
    {
        c[i]=a[i]*b+x;
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
int main()
{
    int n;
    scanf("%d",&n);
    bignum ans=1;
    for (int i=1;i<=n;i++)
        ans=ans*(2*n-i+1)/i;
    ans=ans/(n+1);
    ans.print();
    return(0);
}

