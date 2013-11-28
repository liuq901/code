#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
const double eps=1e-8,pi=acos(-1.0);
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
double fix(double theta)
{
    if (sign(theta)<0)
        theta+=2*pi;
    if (sign(theta-2*pi)>=0)
        theta-=2*pi;
    return(theta);
}
void print(double ans)
{
    static int id=0;
    printf("Case %d: ",++id);
    if (sign(ans)==0)
        printf("Acceptable as proposed\n");
    else if (fabs(ans)>pi+1)
        printf("Unacceptable\n");
    else
        printf("Acceptable after %s rotation of %.2f degrees\n",sign(ans)<0?"clockwise":"counterclockwise",fabs(ans)/pi*180);
    printf("\n");
}
point a[10010];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        if (m==0)
        {
            print(0);
            continue;
        }
        pair <double,double> cw,ccw;
        cw=ccw=make_pair(0,pi);
        a[0]=point(0,0);
        for (int i=1;i<=n;i++)
        {
            double theta=atan2(a[i].y-a[i-1].y,a[i].x-a[i-1].x);
            if (a[i].x>=a[i-1].x)
            {
                cw.second=min(cw.second,fix(theta+pi/2));
                ccw.second=min(ccw.second,fix(pi/2-theta));
            }
            else
            {
                cw.first=max(cw.first,fix(theta-pi/2));
                ccw.first=max(ccw.first,fix(-pi/2-theta));
            }
        }
        if (sign(cw.first-cw.second)==1)
            cw.first=pi+2;
        if (sign(ccw.first-ccw.second)==1)
            ccw.first=pi+2;
        if (sign(cw.first-ccw.first)<=0)
            print(-cw.first);
        else
            print(ccw.first);
    }
    return(0);
}

