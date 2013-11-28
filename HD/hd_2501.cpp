#include <cstdio>
int f[40];
int main()
{
    f[0]=f[1]=1;
    for (int i=2;i<=30;i++)
        f[i]=f[i-1]+f[i-2]*2;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
    return(0);
}

