#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    double len() const
    {
        return(sqrt(x*x+y*y+z*z));
    }
    point unit() const
    {
        double t=len();
        return(point(x/t,y/t,z/t));
    }
};
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
point a[210];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
        a[i]=a[i].unit()*260;
    }
    int ans=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            point dir=det(a[i],a[j]);
            if (sign(dir.len())==0)
                continue;
            int up=0,down=0,center=1;
            for (int k=1;k<=n;k++)
            {
                int sgn=sign(dot(dir,a[k]));
                if (sgn==1)
                    up++;
                else if (sgn==-1)
                    down++;
                else
                    center+=sign(dot(dir,det(a[i],a[k])))>0;
            }
            ans=max(ans,max(up,down)+center);
        }
    printf("%d\n",ans);
    return(0);
}

