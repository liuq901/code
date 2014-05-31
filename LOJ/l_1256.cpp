#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector <string> s[26][26];
vector <int> ans;
char buf[30];
int in[26],out[26],a[26][26];
bool vis[26];
void go(int x)
{
    vis[x]=true;
    for (int i=0;i<26;i++)
        if (a[x][i] && !vis[i])
            go(i);
}
int solve()
{
    int c1,c2;
    c1=c2=0;
    for (int i=0;i<26;i++)
    {
        if (in[i]==out[i])
            continue;
        if (in[i]+1==out[i])
            c1++;
        else if (in[i]==out[i]+1)
            c2++;
        else
            return(-1);
    }
    if ((c1!=0 || c2!=0) && (c1!=1 || c2!=1))
        return(-1);
    int start;
    for (int i=0;i<26;i++)
    {
        if (in[i]+1==out[i])
        {
            start=i;
            break;
        }
        if (in[i]>0)
            start=i;
    }
    memset(vis,0,sizeof(vis));
    go(start);
    for (int i=0;i<26;i++)
        if (in[i]+out[i] && !vis[i])
            return(-1);
    return(start);
}
void dfs(int x)
{
    for (int i=0;i<26;i++)
        if (a[x][i])
        {
            a[x][i]--;
            dfs(i);
        }
    ans.push_back(x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(a,0,sizeof(a));
        for (int i=0;i<26;i++)
            for (int j=0;j<26;j++)
                s[i][j].clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            int x=buf[0]-'a';
            int y=buf[strlen(buf)-1]-'a';
            s[x][y].push_back(buf);
            out[x]++;
            in[y]++;
            a[x][y]++;
        }
        static int id=0;
        printf("Case %d: ",++id);
        int tmp=solve();
        if (tmp==-1)
            printf("No\n");
        else
        {
            printf("Yes\n");
            ans.clear();
            dfs(tmp);
            reverse(ans.begin(),ans.end());
            for (int i=1;i<ans.size();i++)
            {
                printf("%s%c",s[ans[i-1]][ans[i]].back().c_str(),i+1==ans.size()?'\n':' ');
                s[ans[i-1]][ans[i]].pop_back();
            }
        }
    }
    return(0);
}

