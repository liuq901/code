#include <cstdio>
#include <cstring>
typedef int matrix[3][3];
matrix a,b,c;
void multi(matrix a,matrix b,matrix c)
{
    matrix d={0};
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++)
                d[i][j]+=a[i][k]*b[k][j];
    memcpy(c,d,sizeof(d));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                scanf("%d",&a[i][j]);
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                scanf("%d",&b[i][j]);
        multi(a,b,c);
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return(0);
}

