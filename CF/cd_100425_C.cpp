#include <cstdio>
typedef long long ll;
struct point
{
    ll x,y;
    point(){}
    point(ll x,ll y):x(x),y(y){}
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(ll x)
{
    return(x<0?-1:x>0);
}
inline ll det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(b-a,p-a)));
}
point o,p1,p2,p3,p4,ans,a[100010];
int n;
ll A,B,C,S,x0,y0;
inline point get(int t)
{
    return(o+point(x0-B*t,y0+A*t));
}
void calc(const point &a,const point &b,int &L,int &R)
{
    if (L>R)
        return;
    int p=side(get(L),a,b);
    int q=side(get(R),a,b);
    if (p>0 && q>0)
        return;
    if (p<=0 && q<=0)
    {
        L=1,R=0;
        return;
    }
    int l=L,r=R,ans=0;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (side(get(mid),a,b)==1)
        {
            ans=mid;
            if (p==1)
                l=mid+1;
            else
                r=mid-1;
        }
        else if (p==1)
            r=mid-1;
        else
            l=mid+1;
    }
    if (p==1)
        R=ans;
    else
        L=ans;
}
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return(a);
    }
    ll ret=gcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*y;
    return(ret);
}
bool work(int id)
{
    A=a[id+1].y-a[id].y;
    B=a[id].x-a[id+1].x;
    C=S;
    ll p=gcd(A,B,x0,y0);
    if (C%p!=0)
        return(false);
    A/=p,B/=p,C/=p;
    x0*=C,y0*=C;
    int L=-1000000000,R=1000000000;
    o=a[id];
    calc(p1,p2,L,R);
    calc(p2,p3,L,R);
    calc(p3,p4,L,R);
    calc(p4,p1,L,R);
    calc(a[id+1],a[id],L,R);
    calc(a[id-1],a[id],L,R);
    calc(a[id+1],a[id+2],L,R);
    if (L<=R)
    {
        ans=get(L);
        return(true);
    }
    return(false);
}
int main()
{
    int n;
    double tmp;
    scanf("%d%lf",&n,&tmp);
    n--;
    S=ll(tmp*2+0.5);
    for (int i=1;i<=n;i++)
        scanf("%I64d%I64d",&a[i].x,&a[i].y);
    a[0]=a[n];
    a[n+1]=a[1];
    a[n+2]=a[2];
    for (int i=1;i<=n;i++)
        S-=det(a[i-1],a[i]);
    p1=point(-1000001,-1000001);
    p2=point(1000001,-1000001);
    p3=point(1000001,1000001);
    p4=point(-1000001,1000001);
    for (int i=1;i<=n;i++)
        if (work(i))
        {
            printf("%I64d %I64d\n",ans.x,ans.y);
            break;
        }
    return(0);
}

