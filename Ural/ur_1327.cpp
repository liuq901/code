#include <cstdio>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int n=0;
    for (int i=a;i<=b;i++)
        n+=i&1;
    printf("%d\n",n);
    return(0);
}

