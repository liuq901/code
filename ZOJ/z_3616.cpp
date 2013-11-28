#include <cstdio>
#include <algorithm>
using namespace std;
typedef int array[110][2010];
array s,b,g,left;
bool ok[110][2010];
int range(array s,int x1,int y1,int x2,int y2)
{
    return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
int main()
{
    int n,m,B,G;
    while (scanf("%d%d%d%d",&n,&m,&B,&G)==4)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
                b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
                g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
                if (y==1)
                    b[i][j]++;
                else
                    g[i][j]++;
                left[i][j]=x<0?0:left[i][j-1]+1;
            }
        int ans=-1;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
            {
                int now=1<<30;
                for (int k=j;k<=n;k++)
                {
                    if (left[k][i]==0)
                        break;
                    now=min(now,left[k][i]);
                    int x1=j,y1=i-now+1,x2=k,y2=i;
                    if (range(b,x1,y1,x2,y2)>=B && range(g,x1,y1,x2,y2)>=G)
                        ans=max(ans,range(s,x1,y1,x2,y2));
                }
            }
        if (ans==-1)
            printf("No solution!\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

