#include <cstdio>
int f[1010];
int main()
{
    f[0]=f[1]=1;
    for (int i=2;i<=1000;i++)
        for (int j=0;j<=i;j++)
            if (i%2==j%2)
                f[i]+=f[(i-j)/2];
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        static int id=0;
        printf("%d %d\n",++id,f[n]);
    }
    return(0);
}

