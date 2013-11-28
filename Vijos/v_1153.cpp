#include <cstdio>
bool f[210][8010];
int a[210];
int main()
{
    int n,m=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        m+=a[i];
    }
    f[0][0]=true;
    for (int i=1;i<=n;i++)
        for (int j=i-1;j>=0;j--)
            for (int k=a[i];k<=m;k++)
                if (f[j][k-a[i]])
                    f[j+1][k]=true;
    int ans;
    for (int i=0;i<=m/2;i++)
        if (f[n/2][i])
            ans=i;
    printf("%d %d\n",ans,m-ans);
    return(0);
}

