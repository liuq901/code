#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        double r=n/pi;
        printf("%.2f\n",r*r*pi/2);
    }
    return(0);
}

