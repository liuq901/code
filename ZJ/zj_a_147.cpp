#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<n;i++)
            if (i%7!=0)
            {
                if (i!=1)
                    printf(" ");
                printf("%d",i);
            }
        printf("\n");
    }
    return(0);
}

