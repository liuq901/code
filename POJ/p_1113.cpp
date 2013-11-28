#include <cstdio>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef complex <double> point;
typedef const point &Point;
const double pi=acos(-1.0),eps=1e-8;
vector <point> a;
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline double det(Point a,Point b)
{
    return((conj(a)*b).imag());
}
inline bool cmp(Point a,Point b)
{
    if (sign(a.real()-b.real())==0)
        return(a.imag()<b.imag());
    return(a.real()<b.real());
}
vector <point> convex(vector <point> a)
{
    vector <point> b;
    sort(a.begin(),a.end(),cmp);
    for (int i=0;i<a.size();i++)
    {
        while (b.size()>=2 && sign(det(b.back()-b[b.size()-2],a[i]-b.back()))<=0)
            b.pop_back();
        b.push_back(a[i]);
    }
    int tmp=b.size();
    for (int i=a.size()-2;i>=0;i--)
    {
        while (b.size()>tmp && sign(det(b.back()-b[b.size()-2],a[i]-b.back()))<=0)
            b.pop_back();
        b.push_back(a[i]);
    }
    return(b);
}
inline double dist(Point a,Point b)
{
    return(abs(a-b));
}
int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    for (int i=1;i<=n;i++)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        a.push_back(point(x,y));
    }
    a=convex(a);
    double ans=pi*l*2;
    for (int i=1;i<a.size();i++)
        ans+=dist(a[i],a[i-1]);
    printf("%.0f\n",ans);
    return(0);
}

