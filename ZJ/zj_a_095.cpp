#include <cstdio>
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
        printf("%d\n",n==m?m:m+1);
    return(0);
}

