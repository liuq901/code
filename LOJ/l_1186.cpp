#include <cstdio>
int a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans^=x-a[i]-1;
        }
        static int id=0;
        printf("Case %d: %s wins\n",++id,ans?"white":"black");
    }
    return(0);
}

