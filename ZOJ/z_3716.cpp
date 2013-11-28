#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double X[10],Y[10];
double sqr(double x)
{
    return(x*x);
}
double dist(int a,int b)
{
    return(sqrt(sqr(X[a]-X[b])+sqr(Y[a]-Y[b])));
}
int main()
{
    while (scanf("%lf%lf",&X[0],&Y[0])==2)
    {
        for (int i=1;i<4;i++)
            scanf("%lf%lf",&X[i],&Y[i]);
        double ans=dist(0,1)+dist(2,3);
        double ans1=min(dist(0,2)+dist(1,3),dist(0,3)+dist(1,2));
        ans=min(ans,ans1);
        printf("%.12f\n",ans);
    }
    return(0);
}

