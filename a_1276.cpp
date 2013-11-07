#include <cstdio>
const int limit=1299709;
int ans[1300000],a[1300000];
bool f[1300000];
void init()
{
    for (int i=2;i*i<=limit;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=limit;j++)
            f[i*j]=true;
    }
    for (int i=1;i<=limit;i++)
        if (!f[i])
        {
            a[++a[0]]=i;
            ans[i]=0;
        }
    for (int i=2;i<=a[0];i++)
        for (int j=a[i-1]+1;j<a[i];j++)
            ans[j]=a[i]-a[i-1];
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        printf("%d\n",ans[n]);
    }
    return(0);
}

