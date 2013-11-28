#include <cstdio>
#include <cstring>
typedef int matrix[2][2];
const int mod=7;
matrix zero,one,ans;
void multi(const matrix &a,const matrix &b)
{
    matrix c;
    memset(c,0,sizeof(c));
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(ans,c,sizeof(c));
}
void power(int n)
{
    if (n==0)
    {
        memcpy(ans,zero,sizeof(zero));
        return;
    }
    power(n>>1);
    multi(ans,ans);
    if (n&1)
        multi(ans,one);
}
int main()
{
    zero[0][0]=zero[1][1]=1;
    one[1][0]=1;
    while (1)
    {
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        if (a==0 && b==0 && n==0)
            break;
        one[0][1]=b,one[1][1]=a;
        power(n-1);
        printf("%d\n",(ans[0][0]+ans[1][0])%mod);
    }
    return(0);
}

