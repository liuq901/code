#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1010],b[1010];
int f[1010][1010];
int main()
{
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    for (int i=1;i<=n;i++)
        f[i][0]=i;
    for (int i=1;i<=m;i++)
        f[0][i]=i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            f[i][j]=min(min(f[i-1][j],f[i][j-1])+1,f[i-1][j-1]+(a[i]!=b[j]));
    printf("%d\n",f[n][m]);
    return(0);
}

