#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const double inf=1e26;
int n,m,Sx,Sy,Tx,Ty,cnt;
ll det(int x1,int y1,int x2,int y2)
{
    return(ll(x1)*y2-ll(x2)*y1);
}
ll dot(int x1,int y1,int x2,int y2)
{
    return(ll(x1)*x2+ll(y1)*y2);
}
bool online(int x0,int y0,int x1,int y1,int x2,int y2)
{
    x1-=x0,y1-=y0,x2-=x0,y2-=y0;
    return(det(x1,y1,x2,y2)==0 && dot(x1,y1,x2,y2)<=0);
}
double sqr(double x)
{
    return(x*x);
}
double dist(double x1,double y1,double x2,double y2)
{
    return(sqrt(sqr(x1-x2)+sqr(y1-y2)));
}
double work(int X,int Y)
{
    int x=X*n+(X&1?n-Tx:Tx);
    int y=Y*m+(Y&1?m-Ty:Ty);
    for (int i=min(X,0);i<=max(X,0);i++)
        for (int j=min(Y,0);j<=max(Y,0);j++)
        {
            int x0=i*n+(i&1?n-Tx:Tx);
            int y0=j*m+(j&1?m-Ty:Ty);
            if (x0==x && y0==y)
                continue;
            if (online(x0,y0,Sx,Sy,x,y))
                return(inf);
        }
    return(dist(Sx,Sy,x,y));
}
int main()
{
    while (1)
    {
        scanf("%d%d%d%d%d%d%d",&n,&m,&Sx,&Sy,&Tx,&Ty,&cnt);
        if (n==0 && m==0)
            break;
        double ans=inf;
        for (int i=0;i<=cnt;i++)
        {
            int j=cnt-i;
            double now=min(min(work(i,j),work(-i,j)),min(work(i,-j),work(-i,-j)));
            ans=min(ans,now);
        }
        printf("%.3f\n",ans);
    }
    return(0);
}

