#include <cstdio>
#include <cstring>
int f[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,S,T,m;
        scanf("%d%d%d%d",&n,&S,&m,&T);
        memset(f,0,sizeof(f));
        f[0][S]=1;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
            {
                if (j>1)
                    f[i][j]+=f[i-1][j-1];
                if (j<n)
                    f[i][j]+=f[i-1][j+1];
            }
        printf("%d\n",f[m][T]);
    }
    return(0);
}

