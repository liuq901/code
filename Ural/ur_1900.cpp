#include <cstdio>
#include <cstring>
int s[510][510],a[510][510],f[510][510],pre[510][510];
void print(int n,int m)
{
    if (m!=1)
    {
        print(pre[n][m],m-1);
        printf(" ");
    }
    printf("%d",n-1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i;j++)
        {
            scanf("%d",&a[i][i+j]);
            sum+=a[i][i+j];
        }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            s[i][j]=s[i][j-1];
            for (int k=i;k<j;k++)
                s[i][j]+=a[k][j];
        }
    memset(f,63,sizeof(f));
    f[1][0]=0;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<i;k++)
                if (f[k][j-1]+s[k][i-1]<f[i][j])
                {
                    f[i][j]=f[k][j-1]+s[k][i-1];
                    pre[i][j]=k;
                }
    int ans=-1<<30,pos;
    for (int i=m+1;i<=n;i++)
        if (sum-f[i][m]-s[i][n]>ans)
        {
            ans=sum-f[i][m]-s[i][n];
            pos=i;
        }
    printf("%d\n",ans);
    print(pos,m);
    printf("\n");
    return(0);
}

