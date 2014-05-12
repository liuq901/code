#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point
{
    int x,y;
};
ll sqr(int x)
{
    return(ll(x)*x);
}
ll dist(const point &a,const point &b)
{
    return(sqr(a.x-b.x)+sqr(a.y-b.y));
}
point a[100010];
inline bool ystmp(int v1,int v2)
{
    return(a[v1].y<a[v2].y);
}
int ys[100010],tmp[100010];
ll minimal(point c[],int n,int ys[])
{
    int i,j,mid=n/2,cnt=0,xmid=c[mid].x;
    ll ret=1LL<<60;
    if (n<20)
    {
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
            {
                if (dist(c[i],c[j])<ret)
                    ret=dist(c[i],c[j]);
                if (a[ys[i]].y>a[ys[j]].y)
                    swap(ys[i],ys[j]);
            }
        return(ret);
    }
    ret=min(minimal(c,mid,ys),minimal(c+mid,n-mid,ys+mid));
    merge(ys,ys+mid,ys+mid,ys+n,tmp,ystmp);
    copy(tmp,tmp+n,ys);
    for (int i=0;i<n;i++)
    {
        while (i<n && sqr(a[ys[i]].x-xmid)>ret)
            i++;
        int j=i+1,cnt=0;
        while (j<n && sqr(a[ys[j]].y-a[ys[i]].y)<=ret)
        {
            if (sqr(a[ys[j]].x-xmid)<=ret)
            {
                ret=min(ret,dist(a[ys[i]],a[ys[j]]));
                if (++cnt>=10)
                    break;
            }
            j++;
        }
    }
    return(ret);
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        a[i].x=i;
        a[i].y=sum;
    }
    for (int i=0;i<n;i++)
        ys[i]=i;
    printf("%I64d\n",minimal(a,n,ys));
    return(0);
}

