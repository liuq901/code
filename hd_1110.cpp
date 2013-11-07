#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool check(double A,double B,double X,double Y)
{
    if (A*B<=X*Y || Y>=B)
        return(false);
    if (X<A && Y<B)
        return(true);
    double len=sqrt(X*X+Y*Y);
    double angle=asin(B/len)-asin(Y/len);
    return(X*cos(angle)+Y*sin(angle)<A);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double A,B,X,Y;
        scanf("%lf%lf%lf%lf",&A,&B,&X,&Y);
        if (A<B)
            swap(A,B);
        if (X<Y)
            swap(X,Y);
        printf("%s\n",check(A,B,X,Y)?"Escape is possible.":"Box cannot be dropped.");
    }
    return(0);
}

