#include <cstdio>
int f[50][2];
void init()
{
    const int n=43;
    f[1][1]=1;
    for (int i=2;i<=n;i++)
    {
        f[i][0]=f[i-1][0]+f[i-1][1];
        f[i][1]=f[i-1][0];
    }
    f[1][0]=1;
}
void dfs(int n,int len)
{
    if (n<=2)
    {
        for (int i=2;i<len;i++)
            printf("0");
        printf("%d\n",n-1);
        return;
    }
    for (int i=1;;i++)
    {
        if (n<=f[i][0]+f[i][1])
        {
            if (len!=1)
                for (int j=i+1;j<len;j++)
                    printf("0");
            printf("1");
            dfs(n,i);
            return;
        }
        n-=f[i][0]+f[i][1];
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        n++;
        static int id=0;
        printf("Case %d: ",++id);
        dfs(n,-1);
    }
    return(0);
}

