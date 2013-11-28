#include <cstdio>
#include <cstring>
typedef int matrix[2][2];
const int mod=9901;
const matrix zero={{1,0},{0,1}},one={{0,1},{1,1}};
matrix ans;
void multiply(matrix c,matrix a,matrix b)
{
    matrix d={0};
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
void power(int n)
{
    matrix now;
    memcpy(ans,zero,sizeof(zero));
    memcpy(now,one,sizeof(one));
    for (;n;n>>=1)
    {
        if (n&1)
            multiply(ans,ans,now);
        multiply(now,now,now);
    }
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==-1)
            break;
        power(n);
        printf("%d\n",(ans[0][0]+ans[1][0])%mod);
    }
    return(0);
}

