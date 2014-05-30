#include <cstdio>
#include <cmath>
double ans[1000010];
void init()
{
    const int n=100000000;
    double sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=1.0/i;
        if (i%100==0)
            ans[i/100]=sum;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int base=n/100*100;
        double sum=ans[n/100];
        for (int i=base+1;i<=n;i++)
            sum+=1.0/i;
        static int id=0;
        printf("Case %d: %.10f\n",++id,sum);
    }
    return(0);
}

