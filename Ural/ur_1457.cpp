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
        sum+=x;
    }
    printf("%f\n",double(sum)/n);
    return(0);
}

