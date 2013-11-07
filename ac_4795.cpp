#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int n=5;
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    bool in()
    {
        return(scanf("%lf%lf%lf",&x,&y,&z)==3);
    }
    double len()
    {
        return(sqrt(x*x+y*y+z*z));
    }
    point unit()
    {
        double t=len();
        return(point(x/t,y/t,z/t));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b,a.z/b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    if (sign(a.x-b.x)!=0)
        return(a.x<b.x);
    if (sign(a.y-b.y)!=0)
        return(a.y<b.y);
    return(a.z<b.z);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline double mix(const point &a,const point &b,const point &c)
{
    return(dot(det(a,b),c));
}
inline point projection(const point &O,const point &norm,const point &p)
{
    return(p-norm*dot(p-O,norm));
}
inline double area(const point &a,const point &b,const point &c)
{
    return(det(b-a,c-a).len());
}
inline double dist(const point &a,const point &b)
{
    return((a-b).len());
}
inline double point_to_line(const point &p,const point &a,const point &b)
{
    return(area(p,a,b)/dist(a,b));
}
point mass,p[10];
double mi,ma;
void work(const point &A,const point &B,const point &C)
{
    point O=A,norm=det(B-A,C-A).unit();
    bool f1,f2;
    f1=f2=false;
    vector <point> plane;
    for (int i=1;i<=n;i++)
    {
        int t=sign(dot(p[i]-O,norm));
        if (t>0)
            f1=true;
        else if (t<0)
            f2=true;
        else
            plane.push_back(p[i]);
    }
    if (f1 && f2)
        return;
    sort(plane.begin(),plane.end());
    point c[10];
    int m=0;
    for (int i=0;i<plane.size();i++)
    {
        while (m>=2 && sign(mix(plane[i]-c[m],c[m]-c[m-1],norm))<=0)
            m--;
        c[++m]=plane[i];
    }
    int limit=m;
    for (int i=plane.size()-1;i>=0;i--)
    {
        while (m>limit && sign(mix(plane[i]-c[m],c[m]-c[m-1],norm))<=0)
            m--;
        c[++m]=plane[i];
    }
    m--;
    c[0]=c[m];
    point P=projection(O,norm,mass);
    double s1,s2;
    s1=s2=0;
    for (int i=1;i<=m;i++)
    {
        s1+=area(O,c[i-1],c[i]);
        s2+=area(P,c[i-1],c[i]);
        if (sign(point_to_line(P,c[i-1],c[i])-0.2)<0)
            return;
    }
    if (sign(s1-s2)!=0)
        return;
    P=projection(O,norm,p[0]);
    double len=(P-p[0]).len();
    mi=min(mi,len);
    ma=max(ma,len);
}
int main()
{
    while (p[1].in())
    {
        for (int i=2;i<=5;i++)
            p[i].in();
        p[0].in();
        double v1=fabs(mix(p[4]-p[1],p[4]-p[2],p[4]-p[3]));
        double v2=fabs(mix(p[5]-p[1],p[5]-p[2],p[5]-p[3]));
        mass=((p[1]+p[2]+p[3]+p[4])*v1+(p[1]+p[2]+p[3]+p[5])*v2)/4/(v1+v2);
        mi=1e100;
        ma=-1e100;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                for (int k=j+1;k<=n;k++)
                    work(p[i],p[j],p[k]);
        static int id=0;
        printf("Case %d: %.5f %.5f\n",++id,mi,ma);
    }
    return(0);
}

