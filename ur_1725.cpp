#include <cstdio>
int main()
{
    int k,n;
    scanf("%d%d",&n,&k);
    if (n==2)
        printf("0\n");
    else
    {
        if (k>n/2)
            k=n-k+1;
        printf("%d\n",n-k-2);
    }
    return(0);
}

