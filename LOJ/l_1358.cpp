#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    double len() const
    {
        return(sqrt(x*x+y*y));
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
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
inline double Sqrt(double x)
{
    if (sign(x)==0)
        return(0);
    return(sqrt(x));
}
inline double Asin(double x)
{
    if (sign(x+1)==0)
        return(asin(-1.0));
    if (sign(x-1)==0)
        return(asin(1.0));
    return(asin(x));
}
inline double Acos(double x)
{
    if (sign(x+1)==0)
        return(acos(-1.0));
    if (sign(x-1)==0)
        return(acos(1.0));
    return(acos(x));
}
inline double area(const point &pa,const point &pb,double r)
{
    if (sign(pa.len()-pb.len())<0)
        return(area(pb,pa,r));
    if (sign(pb.len())==0)
        return(0);
    double a=pb.len();
    double b=pa.len();
    double c=(pb-pa).len();
    double cosB=dot(pb,pb-pa)/a/c;
    double B=Acos(cosB);
    double cosC=dot(pa,pb)/a/b;
    double C=Acos(cosC);
    double S;
    if (sign(a-r)>0)
    {
        S=C/2*r*r;
        double h=a*b*sin(C)/c;
        if (sign(h-r)<0 && sign(B-pi/2)<0)
            S-=Acos(h/r)*r*r-h*Sqrt(r*r-h*h);
    }
    else if (sign(b-r)>0)
    {
        double theta=pi-B-Asin(sin(B)/r*a);
        S=0.5*a*r*sin(theta)+(C-theta)/2*r*r;
    }
    else
        S=0.5*sin(C)*a*b;
    return(S);
}
inline double calc(point p[],int n,double r)
{
    double S=0;
    for (int i=1;i<=n;i++)
        S+=area(p[i-1],p[i],r)*sign(det(p[i-1],p[i]));
    return(fabs(S));
}
point p[5010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        point o;
        double P;
        scanf("%lf%lf%lf",&o.x,&o.y,&P);
        P/=100;
        for (int i=1;i<=n;i++)
            p[i]=p[i]-o;
        p[0]=p[n];
        double sum=0;
        for (int i=1;i<=n;i++)
            sum+=det(p[i],p[i-1]);
        sum=fabs(sum)/2;
        double l=0,r=1e10;
        for (int _=1;_<=50;_++)
        {
            double mid=(l+r)/2;
            if (sign(calc(p,n,mid)-sum*P)>=0)
                r=mid;
            else
                l=mid;
        }
        static int id=0;
        printf("Case %d: %.0f\n",++id,(l+r)/2);
    }
    return(0);
}

