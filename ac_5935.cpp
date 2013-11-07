#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N=110;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
bool alive[N];
point a[N];
double r[N];
vector <int> now;
int adj[N][N];
void dfs(int x)
{
    now.push_back(x);
    alive[x]=false;
    for (int i=1;i<=adj[x][0];i++)
    {
        int y=adj[x][i];
        if (alive[y])
            dfs(y);
    }
}
int main()
{
    while (1)
    {
        int N;
        scanf("%d",&N);
        if (N==0)
            break;
        for (int i=1;i<=N;i++)
        {
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&r[i]);
            alive[i]=true;
        }
        for (int n=1;n<=N;n++)
            while (1)
            {
                for (int i=1;i<=n;i++)
                {
                    adj[i][0]=0;
                    if (!alive[i])
                        continue;
                    for (int j=1;j<=n;j++)
                    {
                        if (!alive[j] || i==j)
                            continue;
                        if (sign(max(r[i],r[j])-dist(a[i],a[j]))>=0)
                            adj[i][++adj[i][0]]=j;
                    }
                }
                bool change=false;
                for (int i=1;i<=n;i++)
                    if (adj[i][0]>0 && alive[i])
                    {
                        change=true;
                        now.clear();
                        dfs(i);
                        point o(0,0);
                        double tot=0;
                        for (int j=0;j<now.size();j++)
                        {
                            int x=now[j];
                            o=o+a[x];
                            tot+=sqr(r[x]);
                        }
                        alive[i]=true;
                        a[i]=o/now.size();
                        r[i]=sqrt(tot);
                    }
                if (!change)
                    break;
            }
        printf("%d\n",count(alive+1,alive+N+1,true));
    }
    return(0);
}

