#include <cstdio>
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int ans=n%39;
        if (ans==0)
            ans=39;
        printf("3C%02d\n",ans);
    }
    return(0);
}

