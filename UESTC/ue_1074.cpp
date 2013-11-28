#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double H,R,h;
        scanf("%lf%lf%lf",&H,&R,&h);
        h=H-h;
        double r=h/H*R;
        printf("%.2f\n",(pi*R*R*H/3-pi*r*r*h/3)*0.2);
    }
    return(0);
}

