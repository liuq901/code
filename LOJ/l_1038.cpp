#include <cstdio>
double f[100010];
void init()
{
    const int n=100000;
    for (int i=2;i<=n;i++)
    {
        int cnt=0;
        double sum=0;
        for (int j=1;j*j<=i;j++)
            if (i%j==0)
            {
                cnt++;
                sum+=f[j];
                if (j*j!=i)
                {
                    cnt++;
                    sum+=f[i/j];
                }
            }
        f[i]=(sum+cnt)/(cnt-1);
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
        static int id=0;
        printf("Case %d: %.10f\n",++id,f[n]);
    }
    return(0);
}

