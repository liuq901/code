#include <cstdio>
typedef long long ll;
const int m=1000000000;
class bignum
{
    int a[4000];
public:
    bignum(int x=0)
    {
        a[a[0]=1]=x;
    }
    void print()
    {
        printf("%d",a[a[0]]);
        for (int i=a[0]-1;i;i--)
            printf("%09d",a[i]);
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
    ll x=0;
    for (int i=1;i<=c[0];i++)
    {
        ll p=ll(a[i])*b+x;
        c[i]=p%m;
        x=p/m;
    }
    while (x)
    {
        c[++c[0]]=x%m;
        x/=m;
    }
    return(c);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        bignum ans=1;
        for (int i=1;i<=n;i++)
            ans=ans*i;
        ans.print();
    }
    return(0);
}

