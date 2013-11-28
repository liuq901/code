#include <cstdio>
#include <cmath>
const double Gamma=0.577215664901532860606512090082402431042159335939923598805767234;
int main()
{
    double a;
    while (scanf("%lf",&a)==1)
        printf("%.12e\n",(pow(2.0,a)-1)*Gamma);
    return(0);
}

