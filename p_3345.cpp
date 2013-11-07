#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <sstream>
using namespace std;
const int N=210;
int n,s[N],a[N],l[N],r[N],p[N],f[N][N];
bool vis[N];
char buf[100000];
map <string,int> M;
int hash(const string &s)
{
    if (!M.count(s))
    {
        int id=M.size()+1;
        M[s]=id;
    }
    return(M[s]);
}
void dp(int x)
{
    if (x==0)
        return;
    dp(l[x]);
    dp(r[x]);
    int size=s[l[x]]+1;
    s[x]=s[l[x]]+s[r[x]]+1;
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=i;j++)
            f[x][i]=min(f[x][i],f[l[x]][j]+f[r[x]][i-j]);
        if (i>=size)
            f[x][i]=min(f[x][i],a[x]+f[r[x]][i-size]);
    }
}
int main()
{
    int m;
    while (scanf("%d%d",&n,&m)==2)
    {
        M.clear();
        memset(vis,0,sizeof(vis));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            int x=hash(buf);
            scanf("%d",&a[x]);
            gets(buf);
            stringstream sin(buf);
            int K=0;
            string name;
            while (sin>>name)
            {
                int y=hash(name);
                p[++K]=y;
                vis[y]=true;
            }
            if (K>0)
            {
                l[x]=p[1];
                for (int i=1;i<K;i++)
                    r[p[i]]=p[i+1];
            }
        }
        int root=0,now;
        for (int i=1;i<=n;i++)
        {
            if (vis[i])
                continue;
            if (root==0)
                root=now=i;
            else
                now=r[now]=i;
        }
        memset(f,63,sizeof(f));
        f[0][0]=0;
        dp(root);
        int ans=1<<30;
        for (int i=m;i<=n;i++)
            ans=min(ans,f[root][i]);
        printf("%d\n",ans);
    }
    return(0);
}

