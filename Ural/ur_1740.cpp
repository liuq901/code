#include <cstdio>
int main()
{
    int l,k,h;
    scanf("%d%d%d",&l,&k,&h);
    int a=l/k,b=(l+k-1)/k;
    printf("%d %d\n",a*h,b*h);
    return(0);
}

