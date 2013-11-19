#include <cstdio>
#include <cstring>
typedef int matrix[50][50];
int S[50];
matrix zero,one,a;
void multiply(matrix a,matrix b,matrix c,int n,int m)
{
    matrix d={0};
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
                d[i][j]=(d[i][j]+a[i][k]*b[k][j])%m;
    memcpy(c,d,sizeof(d));
}
void power(int T,int n,int m)
{
    memcpy(a,zero,sizeof(zero));
    for (;T;T>>=1)
    {
        if (T&1)
            multiply(a,one,a,n,m);
        multiply(one,one,one,n,m);
    }
}
int main()
{
    for (int i=0;i<50;i++)
        zero[i][i]=1;
    while (1)
    {
        int n,m,A,B,C,T;
        scanf("%d%d%d%d%d%d",&n,&m,&A,&B,&C,&T);
        if (n==0 && m==0 && A==0 && B==0 && C==0 && T==0)
            break;
        for (int i=0;i<n;i++)
            scanf("%d",&S[i]);
        memset(one,0,sizeof(one));
        for (int i=0;i<n;i++)
        {
            if (i>0)
                one[i][i-1]=A;
            one[i][i]=B;
            if (i<n-1)
                one[i][i+1]=C;
        }
        power(T,n,m);
        for (int i=0;i<n;i++)
        {
            int sum=0;
            for (int j=0;j<n;j++)
                sum=(sum+a[i][j]*S[j])%m;
            printf("%d%c",sum,i==n-1?'\n':' ');
        }
    }
    return(0);
}

