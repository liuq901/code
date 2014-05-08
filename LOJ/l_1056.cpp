#include <cstdio>
#include <cmath>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d : %d",&a,&b);
        double t=double(a)/b;
        double r=sqrt(1+t*t);
        double theta=atan(1/t)*2;
        double dis=theta*r;
        double x=400/(4*t+2*dis);
        static int id=0;
        printf("Case %d: %.10f %.10f\n",++id,2*t*x,2*x);
    }
    return(0);
}

