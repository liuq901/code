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
        while (n!=1)
        {
            n=n&1?3*n+1:n>>1;
            ans++;
        }
        printf("%d\n",ans);
    }
    return(0);
}

