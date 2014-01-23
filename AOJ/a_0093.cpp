#include <cstdio>
bool leap(int x)
{
    if (x%400==0)
        return(true);
    if (x%100==0)
        return(false);
    return(x%4==0);
}
int main()
{
    bool first=true;
    while (1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0 && b==0)
            break;
        if (!first)
            printf("\n");
        first=false;
        bool flag=false;
        for (int i=a;i<=b;i++)
            if (leap(i))
            {
                printf("%d\n",i);
                flag=true;
            }
        if (!flag)
            printf("NA\n");
    }
    return(0);
}

