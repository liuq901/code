#include <cstdio>
#include <cstring>
int a[30][30];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                if (i+j>m+1)
                    a[i][j]=-1;
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<m;j++)
                a[i][m+j]=a[i][m-j];
        for (int i=1;i<n;i++)
            memcpy(a[n+i],a[n-i],sizeof(a[n-i]));
        for (int i=1;i<2*n;i++)
        {
            if (a[i][1]==-1 || i>n && a[i-1][1]==-1)
                continue;
            for (int j=1;j<2*m;j++)
                printf("%c",a[i][j]==-1?' ':a[i][j]+'0');
            printf("\n");
        }
        printf("\n");
    }
    return(0);
}

