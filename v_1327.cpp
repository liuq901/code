#include <cstdio>
#include <algorithm>
using namespace std;
char a[5010];
int f[5010][5010];
int main()
{
    int n;
    scanf("%d%s",&n,a+1);
    for (int i=n;i;i--)
    {
        f[i][i-1]=f[i][i]=0;
        for (int j=i+1;j<=n;j++)
        {
            f[i][j]=min(f[i+1][j]+1,f[i][j-1]+1);
            if (a[i]==a[j])
                f[i][j]=min(f[i][j],f[i+1][j-1]);
        }
    }
    printf("%d\n",f[1][n]);
    return(0);
}

