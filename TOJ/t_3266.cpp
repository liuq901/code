#include <cstdio>
int f[20];
int main()
{
    f[1]=0;
    f[2]=1;
    for (int i=3;i<=12;i++)
        f[i]=(i-1)*(f[i-2]+f[i-1]);
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

