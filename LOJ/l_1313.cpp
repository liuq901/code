#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline void convex(point a[],int &n)
{
    sort(a+1,a+n+1);
    point b[110];
    int m=0;
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && det(b[m]-b[m-1],a[i]-b[m])<=0)
            m--;
        b[++m]=a[i];
    }
    int rev=m;
    for (int i=n-1;i;i--)
    {
        while (m>rev && det(b[m]-b[m-1],a[i]-b[m])<=0)
            m--;
        b[++m]=a[i];
    }
    n=m-1;
    for (int i=1;i<=n;i++)
        a[i]=b[i];
}
inline bool in(const point &p,point a[],int n)
{
    a[0]=a[n];
    int res=0;
    for (int i=1;i<=n;i++)
    {
        point A=a[i-1],B=a[i];
        if (A.y<=B.y)
            swap(A,B);
        if (p.y>A.y || p.y<=B.y)
            continue;
        res+=det(B-p,A-p)>0;
    }
    return(res&1);
}
point a[110],p[110],tmp[110];
int d[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,G,P;
        scanf("%d%d%d%d",&n,&m,&G,&P);
        for (int i=1;i<=n;i++)
        {
            a[i].in();
            tmp[i]=a[i];
        }
        for (int i=1;i<=m;i++)
            p[i].in();
        int N=n;
        convex(a,n);
        int t=0;
        for (int i=1;i<=m;i++)
            if (in(p[i],a,n))
                p[++t]=p[i];
        int ans=G*(m-t);
        if (t)
        {
            n=N;
            for (int i=1;i<=n;i++)
                a[i]=tmp[i];
            m=t;
            memset(d,63,sizeof(d));
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                {
                    if (i==j)
                        continue;
                    bool flag=true;
                    for (int k=1;k<=m;k++)
                        if (det(a[j]-a[i],p[k]-a[i])<=0)
                        {
                            flag=false;
                            break;
                        }
                    if (flag)
                        d[i][j]=1;
                }
            for (int k=1;k<=n;k++)
                for (int i=1;i<=n;i++)
                    for (int j=1;j<=n;j++)
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            int best=1<<30;
            for (int i=1;i<=n;i++)
                best=min(best,d[i][i]);
            ans+=best*P;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

