#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N=1010;
bool ok[N],hostile[N][N];
vector <int> edge[N];
int len,n,cnt,pop,ans,top,order[N],low[N],in_seq[N],stack[N],list[N],color[N];
bool Draw(int v,int cc)
{
    color[v]=cc;
    for (int i=0;i<edge[v].size();i++)
    {
        int succ=edge[v][i];
        if (in_seq[succ]!=cnt)
            continue;
        if (color[succ]==cc || color[succ]==-1 && Draw(succ,1-cc))
            return(true);
    }
    return(false);
}
void Check()
{
    for (int i=0;i<len;i++)
        color[list[i]]=-1;
    if (Draw(list[0],0))
        for (int i=0;i<len;i++)
            ok[list[i]]=true;
}
void DFS(int v)
{
    stack[++top]=v;
    order[v]=low[v]=pop++;
    for (int i=0;i<edge[v].size();i++)
    {
        int succ=edge[v][i];
        if (order[succ]==-1)
        {
            DFS(succ);
            if (low[succ]>=order[v])
            {
                cnt++;
                len=0;
                do
                {
                    in_seq[stack[top]]=cnt;
                    list[len++]=stack[top];
                    top--;
                }while(stack[top+1]!=succ);
                in_seq[v]=cnt;
                list[len++]=v;
                Check();
            }
            low[v]=min(low[v],low[succ]);
        }
        else
            low[v]=min(low[v],order[succ]);
    }
}
void Work()
{
    cnt=pop=ans=0;
    for (int i=0;i<n;i++)
    {
        order[i]=in_seq[i]=-1;
        ok[i]=false;
    }
    for (int i=0;i<n;i++)
        if (order[i]==-1)
        {
            top=-1;
            DFS(i);
        }
    for (int i=0;i<n;i++)
        ans+=!ok[i];
    printf("%d\n",ans);
}
int main()
{
    while (1)
    {
        int m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(hostile,0,sizeof(hostile));
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            hostile[x][y]=hostile[y][x]=true;
        }
        for (int i=0;i<n;i++)
        {
            edge[i].clear();
            for (int j=0;j<n;j++)
                if (i!=j && !hostile[i][j])
                    edge[i].push_back(j);
        }
        Work();
    }
    return(0);
}

