#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1010];
int f[1010];
bool b[1010][1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        int n=strlen(a+1);
        memset(b,0,sizeof(b));
        for (int i=n;i;i--)
        {
            b[i][i]=b[i+1][i]=true;
            for (int j=i+1;j<=n;j++)
                if (a[i]==a[j] && b[i+1][j-1])
                    b[i][j]=true;
        }
        memset(f,63,sizeof(f));
        f[0]=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<i;j++)
                if (b[j+1][i])
                    f[i]=min(f[i],f[j]+1);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n]);
    }
    return(0);
}

