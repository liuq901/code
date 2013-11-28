#include <cstdio>
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    while (c>a)
    {
        a+=b;
        if (a>c)
            a=c;
        c-=d;
    }
    printf("%d\n",a);
    return(0);
}

