#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
class fraction
{
    ll a,b;
    friend fraction operator +(const fraction &,const fraction &);
public:
    fraction(){}
    fraction(ll a,ll b):a(a),b(b)
    {
        simplify();
    }
    void simplify()
    {
        int t=__gcd(a,b);
        a/=t,b/=t;
    }
    void print()
    {
        printf("%I64d/%I64d\n",a,b);
    }
};
inline fraction operator +(const fraction &a,const fraction &b)
{
    return(fraction(a.a*b.b+a.b*b.a,a.b*b.b));
}
int f[20];
fraction a[20],s[20];
int main()
{
    f[1]=f[2]=1;
    for (int i=3;i<=15;i++)
        f[i]=f[i-1]+f[i-2];
    for (int i=1;i<=13;i++)
        a[i]=fraction(f[i+2],f[i+1]);
    s[1]=a[1];
    for (int i=2;i<=13;i++)
        s[i]=s[i-1]+a[i];
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        s[n].print();
    }
    return(0);
}

