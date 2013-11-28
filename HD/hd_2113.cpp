#include <cstdio>
int main()
{
    int n;
    bool first=true;
    while (scanf("%d",&n)==1)
    {
        if (!first)
            printf("\n");
        first=false;
        int ans=0;
        while (n)
        {
            int p=n%10;
            if (p%2==0)
                ans+=p;
            n/=10;
        }
        printf("%d\n",ans);
    }
    return(0);
}

