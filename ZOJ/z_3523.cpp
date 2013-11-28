#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string a[60],b[60];
char buf[100];
int f[60][60];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        int ans=0;
        gets(buf);
        for (int T=1;T<=n;T++)
        {
            for (int i=1;i<=m;i++)
            {
                gets(buf);
                a[i]=b[i]=buf;
            }
            sort(b+1,b+m+1);
            for (int i=0;i<=m;i++)
                f[i][0]=f[0][i]=0;
            for (int i=1;i<=m;i++)
                for (int j=1;j<=m;j++)
                {
                    f[i][j]=max(f[i-1][j],f[i][j-1]);
                    if (a[i]==b[j])
                        f[i][j]=max(f[i][j],f[i-1][j-1]+1);
                }
            ans+=m-f[m][m];
        }
        printf("%d\n",ans);
    }
    return(0);
}

