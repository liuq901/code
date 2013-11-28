#include <cstdio>
int a[200010],ans[200010];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for (int i=1;i<=n;i++)
        if (a[i]*n==sum)
            ans[++ans[0]]=i;
    printf("%d\n",ans[0]);
    for (int i=1;i<=ans[0];i++)
        printf("%d%c",ans[i],i==ans[0]?'\n':' ');
    return(0);
}

