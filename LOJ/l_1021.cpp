#include <cstdio>
#include <cstring>
#include <cctype>
typedef long long ll;
ll f[66000][20];
int a[20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,K;
        scanf("%d%d",&m,&K);
        char s[20];
        scanf("%s",s);
        int n=strlen(s);
        for (int i=1;i<=n;i++)
            a[i]=isdigit(s[i-1])?s[i-1]-'0':s[i-1]-'A'+10;
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int i=0;i<1<<n;i++)
           for (int j=0;j<K;j++)
           {
               if (f[i][j]==0)
                   continue;
               for (int k=1;k<=n;k++)
               {
                   if (i>>k-1&1)
                       continue;
                   f[i|1<<k-1][(j*m+a[k])%K]+=f[i][j];
               }
           }
        static int id=0;
        printf("Case %d: %lld\n",++id,f[(1<<n)-1][0]);
    }
    return(0);
}

