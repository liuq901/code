#include <cstdio>
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int ans=0;
        for (int i=1;i<n;i++)
            ans+=(i-1)*(n-i-1);
        printf("%d\n",ans*n/4);
    }
    return(0);
}

