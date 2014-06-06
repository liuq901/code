#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double v1,v2,v3,a1,a2;
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        double t1=v1/a1,t2=v2/a2;
        static int id=0;
        printf("Case %d: %.10f %.10f\n",++id,0.5*(a1*t1*t1+a2*t2*t2),v3*max(t1,t2));
    }
    return(0);
}

