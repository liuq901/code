#include <cstdio>
#include <algorithm>
using namespace std;
int id,f[110],ans[110],delta[110],b[110],a[100000][4];
bool dfs(int x)
{
    f[x]=id;
    for (int i=b[x];i;i=a[i][3])
    {
        if (ans[x]%a[i][1]!=0 || a[i][2]%ans[x]!=0)
            return(false);
        int y=a[i][0];
        if (f[y]==id)
        {
            int u=__gcd(ans[x],ans[y]),v=ans[x]/u*ans[y];
            if (u!=a[i][1] || v!=a[i][2])
                return(false);
        }
        else
        {
            ans[y]=a[i][2]/ans[x]*a[i][1];
            if (!dfs(y))
                return(false);
        }
    }
    return(true);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        delta[i]=1;
    bool flag=true;
    for (int i=1;i<=m;i++)
    {
        int x,y,z,p;
        scanf("%d%d%d%d",&x,&y,&z,&p);
        if (p%z!=0)
        {
            flag=false;
            break;
        }
        a[i][0]=y,a[i][1]=z,a[i][2]=p,a[i][3]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=p,a[i+m][3]=b[y],b[y]=i+m;
        delta[x]=max(delta[x],z);
        delta[y]=max(delta[y],z);
    }
    for (int i=1;i<=n;i++)
    {
        if (ans[i]!=0)
            continue;
        id=0;
        for (ans[i]=delta[i];ans[i]<=1000000;ans[i]+=delta[i])
        {
            id++;
            if (dfs(i))
                break;
        }
        if (ans[i]>1000000)
        {
            flag=false;
            break;
        }
    }
    if (!flag)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i=1;i<=n;i++)
            printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return(0);
}

