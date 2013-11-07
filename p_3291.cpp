#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[110],b[110];
int f[110][110];
int main()
{
    while (1)
    {
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),m=strlen(b+1);
        if (n==1 && m==1 && a[1]=='0' && b[1]=='0')
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if (a[i]==b[j])
                    f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
        int len=f[n][m],ans=1;
        if (n>m)
            swap(n,m);
        while (len*2<m)
        {
            len+=n;
            n*=2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return(0);
}

