#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int a[10]={0};
        for (int i=1;i<=n;i++)
        {
            int x=i;
            while (x)
            {
                a[x%10]++;
                x/=10;
            }
        }
        for (int i=0;i<10;i++)
            printf("%d%c",a[i],i==9?'\n':' ');
    }
    return(0);
}

