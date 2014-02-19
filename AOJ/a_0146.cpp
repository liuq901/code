#include <cstdio>
#include <cstdlib>
double f[32770][20];
int a[20],b[20],c[20],s[32770],pre[32770][20];
void print(int x,int y)
{
    if (pre[x][y]!=0)
    {
        print(x^1<<y-1,pre[x][y]);
        printf(" ");
    }
    printf("%d",a[y]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for (int i=0;i<1<<n;i++)
        for (int j=1;j<=n;j++)
        {
            f[i][j]=1e100;
            if (i>>j-1&1)
                s[i]+=c[j]*20;
        }
    for (int i=1;i<=n;i++)
        f[1<<i-1][i]=0;
    for (int i=0;i<1<<n;i++)
        for (int j=1;j<=n;j++)
        {
            if (f[i][j]==1e100)
                continue;
            for (int k=1;k<=n;k++)
            {
                if (i>>k-1&1)
                    continue;
                double now=f[i][j]+abs(b[j]-b[k])/2000.0*(70+s[i]);
                if (now<f[i|1<<k-1][k])
                {
                    f[i|1<<k-1][k]=now;
                    pre[i|1<<k-1][k]=j;
                }
            }
        }
    double mi=1e100;
    int t=0;
    for (int i=1;i<=n;i++)
        if (f[(1<<n)-1][i]<mi)
        {
            mi=f[(1<<n)-1][i];
            t=i;
        }
    print((1<<n)-1,t);
    printf("\n");
    return(0);
}

