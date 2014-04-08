#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[110];
int f[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        int n=strlen(a+1);
        for (int i=n;i;i--)
            for (int j=i+1;j<=n;j++)
            {
                f[i][j]=min(f[i+1][j],f[i][j-1])+1;
                if (a[i]==a[j])
                    f[i][j]=min(f[i][j],f[i+1][j-1]);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[1][n]);
    }
    return(0);
}

