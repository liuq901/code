#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int tot,b[16010],a[40010][2];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
int idx,dfn[16010],low[16010],c[16010];
stack <int> s;
bool in[16010];
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    s.push(x);
    in[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (in[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        c[0]++;
        while (1)
        {
            int y=s.top();
            s.pop();
            c[y]=c[0],in[y]=false;
            if (x==y)
                break;
        }
    }
}
bool solve(int n)
{
    memset(dfn,0,sizeof(dfn));
    idx=c[0]=0;
    for (int i=1;i<=2*n;i++)
        if (!dfn[i])
            tarjan(i);
    for (int i=1;i<=n;i++)
        if (c[i]==c[i+n])
            return(false);
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=m;i++)
        {
            char c1,c2;
            int x,y;
            scanf(" %c%d %c%d",&c1,&x,&c2,&y);
            if (c1=='+')
                x+=n;
            if (c2=='+')
                y+=n;
            add(x,y>n?y-n:y+n);
            add(y,x>n?x-n:x+n);
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (solve(n))
        {
            printf("Yes\n");
            vector <int> ans;
            for (int i=1;i<=n;i++)
                if (c[i]<c[i+n])
                    ans.push_back(i);
            printf("%d",ans.size());
            for (int i=0;i<ans.size();i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
        else
            printf("No\n");
    }
    return(0);
}

