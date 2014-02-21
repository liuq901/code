#include <cstdio>
int f[40];
void init()
{
    f[1]=1;
    f[2]=2;
    f[3]=4;
    for (int i=4;i<=30;i++)
        f[i]=f[i-1]+f[i-2]+f[i-3];
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        printf("%d\n",((f[n]+9)/10+364)/365);
    }
    return(0);
}

