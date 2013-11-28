#include <cstdio>
int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%.0f\n",1000/(a/b+a/c+1)*a);
    return(0);
}

