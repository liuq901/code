#include <cstdio>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
point a[110][4];
double d[110][4];
bool in[110][4];
int p[110];
queue <pair <int,int> > Q;
int main()
{
    int n,K,S,T;
    scanf("%d%d%d%d",&n,&K,&S,&T);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<3;j++)
            scanf("%d%d",&a[i][j].x,&a[i][j].y);
        for (int j=0;j<3;j++)
        {
            point A=a[i][j],B=a[i][(j+1)%3],C=a[i][(j+2)%3];
            if (dot(B-A,C-A)==0)
            {
                a[i][3]=B+C-A;
                break;
            }
        }
        scanf("%d",&p[i]);
        for (int j=0;j<4;j++)
            d[i][j]=1e26;
    }
    for (int i=0;i<4;i++)
    {
        d[S][i]=0;
        in[S][i]=true;
        Q.push(make_pair(S,i));
    }
    while (!Q.empty())
    {
        int x=Q.front().first,y=Q.front().second;
        Q.pop();
        in[x][y]=false;
        for (int i=0;i<4;i++)
            if (sign(d[x][y]+p[x]*dist(a[x][y],a[x][i])-d[x][i])<0)
            {
                d[x][i]=d[x][y]+p[x]*dist(a[x][y],a[x][i]);
                if (!in[x][i])
                {
                    in[x][i]=true;
                    Q.push(make_pair(x,i));
                }
            }
        for (int i=1;i<=n;i++)
        {
            if (i==x)
                continue;
            for (int j=0;j<4;j++)
                if (sign(d[x][y]+K*dist(a[x][y],a[i][j])-d[i][j])<0)
                {
                    d[i][j]=d[x][y]+K*dist(a[x][y],a[i][j]);
                    if (!in[i][j])
                    {
                        in[i][j]=true;
                        Q.push(make_pair(i,j));
                    }
                }
        }
    }
    double ans=1e26;
    for (int i=0;i<4;i++)
        ans=min(ans,d[T][i]);
    printf("%.2f\n",ans);
    return(0);
}

