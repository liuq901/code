#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y,z;
    point(double longitude,double latitude)
    {
        longitude*=pi/180;
        latitude*=pi/180;
        x=cos(latitude)*cos(longitude);
        y=cos(latitude)*sin(longitude);
        z=sin(latitude);
    }
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
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b).len())==0);
}
inline void calc(const point &p,double &longitude,double &latitude)
{
    latitude=asin(p.z);
    longitude=atan2(p.y,p.x);
    if (sign(longitude)<0)
        longitude+=2*pi;
    latitude*=180/pi;
    longitude*=180/pi;
    point tmp=point(longitude,latitude);
}
double R,F;
int main()
{
    double r;
    scanf("%lf%*lf%lf",&R,&r);
    R+=r;
    int n;
    scanf("%lf%d",&F,&n);
    point now(0,0,0);
    for (int i=1;i<=n;i++)
    {
        double a1,b1,a2,b2;
        scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);
        now=now+det(point(a1,b1)*R,point(a2,b2)*F);
    }
    now=now*-1;
    if (sign(now.len())==0)
        printf("0 0 0 0 0\n");
    else
    {
        point dir(1,0,0);
        if (parellel(now,dir))
            dir=point(0,1,0);
        dir=det(now,dir).unit();
        point force=det(now,dir).unit();
        double a1,b1,a2,b2;
        calc(dir,a1,b1);
        calc(force,a2,b2);
        printf("%.10f %.10f %.10f %.10f %.10f\n",a1,b1,a2,b2,now.len()/R);
    }
    return(0);
}

