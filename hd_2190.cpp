#include <cstdio>
int f[40];
int main()
{
    f[0]=1;
    for (int i=1;i<=30;i++)
    {
        f[i]=f[i-1];
        if (i>=2)
            f[i]+=f[i-2]*2;
    }
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

