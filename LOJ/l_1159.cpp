#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[60],b[60],c[60];
int f[60][60][60];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s%s",a+1,b+1,c+1);
        int n=strlen(a+1),m=strlen(b+1),K=strlen(c+1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=1;k<=K;k++)
                    if (a[i]==b[j] && a[i]==c[k])
                        f[i][j][k]=f[i-1][j-1][k-1]+1;
                    else
                        f[i][j][k]=max(max(f[i-1][j][k],f[i][j-1][k]),f[i][j][k-1]);
        static int id=0;
        printf("Case %d: %d\n",++id,f[n][m][K]);
    }
    return(0);
}

