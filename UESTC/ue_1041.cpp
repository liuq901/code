#include <cstdio>
#include <cstring>
typedef int matrix[10][10];
matrix a,b,c;
void multi(matrix a,matrix b,matrix c,int A,int B,int C)
{
    matrix d={0};
    for (int i=0;i<A;i++)
        for (int j=0;j<C;j++)
            for (int k=0;k<B;k++)
                d[i][j]+=a[i][k]*b[k][j];
    memcpy(c,d,sizeof(d));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        for (int i=0;i<A;i++)
            for (int j=0;j<B;j++)
                scanf("%d",&a[i][j]);
        for (int i=0;i<B;i++)
            for (int j=0;j<C;j++)
                scanf("%d",&b[i][j]);
        multi(a,b,c,A,B,C);
        for (int i=0;i<A;i++)
        {
            for (int j=0;j<C;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return(0);
}

