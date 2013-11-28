#include <cstdio>
#include <vector>
using namespace std;
int n,ans,p[110],a[110][110];
vector <int> b;
void dfs(int dep)
{
    if (b.size()>1)
    {
        int now=0;
        for (int i=0;i<b.size();i++)
        {
            int x=b[i];
            p[x]=1<<30;
            for (int j=0;j<b.size();j++)
            {
                int y=b[j];
                if (x==y)
                    continue;
                if (a[x][y]<p[x])
                    p[x]=a[x][y];
            }
            now+=p[x];
        }
        ans=max(ans,now);
    }
    for (int i=dep;i<=n;i++)
    {
        bool flag=true;
        for (int j=0;j<b.size();j++)
        {
            int x=b[j];
            if (a[i][x]==0)
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            b.push_back(i);
            dfs(i+1);
            b.pop_back();
        }
    }
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
    }
    for (int i=1;i<=n;i++)
    {
        b.push_back(i);
        dfs(i+1);
        b.pop_back();
    }
    printf("%d\n",ans);
    return(0);
}

