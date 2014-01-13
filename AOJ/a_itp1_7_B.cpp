#include <cstdio>
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                int k=m-i-j;
                ans+=k>j && k<=n;
            }
        printf("%d\n",ans);
    }
    return(0);
}

