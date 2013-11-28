#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-8;
const int maxn=1000;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
point operator +(point a,point b)
{
    return(point(a.x+b.x,a.y+b.y));
}
point operator *(point a,double b)
{
    return(point(a.x*b,a.y*b));
}
point operator /(point a,double b)
{
    return(point(a.x/b,a.y/b));
}
double det(point c,point a,point b)
{
    return((a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x));
}
int dcmp(double x)
{
    return(x<-eps?-1:x>eps);
}
bool cross(point a,point b,point c,point d,point &t)
{
    double u=det(a,c,b),v=det(a,b,d);
    if (!dcmp(u+v))
        return(false);
    t=(c*v+d*u)/(u+v);
    return(true);
}
point q[maxn];
struct polygon
{
    point p[maxn];
    int n;
    void cut(point a,point b)
    {
        int tot=0;
        for (int i=0;i<n;i++)
        {
            if (dcmp(det(a,b,p[i]))>=0)
                q[tot++]=p[i];
            if (dcmp(det(a,b,p[i]))*dcmp(det(a,b,p[i+1]))<0 && cross(a,b,p[i],p[i+1],q[tot]))
                tot++;
        }
        if (tot<3)
            tot=0;
        for (int i=0;i<tot;i++)
            p[i]=q[i];
        n=tot;
        p[n]=p[0];
    }
    void init()
    {
        n=0;
        p[n++]=point(0,0);
        p[n++]=point(0,10000);
        p[n++]=point(10000,10000);
        p[n++]=point(10000,0);
        p[n]=p[0];
    }
};
bool sameside(point u,point v,point a,point b)
{
    return(dcmp(det(a,b,u))*dcmp(det(a,b,v))>0);
}
vector <int> id;
polygon sta[50];
int n,c[50*50];
point A[50],B[50],ori;
void dfs(int dep)
{
    if (!sta[dep].n)
        return;
    if (dep==n)
    {
        int now=0;
        for (int i=0;i<n;i++)
        {
            int ok=0;
            for (int j=0;!ok && j<sta[dep].n;j++)
                if (sameside(ori,sta[dep].p[j],A[i],B[i]))
                    ok=1;
            if (ok)
                now=(now<<1)+1;
            else
                now<<=1;
        }
        id.push_back(now);
        return;
    }
    sta[dep+1]=sta[dep];
    sta[dep+1].cut(A[dep],B[dep]);
    dfs(dep+1);
    sta[dep+1]=sta[dep];
    sta[dep+1].cut(B[dep],A[dep]);
    dfs(dep+1);
}
bool g[1000][1000];
void fill(int x,int color)
{
    if (c[x])
        return;
    c[x]=color;
    for (int i=0;i<id.size();i++)
        if (g[x][i])
            fill(i,3-color);
}
int main()
{
    ori=point(0,0);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            A[i].in();
            B[i].in();
        }
        id.clear();
        sta[0].init();
        dfs(0);
        sort(id.begin(),id.end());
        memset(g,0,sizeof(g));
        for (int i=0;i<id.size();i++)
            for (int j=i+1;j<id.size();j++)
            {
                int x=id[i],y=id[j],t=0;
                for (int k=0;k<n;k++)
                    if ((x>>k&1)!=(y>>k&1))
                        t++;
                if (t==1)
                    g[i][j]=g[j][i]=true;
            }
        memset(c,0,sizeof(c));
        fill(0,1);
        printf("2\n");
        for (int i=0;i<id.size();i++)
            printf("%d %d\n",id[i],c[i]);
    }
    return(0);
}

