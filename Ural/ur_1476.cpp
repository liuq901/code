#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=10000;
struct bignum
{
    int a[126];
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
    bool zero() const
    {
        return(a[0]==1 && a[1]==0);
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
bignum operator *(const bignum &a,const bignum &b)
{
    if (a.zero() || b.zero())
        return(0);
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
bignum c[50][50],a[50][50],f[50][50];
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    for (int i=0;i<=n;i++)
        for (int j=0;j<=min(n-i,K);j++)
            for (int k=0;k<=i;k++)
                a[i][j+k]=a[i][j+k]+c[n-i][j]*c[i][k];
    for (int i=0;i<=n;i++)
        f[1][i]=c[n][i];
    for (int i=2;i<=m;i++)
        for (int j=0;j<=n;j++)
            for (int k=0;k<=n;k++)
                f[i][j]=f[i][j]+f[i-1][k]*a[k][j];
    bignum ans;
    for (int i=0;i<=n;i++)
        ans=ans+f[m][i];
    ans.print();
    return(0);
}

