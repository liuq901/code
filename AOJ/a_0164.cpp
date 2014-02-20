#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int a[30];
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int t=1,sum=31;
        bool flag=false;
        while (sum!=1)
        {
            printf("%d\n",sum);
            if (!flag)
                sum-=a[t];
            else
            {
                sum-=5-a[t++];
                if (t==n+1)
                    t=1;
            }
            flag=!flag;
        }
        printf("1\n0\n");
    }
    return(0);
}

