#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=i*x;
    }
    printf("%d\n",sum);
    return(0);
}

