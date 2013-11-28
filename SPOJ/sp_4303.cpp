#include <cstdio>
const double eps=1e-8;
double f[610][3610];
int main()
{
    f[0][0]=1;
    for (int i=0;i<600;i++)
        for (int j=0;j<=3600;j++)
            for (int x=1;x<=6;x++)
            {
                if (j+x>3600)
                    break;
                f[i+1][j+x]+=f[i][j]/6.0;
            }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if (n>600 || k>n*6)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",int(f[n][k]*100+eps));
    }
    return(0);
}

