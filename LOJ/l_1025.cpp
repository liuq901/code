#include <cstdio>
#include <cstring>
typedef long long ll;
ll f[70][70];
char a[70];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        int n=strlen(a+1);
        memset(f,0,sizeof(f));
        for (int i=n;i;i--)
        {
            f[i][i]=1;
            for (int j=i+1;j<=n;j++)
            {
                f[i][j]=f[i+1][j]+f[i][j-1];
                if (a[i]!=a[j])
                    f[i][j]-=f[i+1][j-1];
                else
                    f[i][j]++;
            }
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,f[1][n]);
    }
    return(0);
}

