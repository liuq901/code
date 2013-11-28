#include <cstdio>
#include <cmath>
int main()
{
    int n,m,id=0,ans;
    double ma=0;
    while (scanf("%d,%d",&n,&m)==2)
    {
        id++;
        double now=m*log(n);
        if (now>ma)
        {
            ma=now;
            ans=id;
        }
    }
    printf("%d\n",ans);
    return(0);
}

