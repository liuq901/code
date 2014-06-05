#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int idx,tot,b[10010],dfn[10010],low[10010],a[40010][2];
bool cut[10010];
vector <int> block[10010];
stack <int> s;
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    s.push(x);
    int son=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            son++;
            if (low[y]>=dfn[x])
            {
                if (x!=1)
                    cut[x]=true;
                block[++tot].clear();
                while (1)
                {
                    int z=s.top();
                    s.pop();
                    block[tot].push_back(z);
                    if (z==y)
                        break;
                }
                block[tot].push_back(x);
            }
            low[x]=min(low[x],low[y]);
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (x==1 && son>1)
        cut[x]=true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(dfn,0,sizeof(dfn));
        memset(cut,0,sizeof(cut));
        idx=tot=0;
        tarjan(1);
        static int id=0;
        printf("Case %d: ",++id);
        if (tot==1)
            printf("2 %d\n",n*(n-1)/2);
        else
        {
            ull ans=1;
            int cnt=0;
            for (int i=1;i<=tot;i++)
            {
                int sum=0;
                for (int j=0;j<block[i].size();j++)
                    sum+=cut[block[i][j]];
                if (sum==1)
                    cnt++,ans*=block[i].size()-1;
            }
            printf("%d %llu\n",cnt,ans);
        }
    }
    return(0);
}

