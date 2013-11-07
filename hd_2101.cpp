#include <cstdio>
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)==2)
        printf("%s\n",(a+b)%86?"no":"yes");
    return(0);
}

