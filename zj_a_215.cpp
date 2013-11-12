#include <cstdio>
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
        for (int i=n;;i++)
            if ((i+n)*(i-n+1)/2>m)
            {
                printf("%d\n",i-n+1);
                break;
            }
    return(0);
}

