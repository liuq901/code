#include <cstdio>
#include <cstring>
int a[10][10],b[10][10],c[10][10],d[10][10];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        for (int i=1;i<=9;i++)
            for (int j=1;j<=9;j++)
            {
                scanf("%d",&a[i][j]);
                b[i][a[i][j]]++;
                c[j][a[i][j]]++;
                d[(i-1)/3*3+(j-1)/3+1][a[i][j]]++;
            }
        for (int i=1;i<=9;i++)
        {
            for (int j=1;j<=9;j++)
            {
                if (b[i][a[i][j]]>1 || c[j][a[i][j]]>1 || d[(i-1)/3*3+(j-1)/3+1][a[i][j]]>1)
                    printf("*");
                else
                    printf(" ");
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
        if (T)
            printf("\n");
    }
    return(0);
}

