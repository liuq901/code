#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double x,y,c;
        scanf("%lf%lf%lf",&x,&y,&c);
        double l=0,r=min(x,y);
        for (int _=1;_<=100;_++)
        {
            double mid=(l+r)/2;
            double a=sqrt(x*x-mid*mid),b=sqrt(y*y-mid*mid);
            double l1=c*mid/a,l2=c*mid/b;
            if (l1+l2<mid)
                l=mid;
            else
                r=mid;
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,(l+r)/2);
    }
    return(0);
}

