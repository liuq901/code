#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    if (n&1)
        n--;
    printf("%d\n",(1+n/2)*(n/2)/2);
    for (int i=1;i<=n/2;i++)
        for (int j=n;j>=n-i+1;j--)
            printf("%d %d\n",i,j);
    return(0);
}

