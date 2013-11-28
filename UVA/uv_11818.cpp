#include <cstdio>
#include <cstring>
#include <utility>
#include <map>
using namespace std;
const int edge[][4]={{0},{8,11},{9,11,12},{10,12},{3,6,8},{4,6,7,9},{5,7,10},{1,3},{1,2,4},{2,5}};
const int to[][4]={{0},{4,2},{5,1,3},{6,2},{7,5,1},{8,4,6,2},{9,5,3},{8,4},{7,9,5},{8,6}};
const int pos[][4]={{0},{1,2,1,3},{2,2,2,3},{0,2,1,2},{1,2,2,2},{2,2,3,2},{1,1,1,2},{2,1,2,2},{0,1,1,1},{1,1,2,1},{2,1,3,1},{1,0,1,1},{2,0,2,1}};
map <pair <pair <int,int>,pair <int,int> >,int> M;
void init()
{
    for (int i=1;i<=12;i++)
    {
        pair <int,int> s1(pos[i][0],pos[i][1]),s2(pos[i][2],pos[i][3]);
        M[make_pair(s1,s2)]=i;
        M[make_pair(s2,s1)]=i;
    }
}
int hash(int x1,int y1,int x2,int y2)
{
    pair <int,int> s1(x1,y1),s2(x2,y2);
    return(M[make_pair(s1,s2)]);
}
bool vis[10];
void dfs(int x,int state)
{
    vis[x]=true;
    for (int i=0;i<4;i++)
    {
        if (edge[x][i]==0 || state>>edge[x][i]-1&1)
            continue;
        int y=to[x][i];
        if (!vis[y])
            dfs(y,state);
    }
}
bool check(int S,int T,int state)
{
    memset(vis,0,sizeof(vis));
    dfs(S,state);
    return(vis[T]);
}
int f[10][10][4100];
bool dp(int S,int T,int state)
{
    if (f[S][T][state]!=-1)
        return(f[S][T][state]);
    int &ret=f[S][T][state];
    ret=false;
    for (int i=1;i<=12;i++)
        if (state>>i-1&1)
        {
            int now=state^1<<i-1;
            if (check(S,T,now) || !dp(S,T,now))
            {
                ret=true;
                break;
            }
        }
    return(ret);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    memset(f,-1,sizeof(f));
    while (T--)
    {
        int S,T,n;
        scanf("%d%d%d",&S,&T,&n);
        int state=(1<<12)-1;
        for (int i=1;i<=n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int id=hash(x1,y1,x2,y2);
            state^=1<<id-1;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (check(S,T,state))
            printf("No Cheese!\n");
        else
            printf("%s\n",dp(S,T,state)?"SOHA":"TARA");
    }
    return(0);
}

