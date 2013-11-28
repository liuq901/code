#include <cstdio>
#include <cstring>
bool a[110][110];
int n,color[110];
bool dfs(int x,int now)
{
    if (color[x]!=-1)
        return(color[x]==now);
    color[x]=now;
    for (int i=1;i<=n;i++)
    {
        if (!a[x][i])
            continue;
        if (!dfs(i,now^1))
            return(false);
    }
    return(true);
}
int main()
{
    while (scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            while (1)
            {
                int x;
                scanf("%d",&x);
                if (x==0)
                    break;
                if (x==i)
                    continue;
                a[i][x]=true;
            }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                bool flag=!a[i][j] || !a[j][i];
                a[i][j]=a[j][i]=flag;
            }
        memset(color,-1,sizeof(color));
        bool flag=true;
        for (int i=1;i<=n;i++)
            if (color[i]==-1 && !dfs(i,0))
            {
                flag=false;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

