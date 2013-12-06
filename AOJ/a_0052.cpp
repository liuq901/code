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
        while (n)
            ans+=n/=5;
        printf("%d\n",ans);
    }
    return(0);
}

