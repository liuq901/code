#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=10000;
struct bignum
{
    int a[30];
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
    if (x)
        c[++c[0]]=x;
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
bool operator <(const bignum &a,const bignum &b)
{
    if (a[0]!=b[0])
        return(a[0]<b[0]);
    for (int i=a[0];i;i--)
        if (a[i]!=b[i])
            return(a[i]<b[i]);
    return(false);
}
bignum f[100][100];
int a[100];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    bignum ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            scanf("%d",&a[j]);
        for (int j=m;j;j--)
        {
            f[j][j]=a[j];
            for (int k=j+1;k<=m;k++)
                f[j][k]=max(f[j+1][k]*2+a[j],f[j][k-1]*2+a[k]);
        }
        ans=ans+f[1][m]*2;
    }
    ans.print();
    return(0);
}

