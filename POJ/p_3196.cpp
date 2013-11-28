#include <cstdio>
#include <cstdlib>
int main()
{
    while (1)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (a==0 && b==0 && c==0)
            break;
        if ((c-a)%b!=0)
            printf("No accounting tablet\n");
        else
        {
            int p=abs(c-a)/b;
            printf("%d\n",p/3+(p%3!=0));
        }
    }
    return(0);
}

