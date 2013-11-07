#include <cstdio>
#include <cstring>
const int mod=10000;
int a[110],b[110],f[110][3010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int m=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            m+=a[i]*b[i];
        }
        if (m%3==0)
        {
            m/=3;
            memset(f,0,sizeof(f));
            f[0][0]=1;
            for (int i=1;i<=n;i++)
            {
                for (int j=0;j<=m;j++)
                    f[i][j]=f[i-1][j];
                for (int j=1;j<=b[i];j++)
                {
                    int p=a[i]*j;
                    for (int k=p;k<=m;k++)
                        f[i][k]=(f[i][k]+f[i-1][k-p])%mod;
                }
            }
            if (f[n][m]==0)
                printf("sorry\n");
            else
                printf("%d\n",f[n][m]);
        }
        else
            printf("sorry\n");
    }
    return(0);
}

