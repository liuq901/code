#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
priority_queue <double> Q;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        double x;
        scanf("%lf",&x);
        Q.push(x);
    }
    while (Q.size()>=2)
    {
        double x=Q.top();
        Q.pop();
        double y=Q.top();
        Q.pop();
        Q.push(2*sqrt(x*y));
    }
    printf("%.2f\n",Q.top());
    return(0);
}

