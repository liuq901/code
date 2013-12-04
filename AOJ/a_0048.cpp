#include <cstdio>
const double a[]={48,51,54,57,60,64,69,75,81,91};
const char ans[][20]={"light fly","fly","bantam","feather","light","light welter","welter","light middle","middle","light heavy","heavy"};
const char *get(double x)
{
    for (int i=0;i<10;i++)
        if (x<=a[i])
            return(ans[i]);
    return(ans[10]);
}
int main()
{
    double x;
    while (scanf("%lf",&x)==1)
        printf("%s\n",get(x));
    return(0);
}

