#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[30010],dep[30010],a[60010][3];
void dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dep[y]=dep[x]+a[i][1];
        dfs(y,x);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        dep[1]=0;
        dfs(1,0);
        int k=max_element(dep+1,dep+n+1)-dep;
        dep[k]=0;
        dfs(k,0);
        static int id=0;
        printf("Case %d: %d\n",++id,*max_element(dep+1,dep+n+1));
    }
    return(0);
}

