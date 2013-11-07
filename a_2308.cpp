#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double g=9.8,pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double H(double vy,double t)
{
    return(vy*t-0.5*g*sqr(t));
}
int n;
double V,L[60],R[60],U[60],D[60];
point pig;
vector <double> angle;
double calc(double vx,double vy,double X)
{
    double t=X/vx;
    return(H(vy,t));
}
bool get(double vy,double Y,double &t1,double &t2)
{
    double a=-0.5*g,b=vy,c=-Y;
    double delta=sqr(b)-4*a*c;
    if (sign(delta)<0)
        return(false);
    delta=sqrt(max(0.0,delta));
    t1=(-b+delta)/(2*a);
    t2=(-b-delta)/(2*a);
    return(true);
}
bool check(double theta)
{
    if (sign(theta)==0 || sign(theta-pi/2)==0)
        return(false);
    double vx=V*cos(theta),vy=V*sin(theta);
    double t=vy/g,top=H(vy,t);
    for (int i=1;i<=n;i++)
    {
        if (sign(top-D[i])<=0)
            continue;
        double height=calc(vx,vy,L[i]);
        if (sign(height-D[i])>0 && sign(height-U[i])<0)
            return(false);
        height=calc(vx,vy,R[i]);
        if (sign(height-D[i])>0 && sign(height-U[i])<0)
            return(false);
        double t1,t2;
        if (get(vy,U[i],t1,t2))
        {
            double x1=vx*t1,x2=vx*t2;
            if (sign(x1-L[i])>0 && sign(x1-R[i])<0)
                return(false);
            if (sign(x2-L[i])>0 && sign(x2-R[i])<0)
                return(false);
        }
        if (get(vy,D[i],t1,t2))
        {
            double x1=vx*t1,x2=vx*t2;
            if (sign(x1-L[i])>0 && sign(x1-R[i])<0)
                return(false);
            if (sign(x2-L[i])>0 && sign(x2-R[i])<0)
                return(false);
        }
    }
    double height=calc(vx,vy,pig.x);
    if (sign(height-pig.y)<0)
        return(false);
    for (int i=1;i<=n;i++)
        if (sign(pig.x-L[i])>0 && sign(pig.x-R[i])<0 && sign(pig.y-U[i])<0 && sign(height-U[i])>=0)
            return(false);
    return(true);
}
double tri(const point &p)
{
    double l=0,r=pi/2;
    for (int T=1;T<=100;T++)
    {
        double lx=(2*l+r)/3,rx=(l+2*r)/3;
        if (calc(V*cos(lx),V*sin(lx),p.x)>calc(V*cos(rx),V*sin(rx),p.x))
            r=rx;
        else
            l=lx;
    }
    return((l+r)/2);
}
void work(const point &p)
{
    double best=tri(p),vx=V*cos(best),vy=V*sin(best);
    int signum=sign(calc(vx,vy,p.x)-p.y);
    double l=0,r=best;
    for (int T=1;T<=100;T++)
    {
        double mid=(l+r)/2;
        double vx=V*cos(mid),vy=V*sin(mid);
        if (sign(calc(vx,vy,p.x)-p.y)*signum<=0)
            l=mid;
        else
            r=mid;
    }
    angle.push_back((l+r)/2);
    l=best,r=pi/2;
    for (int T=1;T<=100;T++)
    {
        double mid=(l+r)/2;
        double vx=V*cos(mid),vy=V*sin(mid);
        if (sign(calc(vx,vy,p.x)-p.y)*signum<=0)
            r=mid;
        else
            l=mid;
    }
    angle.push_back((l+r)/2);
}
int main()
{
    scanf("%d%lf%lf%lf",&n,&V,&pig.x,&pig.y);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf%lf",&L[i],&D[i],&R[i],&U[i]);
        if (sign(L[i]-pig.x)>=0)
            i--,n--;
        else
            R[i]=min(R[i],pig.x);
    }
    work(pig);
    for (int i=1;i<=n;i++)
    {
        work(point(L[i],U[i]));
        work(point(R[i],U[i]));
        work(point(L[i],D[i]));
        work(point(R[i],D[i]));
        double t=sqrt(2*D[i]/g);
        double vy=g*t;
        if (sign(vy-V)<0 && sign(vy)>0)
            angle.push_back(asin(vy/V));
    }
    sort(angle.begin(),angle.end());
    bool flag=false;
    for (int i=0;i<angle.size();i++)
    {
        if (check(angle[i]))
        {
            flag=true;
            break;
        }
        if (i>0 && check((angle[i-1]+angle[i])/2))
        {
            flag=true;
            break;
        }
    }
    printf("%s\n",flag?"Yes":"No");
    return(0);
}

