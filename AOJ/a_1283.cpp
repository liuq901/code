#include <cstdio>
#include <vector>
#include <complex>
#define X real()
#define Y imag()
using namespace std;
typedef complex <double> point;
typedef const point &Point;
const double pi=acos(-1.0),eps=1e-8;
point a[110];
vector <point> poly;
inline point unit(Point a)
{
    double t=abs(a);
    return(point(a.X/t,a.Y/t));
}
inline point rotate(Point a)
{
    return(point(-a.Y,a.X));
}
inline double det(Point a,Point b)
{
    return((conj(a)*b).Y);
}
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
bool intersect(Point A,Point B,Point P,Point Q,point &T)
{
    if (sign(det(Q-A,B-A))*sign(det(P-A,B-A))!=-1)
        return(false);
    double t=det(A-P,P-Q)/det(A-B,P-Q);
    T=A+(B-A)*t;
    return(true);
}
bool work(Point A,Point B)
{
    vector <point> now;
    for (int i=1;i<poly.size();i++)
    {
        point P=poly[i-1],Q=poly[i];
        if (sign(det(B-A,P-B))>=0)
            now.push_back(P);
        point T;
        if (intersect(A,B,P,Q,T))
            now.push_back(T);
    }
    if (now.size()<3)
        return(false);
    now.push_back(now[0]);
    poly=now;
    return(true);
}
bool check(double mid,int n)
{
    poly.clear();
    poly.push_back(point(-1,-1));
    poly.push_back(point(10001,-1));
    poly.push_back(point(10001,10001));
    poly.push_back(point(-1,10001));
    poly.push_back(point(-1,-1));
    bool flag=true;
    for (int i=1;i<=n;i++)
    {
        point v=unit(rotate(a[i]-a[i-1]));
        if (!work(a[i-1]+v*mid,a[i]+v*mid))
        {
            flag=false;
            break;
        }
    }
    return(flag);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].X,&a[i].Y);
        a[0]=a[n];
        double l=0,r=5000;
        while (r-l>eps)
        {
            double mid=(l+r)/2;
            if (check(mid,n))
                l=mid;
            else
                r=mid;
        }
        printf("%.6f\n",(l+r)/2);
    }
    return(0);
}

