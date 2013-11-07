#include <cstdio>
#include <cstring>
int a[110][110],b[110][110],c[110][110];
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
                scanf("%d",&a[i][j]);
        int p;
        scanf("%*d%d",&p);
        for (int i=1;i<=m;i++)
            for (int j=1;j<=p;j++)
                scanf("%d",&b[i][j]);
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=1;k<=p;k++)
                    c[i][k]+=a[i][j]*b[j][k];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=p;j++)
                printf("%d%c",c[i][j],j==p?'\n':' ');
        printf("\n");
    }
    return(0);
}

