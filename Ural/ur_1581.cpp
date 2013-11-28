#include <cstdio>
int a[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=-1;
    int now=a[1],sum=1;
    bool first=true;
    for (int i=2;i<=n+1;i++)
    {
        if (a[i]!=now)
        {
            if (!first)
                printf(" ");
            first=false;
            printf("%d %d",sum,now);
            now=a[i];
            sum=1;
            continue;
        }
        sum++;
    }
    printf("\n");
    return(0);
}

