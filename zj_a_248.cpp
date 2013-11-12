#include <cstdio>
int main()
{
    int a,b,n;
    while (scanf("%d%d%d",&a,&b,&n)==3)
    {
        printf("%d.",a/b);
        a%=b;
        for (int i=1;i<=n;i++)
        {
            printf("%d",a*10/b);
            a=a*10%b;
        }
        printf("\n");
    }
    return(0);
}

