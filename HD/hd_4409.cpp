#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
char buf[10000];
int dep[30010],pre[30010],fa[30010][16];
string name[30010];
vector <int> son[30010];
map <string,int> M;
inline bool cmp(int x,int y)
{
    return(name[x]<name[y]);
}
void dfs(int x)
{
    for (int i=0;i<son[x].size();i++)
    {
        int y=son[x][i];
        dep[y]=dep[x]+1;
        dfs(y);
    }
}
void print(int x)
{
    for (int i=1;i<=dep[x];i++)
        printf(".");
    printf("%s\n",name[x].c_str());
    for (int i=0;i<son[x].size();i++)
        print(son[x][i]);
}
int LCA(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    for (int i=15;i>=0;i--)
        if (dep[x]-dep[y]>=1<<i)
            x=fa[x][i];
    if (x==y)
        return(x);
    for (int i=15;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return(fa[x][0]);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        M.clear();
        for (int i=1;i<=n;i++)
        {
            son[i].clear();
            scanf("%s",buf);
            string s=buf;
            int pos;
            for (int j=0;j<s.size();j++)
                if (s[j]!='.')
                {
                    pos=j;
                    break;
                }
            s=s.substr(pos);
            pre[pos]=i;
            if (pos>0)
            {
                fa[i][0]=pre[pos-1];
                son[fa[i][0]].push_back(i);
            }
            name[i]=s;
            M[s]=i;
        }
        for (int i=1;i<=n;i++)
            sort(son[i].begin(),son[i].end(),cmp);
        dfs(1);
        for (int i=2;i<=n;i++)
            for (int j=1;j<16;j++)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%s",buf);
            if (buf[0]=='L')
                print(1);
            else if (buf[0]=='b')
            {
                scanf("%s",buf);
                int id=M[buf];
                printf("%d\n",id==1?1:son[fa[id][0]].size());
            }
            else
            {
                scanf("%s",buf);
                int x=M[buf];
                scanf("%s",buf);
                int y=M[buf];
                int t=LCA(x,y);
                if (t==x || t==y)
                    t=fa[t][0];
                printf("%s\n",name[t].c_str());
            }
        }
    }
    return(0);
}

