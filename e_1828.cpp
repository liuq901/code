#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==-1)
            break;
        printf("%02d:%02d:%02d\n",n/3600,n%3600/60,n%60);
    }
    return(0);
}

