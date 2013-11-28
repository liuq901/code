#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,N,ans,pos[10],who[10],a[10][10][10];
vector <int> b[10][15];
bool D[100],d[100],Vis[4][4][4],vis[4][4][4];
int getall(int x)
{
    int tot=0;
    for (int i=1;i<=m;i++)
    {
        b[x][++tot].clear();
        for (int j=1;j<=m;j++)
            b[x][tot].push_back(a[x][i][j]);
    }
    for (int i=1;i<=m;i++)
    {
        b[x][++tot].clear();
        for (int j=1;j<=m;j++)
            b[x][tot].push_back(a[x][j][i]);
    }
    b[x][++tot].clear();
    for (int i=1;i<=m;i++)
        b[x][tot].push_back(a[x][i][i]);
    b[x][++tot].clear();
    for (int i=1;i<=m;i++)
        b[x][tot].push_back(a[x][i][m-i+1]);
}
bool bingo(int x)
{
    for (int i=1;i<=m;i++)
    {
        int s1=0,s2=0;
        for (int j=1;j<=m;j++)
        {
            s1+=vis[x-1][i-1][j-1];
            s2+=vis[x-1][j-1][i-1];
        }
        if (s1==m || s2==m)
            return(true);
    }
    int s1=0,s2=0;
    for (int i=1;i<=m;i++)
    {
        s1+=vis[x-1][i-1][i-1];
        s2+=vis[x-1][i-1][m-i];
    }
    return(s1==m || s2==m);
}
void fill(int num)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=m;k++)
                if (a[i][j][k]==num)
                    vis[i-1][j-1][k-1]=true;
}
void work()
{
    int cnt=0;
    memset(D,0,sizeof(D));
    memset(Vis,0,sizeof(Vis));
    for (int i=1;i<=pos[n];i++)
    {
        vector <int> c;
        for (int j=1;j<=n;j++)
            if (pos[j]==i)
                c.insert(c.end(),b[j][who[j]].begin(),b[j][who[j]].end());
        sort(c.begin(),c.end());
        c.erase(unique(c.begin(),c.end()),c.end());
        bool ok=false;
        for (int j=0;j<c.size();j++)
        {
            memcpy(d,D,sizeof(D));
            memcpy(vis,Vis,sizeof(Vis));
            if (d[c[j]])
                continue;
            int now=0;
            bool flag=true;
            for (int k=0;k<c.size();k++)
            {
                if (c[j]==c[k])
                    continue;
                int x=c[k];
                if (!d[x])
                {
                    d[x]=true;
                    now++;
                    fill(x);
                    for (int k=1;k<=n;k++)
                        if (pos[k]>=i && bingo(k))
                        {
                            flag=false;
                            goto out;
                        }
                }
            }
            d[c[j]]=true;
            now++;
            fill(c[j]);
            for (int k=1;k<=n;k++)
                if (pos[k]==i && !bingo(k) || pos[k]>i && bingo(k))
                    flag=false;
out:
            if (flag)
            {
                ok=true;
                cnt+=now;
                memcpy(D,d,sizeof(d));
                memcpy(Vis,vis,sizeof(vis));
                break;
            }
        }
        if (cnt>=ans)
            ok=false;
        if (!ok)
            return;
    }
    ans=min(ans,cnt);
}
int part[110];
void dfs(int dep)
{
    if (dep==n+1)
    {
        work();
        return;
    }
    for (int i=1;i<=N;i++)
    {
        who[dep]=i;
        int ma=0;
        for (int j=0;j<b[dep][who[dep]].size();j++)
            ma=max(ma,++part[b[dep][who[dep]][j]]);
        if (dep>1)
        {
            pos[dep]=pos[dep-1];
            int cnt=0;
            for (int i=1;i<dep;i++)
                if (pos[i]==pos[dep])
                    cnt++;
            if (ma>=cnt)
                dfs(dep+1);
        }
        pos[dep]=pos[dep-1]+1;
        dfs(dep+1);
        for (int j=0;j<b[dep][who[dep]].size();j++)
            part[b[dep][who[dep]][j]]--;
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=1;k<=m;k++)
                    scanf("%d",&a[i][j][k]);
        for (int i=1;i<=n;i++)
            getall(i);
        N=m+1<<1;
        ans=1<<30;
        dfs(1);
        if (ans==1<<30)
            printf("0\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

