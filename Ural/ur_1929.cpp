#include <cstdio>
bool f[1000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        f[x]=true;
        sum++;
    }
    int ans=0;
    for (int i=2;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if ((f[1] || f[i] || f[j]) && (sum-f[1]-f[i]-f[j])>=n/3-1)
                ans++;
    printf("%d\n",ans);
    return(0);
}

