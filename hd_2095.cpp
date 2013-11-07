#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans^=x;
        }
        printf("%d\n",ans);
    }
    return(0);
}

