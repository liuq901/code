#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=10000,limit=100;
int a[110];
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
struct frac
{
    bignum a,b;
    frac(int x):a(x),b(1){}
    frac(bignum a,bignum b):a(a),b(b){}
    frac inverse()
    {
        return(frac(b,a));
    }
};
frac operator +(const frac &a,const frac &b)
{
    return(frac(a.a*b.b+b.a*a.b,a.b*b.b));
}
frac calc(int dep)
{
    if (dep==limit)
        return(a[dep]);
    return(a[dep]+calc(dep+1).inverse());
}
int main()
{
    a[1]=2;
    int t=1;
    for (int i=2;i<=100;i+=3)
    {
        a[i]=1;
        a[i+1]=2*t;
        a[i+2]=1;
        t++;
    }
    calc(1).a.print();
    return(0);
}

