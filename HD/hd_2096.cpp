#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(a%100+b%100)%100);
    }
    return(0);
}

