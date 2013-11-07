#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    point unit()
    {
        double t=sqrt(x*x+y*y);
        return(point(x/t,y/t));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,p-b))==0 && sign(dot(p-a,p-b))<=0);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
string s[20];
int p,c,g,value[20],f[5000];
point a[20],cor[20][2];
char buf[20];
bool check(double v)
{
    vector <point> b;
    for (int i=1;i<=c;i++)
    {
        cor[i][0]=a[s[i][0]-'A'+1];
        cor[i][1]=a[s[i][s[i].size()-1]-'A'+1];
        point dir=(cor[i][1]-cor[i][0]).unit();
        for (int j=0;j<s[i].size();j++)
        {
            int x=s[i][j]-'A'+1;
            if (value[x]!=0)
            {
                b.push_back(a[x]+dir*v/value[x]);
                b.push_back(a[x]-dir*v/value[x]);
            }
            b.push_back(a[x]);
        }
    }
    int begin=0;
    for (int i=1;i<=p;i++)
        if (value[i]==0)
            begin|=1<<i-1;
    memset(f,63,sizeof(f));
    f[begin]=0;
    int limit=(1<<p)-1;
    for (int i=0;i<b.size();i++)
    {
        int now=0;
        point P=b[i];
        for (int j=1;j<=c;j++)
        {
            if (!online(P,cor[j][0],cor[j][1]))
                continue;
            for (int k=0;k<s[j].size();k++)
            {
                int x=s[j][k]-'A'+1;
                if (value[x]==0)
                    continue;
                if (sign(dist(P,a[x])*value[x]-v)<=0)
                    now|=1<<x-1;
            }
        }
        for (int j=limit;j>=0;j--)
            f[j|now]=min(f[j|now],f[j]+1);
    }
    return(f[limit]<=g);
}
int main()
{
    while (scanf("%d%d%d",&p,&c,&g)==3)
    {
        for (int i=1;i<=p;i++)
        {
            char ch;
            scanf(" %c",&ch);
            int x=ch-'A'+1;
            a[x].in();
            scanf("%d",&value[x]);
        }
        for (int i=1;i<=c;i++)
        {
            scanf("%s",buf);
            s[i]=buf;
        }
        double l=0,r=1e12;
        for (int T=1;T<=50;T++)
        {
            double mid=(l+r)/2;
            if (check(mid))
                r=mid;
            else
                l=mid;
        }
        double ans=(l+r)/2;
        if (ans>1e11)
            printf("too few guards\n");
        else
            printf("%.2f\n",ans);
    }
    return(0);
}

