#include <cstdio>
const int c[30]={0,4,4,4,4,4,4,4,4,4,15,4};
int main()
{
    int n;
    scanf("%d",&n);
    if (n<10)
        n=10;
    printf("%d\n",c[n-10]);
    return(0);
}

