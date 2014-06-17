#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
struct fraction
{
    ll a,b;
    fraction(ll _a=0,ll _b=1)
    {
        ll p=__gcd(_a,_b);
        a=_a/p;
        b=_b/p;
        if (b<0)
            a*=-1,b*=-1;
    }
    void in()
    {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        a=h*3600+m*60+s;
        b=1;
    }
    void print() const
    {
        int h=a/b/3600,m=a/b/60%60,s=a/b%60;
        printf("%02d:%02d:%02d",h,m,s);
        if (b!=1)
            printf(" %lld/%lld",a%b,b);
        printf("\n");
    }
};
inline fraction operator +(const fraction &a,const fraction &b)
{
    return(fraction(a.a*b.b+b.a*a.b,a.b*b.b));
}
inline fraction operator -(const fraction &a,const fraction &b)
{
    return(fraction(a.a*b.b-b.a*a.b,a.b*b.b));
}
inline fraction operator *(const fraction &a,const fraction &b)
{
    return(fraction(a.a*b.a,a.b*b.b));
}
inline fraction operator /(const fraction &a,const fraction &b)
{
    return(fraction(a.a*b.b,a.b*b.a));
}
inline bool operator <(const fraction &a,const fraction &b)
{
    return(a.a*b.b<a.b*b.a);
}
inline bool operator <=(const fraction &a,const fraction &b)
{
    return(a.a*b.b<=a.b*b.a);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        fraction line,l,r;
        line.in(),l.in(),r.in();
        fraction rline=(line.a+21600)%43200;
        set <fraction> res;
        for (int i=0;i<12;i++)
        {
            fraction ans=(line*2-i*3600)/13+i*3600;
            if (l<=ans && ans<=r)
                res.insert(ans);
            ans=(rline*2-i*3600)/13+i*3600;
            if (l<=ans && ans<=r)
                res.insert(ans);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,res.size());
        for (set <fraction>::iterator k=res.begin();k!=res.end();k++)
            k->print();
    }
    return(0);
}

