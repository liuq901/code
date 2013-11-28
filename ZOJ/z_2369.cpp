#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double H=1e-5;
struct F
{
    double r1,r2;
    F(double r1,double r2):r1(r1*r1),r2(r2*r2){}
    double operator ()(double x)
    {
        x*=x;
        return(sqrt((r2-x)*(r1-x)));
    }
};
void main2()
{
    double r1,r2;
    scanf("%lf%lf",&r1,&r2);
    if (r1>r2)
        swap(r1,r2);
    int n=int(r1/H);
    double h=r1/n/2;
    F f(r1,r2);
    double s=0;
    s+=f(0)+f(r1);
    for (int i=1;i<2*n;i++)
        s+=i&1?4*f(i*h):2*f(i*h);
    s=s/6/n*8*r1;
    printf("%.4f\n",s);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        main2();
    return(0);
}

