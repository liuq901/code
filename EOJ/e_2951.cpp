#include <cstdio>
int main()
{
    unsigned a;
    int n;
    scanf("%u%d",&a,&n);
    for (int i=1;i<=n;i++)
        a=((a&1)<<31)+(a>>1);
    printf("%u\n",a);
    return(0);
}

