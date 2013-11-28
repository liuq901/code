#include <cstdio>
int main()
{
    int last=1,ma=-1,ans,mi,n;
    scanf("%d%d",&n,&mi);
    for (int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x<mi)
        {
            mi=x;
            if (i-last+(last==1?0:1)>ma)
            {
                ma=i-last+(last==1?0:1);
                ans=last;
            }
            last=i;
        }
    }
    if (n-last+(last==1?0:1)>ma)
        ans=last;
    printf("%d\n",ans);
    return(0);
}

