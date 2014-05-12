#include <cstdio>
#include <vector>
using namespace std;
int S[100010],T[100010],q[100010],num[100010],f[100010],b[100010],a[200010][2];
bool vis[100010];
void bfs()
{
    int l,r;
    vis[1]=true;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (vis[y])
                continue;
            vis[y]=true;
            q[++r]=y;
            f[y]=x;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
    }
    for (int i=1;i<=n;i++)
        scanf("%d",&S[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&T[i]);
    bfs();
    vector <int> ans;
    for (int i=1;i<=n;i++)
    {
        int x=q[i];
        num[x]=num[f[f[x]]];
        if ((S[x]^num[x])!=T[x])
        {
            num[x]^=1;
            ans.push_back(x);
        }
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
    return(0);
}

