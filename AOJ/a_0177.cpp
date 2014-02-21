#include <cstdio>
#include <cmath>
double dist(double lati1,double longi1,double lati2,double longi2,double R)
{
    double pi=acos(-1.0);
    lati1*=pi/180,longi1*=pi/180,lati2*=pi/180,longi2*=pi/180;
    double x1=cos(lati1)*sin(longi1),y1=cos(lati1)*cos(longi1),z1=sin(lati1);
    double x2=cos(lati2)*sin(longi2),y2=cos(lati2)*cos(longi2),z2=sin(lati2);
    double theta=acos(x1*x2+y1*y2+z1*z2);
    return(R*theta);
}
int main()
{
    while (1)
    {
        double lati1,longi1,lati2,longi2;
        scanf("%lf%lf%lf%lf",&lati1,&longi1,&lati2,&longi2);
        if (lati1==-1 && longi1==-1 && lati2==-1 && longi2==-1)
            break;
        printf("%.0f\n",dist(lati1,longi1,lati2,longi2,6378.1));
    }
    return(0);
}

