#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
        if (n%i==0)
        {
            printf("%d\n",n/i);
            break;
        }
    return(0);
}

