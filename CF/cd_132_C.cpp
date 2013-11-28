#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[]={1,-1};
int f[110][60][2],g[110][60][2];
char op[110];
int main()
{
    int m;
    scanf("%s%d",op+1,&m);
    int n=strlen(op+1);
    memset(f,-63,sizeof(f));
    memset(g,63,sizeof(g));
    int inf=g[0][0][0];
    f[0][0][0]=g[0][0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            for (int k=0;k<2;k++)
            {
                int V=max(f[i-1][j][k],g[i-1][j][k]),v=min(f[i-1][j][k],g[i-1][j][k]);
                if (V==inf)
                    continue;
                if (op[i]=='T')
                {
                    for (int l=0;l<=m-j;l+=2)
                    {
                        f[i][j+l][1-k]=max(f[i][j+l][1-k],V);
                        g[i][j+l][1-k]=min(g[i][j+l][1-k],v);
                    }
                    for (int l=1;l<=m-j;l+=2)
                    {
                        f[i][j+l][k]=max(f[i][j+l][k],V+c[k]);
                        g[i][j+l][k]=min(g[i][j+l][k],v+c[k]);
                    }
                }
                else
                {
                    for (int l=0;l<=m-j;l+=2)
                    {
                        f[i][j+l][k]=max(f[i][j+l][k],V+c[k]);
                        g[i][j+l][k]=min(g[i][j+l][k],v+c[k]);
                    }
                    for (int l=1;l<=m-j;l+=2)
                    {
                        f[i][j+l][1-k]=max(f[i][j+l][1-k],V);
                        g[i][j+l][1-k]=min(g[i][j+l][1-k],v);
                    }
                }
            }
    int ans=0;
    for (int i=0;i<2;i++)
    {
        if (f[n][m][i]>0)
            ans=max(ans,f[n][m][i]);
        if (g[n][m][i]<0)
            ans=max(ans,-g[n][m][i]);
    }
    printf("%d\n",ans);
    return(0);
}

