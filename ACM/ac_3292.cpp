#include <cstdio>
#include <cstring>
int limit,a[60],b[60],f[60][60],g[60][60];
void update(int &a,int &b,int aa,int bb)
{
    if (bb>limit)
        return;
    if (a==-1 || aa<a || a==aa && bb<b)
        a=aa,b=bb;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        bool flag=true;
        for (int i=2;i<=n;i++)
            if (a[i]!=b[i-1])
            {
                flag=false;
                break;
            }
        static int id=0;
        printf("Matrix #%d\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            limit;
            scanf("%d",&limit);
            if (!flag)
                printf("Impossible.\n");
            memset(f,-1,sizeof(f));
            for (int i=1;i<=n;i++)
                f[i][i]=g[i][i]=0;
            for (int i=n;i;i--)
                for (int j=i+1;j<=n;j++)
                    for (int k=i;k<j;k++)
                    {
                        if (f[i][k]==-1 || f[k+1][j]==-1)
                            continue;
                        if (i!=k)
                            update(f[i][j],g[i][j],f[i][k]+f[k+1][j],g[i][k]+a[i]*b[k]*b[j]);
                        update(f[i][j],g[i][j],f[i][k]+f[k+1][j]+1,a[i]*b[k]*b[j]);
                    }
            if (f[1][n]==-1)
                printf("Impossible.\n");
            else
                printf("%d\n",f[1][n]);
        }
        printf("\n");
    }
    return(0);
}

