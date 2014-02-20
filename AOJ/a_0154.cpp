#include <cstdio>
#include <cstring>
int f[10][1010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for (int j=1;j<=y;j++)
            {
                int t=j*x;
                for (int k=t;k<=1000;k++)
                    f[i][k]+=f[i-1][k-t];
            }
            for (int j=0;j<=1000;j++)
                f[i][j]+=f[i-1][j];
        }
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",f[n][x]);
        }
    }
    return(0);
}

