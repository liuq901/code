#include <cstdio>
#include <cstring>
typedef double matrix[210][210];
matrix ans,a,b;
int n,cnt[110];
void init(matrix a)
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            a[i][j]=0;
        a[i][i]=1;
    }
}
void calc(matrix a,int t)
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            a[i][j]=0;
        int l=i-t,r=i+t;
        if (l<=0)
            l+=n;
        if (r>n)
            r-=n;
        a[i][l]+=0.5;
        a[i][r]+=0.5;
    }
}
matrix d;
void multi(matrix a,matrix b,matrix c)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[i][j]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[1][j]+=a[1][i]*b[i][j];
    for (int i=2;i<=n;i++)
    {
        for (int j=2;j<=n;j++)
            d[i][j]=d[i-1][j-1];
        d[i][1]=d[i-1][n];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            c[i][j]=d[i][j];
}
void power(matrix one,matrix ans,int p)
{
    init(ans);
    for (;p;p>>=1)
    {
        if (p&1)
            multi(ans,one,ans);
        multi(one,one,one);
    }
}
int main()
{
    while (1)
    {
        int m,L,R;
        scanf("%d%d%d%d",&n,&m,&L,&R);
        if (n==0 && m==0 && L==0 && R==0)
            break;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        init(ans);
        for (int i=1;i<=100;i++)
        {
            calc(a,i);
            power(a,b,cnt[i]);
            multi(ans,b,ans);
        }
        double sum=0;
        for (int i=L;i<=R;i++)
            sum+=ans[1][i];
        printf("%.4f\n",sum);
    }
    return(0);
}

