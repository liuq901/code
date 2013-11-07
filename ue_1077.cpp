#include <cstdio>
int main()
{
    while (1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0 && b==0)
            break;
        printf("%d\n",b/3-(a-1)/3);
    }
    return(0);
}

