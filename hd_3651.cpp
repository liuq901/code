#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char a[110];
int f[110][20][20];
int main()
{
    while (scanf("%s",a+1)==1)
    {
        int n=strlen(a+1);
        memset(f,63,sizeof(f));
        f[0][5][6]=0;
        for (int i=1;i<=n;i++)
        {
            int x=a[i]-'0';
            if (x==0)
                x=10;
            for (int j=1;j<=10;j++)
                for (int k=j+1;k<=10;k++)
                    for (int p=1;p<=10;p++)
                    {
                        if (x<p)
                            f[i][x][p]=min(f[i][x][p],f[i-1][j][k]+max(abs(j-x)+1,abs(k-p)));
                        if (x>p)
                            f[i][p][x]=min(f[i][p][x],f[i-1][j][k]+max(abs(j-p),abs(k-x)+1));
                    }
        }
        int ans=1<<30;
        for (int i=1;i<=10;i++)
            for (int j=i+1;j<=10;j++)
                ans=min(ans,f[n][i][j]);
        printf("%d\n",ans);
    }
    return(0);
}

