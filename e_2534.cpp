#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,c,r,h;
        scanf("%d%d%d%d%d",&a,&b,&c,&r,&h);
        printf("%.2f\n",min(double(a)*b*c,pi*r*r*h));
    }
    return(0);
}

