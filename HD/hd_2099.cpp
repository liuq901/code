#include <cstdio>
int main()
{
    while (1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0 && b==0)
            break;
        bool first=true;
        for (int i=0;i<=99;i++)
            if ((a*100+i)%b==0)
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%02d",i);
            }
        printf("\n");
    }
    return(0);
}

