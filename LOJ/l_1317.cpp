#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        double p;
        scanf("%d%*d%d%lf",&n,&K,&p);
        static int id=0;
        printf("Case %d: %.10f\n",++id,n*K*p);
    }
    return(0);
}

