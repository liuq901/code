#include <cstdio>
int main()
{
    while (1)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if (n==0 && k==0)
            break;
        printf("%s\n",(n-1)%(k+1)==0?"Jiang":"Tang");
    }
    return(0);
}

