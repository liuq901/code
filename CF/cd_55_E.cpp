#include <cstdio>
typedef long long ll;
struct point
{
    int x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
point a[200010];
int main()
{
    int n;
    scanf("%d",&n);
    ll N=ll(n)*(n-1)*(n-2)/6;
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    for (int i=1;i<=n;i++)
        a[i+n]=a[i];
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        point P;
        scanf("%d%d",&P.x,&P.y);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            if (det(a[i+1]-a[i],P-a[i])<0)
            {
                int l=i+1,r=i+n-1,p;
                while (l<=r)
                {
                    int mid=l+r>>1;
                    if (det(a[mid]-a[i],P-a[i])<0)
                        p=mid,l=mid+1;
                    else
                        r=mid-1;
                }
                ans+=ll(p-i)*(p-i-1)/2;
                continue;
            }
            ans=N;
            break;
        }
        printf("%I64d\n",N-ans);
    }
    return(0);
}

