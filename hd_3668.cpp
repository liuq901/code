#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
inline double sqr(double x)
{
    return(x*x);
}
int main()
{
    int R,H;
    while (scanf("%d%d",&R,&H)==2)
    {
        double ans=2.0/3.0*sqr(R)*R;
        if (2*R>H)
        {
            double p=sqrt(sqr(R)-sqr(H/2.0));
            ans+=p*sqr(H/2.0)-sqr(R)*p+sqr(p)*p/3;
        }
        printf("%.4f\n",2*pi*sqr(R)*H-ans*8);
    }
    return(0);
}

