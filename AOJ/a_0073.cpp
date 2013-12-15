#include <cstdio>
#include <cmath>
int main()
{
    while (1)
    {
        int x,h;
        scanf("%d%d",&x,&h);
        if (x==0 && h==0)
            break;
        double d=x/2.0;
        double l=sqrt(d*d+h*h);
        printf("%.10f\n",x*x+x*l*2);
    }
    return(0);
}

