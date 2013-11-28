#include <cstdio>
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        bool first=true;
        for (int i=0;i<=12;i++)
            if (n>>i&1)
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",1<<i);
            }
        printf("\n");
    }
    return(0);
}

