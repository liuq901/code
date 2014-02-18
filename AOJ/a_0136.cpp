#include <cstdio>
const double a[]={0,165,170,175,180,185,1e100};
int ans[10];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        double x;
        scanf("%lf",&x);
        for (int j=1;j<=6;j++)
            if (x<a[j])
            {
                ans[j]++;
                break;
            }
    }
    for (int i=1;i<=6;i++)
    {
        printf("%d:",i);
        for (int j=1;j<=ans[i];j++)
            printf("*");
        printf("\n");
    }
    return(0);
}

