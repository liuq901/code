#include <cstdio>
#include <algorithm>
using namespace std;
int m,tot,v[20],a[20000];
bool dfs(int dep,int limit,int now,bool first)
{
    if (dep==limit+1)
    {
        if (!first)
            return(binary_search(a+1,a+tot+1,m-now));
        a[++tot]=now;
        return(false);
    }
    for (int i=0;i<=2;i++)
        if (dfs(dep+1,limit,now+v[dep]*i,first))
            return(true);
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        tot=0;
        dfs(1,n/2,0,true);
        sort(a+1,a+tot+1);
        static int id=0;
        printf("Case %d: %s\n",++id,dfs(n/2+1,n,0,false)?"Yes":"No");
    }
    return(0);
}

