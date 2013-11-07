#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N=110;
int n,ans,len[N],mc[N],list[N][N];
bool found,g[N][N];
vector <int> now,best;
void dfs(int size)
{
    if (len[size]==0)
    {
        if (size>ans)
            ans=size,found=true,best=now;
        return;
    }
    for (int k=0;k<len[size] && !found;k++)
    {
        int i=list[size][k];
        if (size+len[size]-k<=ans || size+mc[i]<=ans)
            break;
        len[size+1]=0;
        for (int j=k+1;j<len[size];j++)
            if (g[i][list[size][j]])
                list[size+1][len[size+1]++]=list[size][j];
        now.push_back(i);
        dfs(size+1);
        now.pop_back();
    }
}
void work()
{
    mc[n]=ans=1;
    for (int i=n-1;i;i--)
    {
        found=false;
        len[1]=0;
        for (int j=i+1;j<=n;j++)
            if (g[i][j])
                list[1][len[1]++]=j;
        now.push_back(i);
        dfs(1);
        now.pop_back();
        mc[i]=ans;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        memset(g,true,sizeof(g));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            g[x][y]=g[y][x]=false;
        }
        work();
        printf("%d\n",ans);
        for (int i=0;i<best.size();i++)
            printf("%d%c",best[i],i==best.size()-1?'\n':' ');
    }
    return(0);
}

