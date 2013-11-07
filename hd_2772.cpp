#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int c[10]={6,2,5,5,4,5,6,3,7,6};
ll a[110],f[60][110];
class bignum
{
    int a[60];
public:
    bignum()
    {
        memset(a,0,sizeof(a));
    }
    bignum(int x)
    {
        memset(a,0,sizeof(a));
        while (x)
        {
            a[++a[0]]=x%10;
            x/=10;
        }
        a[0]=max(a[0],1);
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
bignum g[60][110],b[110];
bignum operator +(const bignum &a,const bignum &b)
{
    bignum c;
    c[0]=max(a[0],b[0]);
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
bool operator <(const bignum &a,const bignum &b)
{
    if (a[0]!=b[0])
        return(a[0]<b[0]);
    for (int i=a[0];i;i--)
        if (a[i]!=b[i])
            return(a[i]<b[i]);
    return(false);
}
void init()
{
    for (int i=0;i<=50;i++)
        for (int j=0;j<=100;j++)
        {
            f[i][j]=1LL<<55;
            g[i][j]=0;
        }
    f[0][0]=0;
    g[0][0]=0;
    for (int i=1;i<=50;i++)
        for (int j=2;j<=100;j++)
            for (int k=0;k<10;k++)
            {
                if (i==1 && k==0 || j<c[k])
                    continue;
                f[i][j]=min(f[i][j],f[i-1][j-c[k]]*10+k);
                g[i][j]=max(g[i][j],g[i-1][j-c[k]]*10+k);
            }
    for (int i=2;i<=100;i++)
    {
        a[i]=1LL<<55;
        b[i]=0;
    }
    for (int i=1;i<=50;i++)
        for (int j=2;j<=100;j++)
        {
            a[j]=min(a[j],f[i][j]);
            b[j]=max(b[j],g[i][j]);
        }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        cout<<a[n]<<" ";
        b[n].print();
    }
    return(0);
}

