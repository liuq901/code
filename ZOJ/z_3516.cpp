#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> f[10010];
int v[10010],b[10010],a[10010][2];
void dfs(int x)
{
    f[x].clear();
    f[x].push_back(v[x]);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        dfs(y);
        for (int j=0;j<f[y].size();j++)
            f[x].push_back(f[y][j]);
    }
    sort(f[x].begin(),f[x].end());
    reverse(f[x].begin(),f[x].end());
    if (f[x].size()>3)
        f[x].resize(3);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        scanf("%d",&v[1]);
        memset(b,0,sizeof(b));
        for (int i=2;i<=n;i++)
        {
            int x;
            scanf("%d%d",&x,&v[i]);
            x++;
            a[i][0]=i,a[i][1]=b[x],b[x]=i;
        }
        dfs(1);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            x++;
            if (f[x].size()<3)
                printf("-1\n");
            else
                printf("%d %d %d\n",f[x][0],f[x][1],f[x][2]);
        }
    }
    return(0);
}

