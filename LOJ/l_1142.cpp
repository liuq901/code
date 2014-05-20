#include <cstdio>
#include <cstring>
int n;
struct matrix
{
    int a[30][30];
    matrix()
    {
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
            a[i][i]=1;
    }
};
inline matrix operator +(const matrix &a,const matrix &b)
{
    matrix c;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            c.a[i][j]=(a.a[i][j]+b.a[i][j])%10;
    return(c);
}
inline matrix operator *(const matrix &a,const matrix &b)
{
    matrix c;
    for (int i=0;i<n;i++)
        c.a[i][i]=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%10;
    return(c);
}
matrix a;
matrix power(int n)
{
    matrix ret,x=a;
    for (;n;n>>=1)
    {
        if (n&1)
            ret=ret*x;
        x=x*x;
    }
    return(ret);
}
matrix calc(int n)
{
    if (n==0)
        return(matrix());
    if (n==1)
        return(a);
    matrix sum=calc(n/2);
    sum=sum+sum*power(n/2);
    if (n&1)
        sum=sum+power(n);
    return(sum);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int K;
        scanf("%d%d",&n,&K);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                scanf("%d",&a.a[i][j]);
                a.a[i][j]%=10;
            }
        matrix ans=calc(K);
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                printf("%d",ans.a[i][j]);
            printf("\n");
        }
    }
    return(0);
}

