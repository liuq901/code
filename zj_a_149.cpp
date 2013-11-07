#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int ans=1;
        if (n==0)
            ans=0;
        while (n)
        {
            ans*=n%10;
            n/=10;
        }
        printf("%d\n",ans);
    }
    return(0);
}

