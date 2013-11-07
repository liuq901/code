#include <cstdio>
int ans[160],f[160][160];
bool isPrime(int x)
{
    if (x<=1)
        return(false);
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return(false);
    return(true);
}
void init()
{
    f[0][0]=1;
    for (int i=1;i<=150;i++)
        for (int j=0;j<=i;j++)
        {
            for (int k=j;k<=i;k++)
            {
                if (isPrime(k))
                    f[i][k]+=f[i-k][j];
            }
            ans[i]+=f[i][j];
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
        printf("%d\n",ans[n]);
    }
    return(0);
}

