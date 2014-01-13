#include <cstdio>
int main()
{
    while (1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0 && b==0)
            break;
        for (int i=1;i<=a;i++)
        {
            for (int j=1;j<=b;j++)
                printf("#");
            printf("\n");
        }
        printf("\n");
    }
    return(0);
}

