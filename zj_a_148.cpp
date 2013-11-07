#include <cstdio>
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
        }
        printf("%s\n",sum>59*n?"no":"yes");
    }
    return(0);
}

