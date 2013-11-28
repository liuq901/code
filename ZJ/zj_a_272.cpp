#include <cstdio>
#include <cstring>
typedef int matrix[2][2];
const int mod=10007;
matrix zero,one,ans;
void multi(matrix c,matrix a,matrix b)
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
    memcpy(ans,zero,sizeof(zero));
    for (;n;n>>=1)
    {
        if (n&1)
            multi(ans,ans,one);
        multi(one,one,one);
    }
}
int main()
{
    zero[0][0]=zero[1][1]=1;
    int n;
    while (scanf("%d",&n)==1)
    {
        one[0][0]=0;
        one[1][1]=one[0][1]=one[1][0]=1;
        power(n);
        printf("%d\n",(ans[0][0]+ans[1][0])%mod);
    }
    return(0);
}

