#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
const int N=2000010;
struct trie
{
    char ch;
    int son,next,suffix,father,danger;
};
trie a[N];
char buf[100010];
int tot,pos[210],cnt[210],w[210][210];
string name[210],s[210];
void clear(int x)
{
    a[x].son=a[x].next=0;
    a[x].danger=0;
}
int insert(int x,char ch)
{
    for (int i=a[x].son;i;i=a[i].next)
        if (a[i].ch==ch)
            return(i);
    clear(++tot);
    a[tot].father=x;
    a[tot].ch=ch;
    if (!a[x].son)
        a[x].son=tot;
    else
    {
        int p=a[x].son;
        while (a[p].next)
            p=a[p].next;
        a[p].next=tot;
    }
    return(tot);
}
int q[N];
int child(int x,char ch)
{
    for (int i=a[x].son;i;i=a[i].next)
        if (a[i].ch==ch)
            return(i);
    if (x==1)
        return(1);
    return(child(a[x].suffix,ch));
}
void build()
{
    int l,r;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=a[x].son;i;i=a[i].next)
            q[++r]=i;
    }
    a[1].suffix=1;
    for (int i=2;i<=r;i++)
    {
        int x=q[i];
        if (a[x].father==1)
        {
            a[x].suffix=1;
            continue;
        }
        a[x].suffix=child(a[a[x].father].suffix,a[x].ch);
    }
}
int K,b[210],dx[210],dy[210],slack[210];
bool f[210],g[210];
bool hungary(int x)
{
    if (x==0)
        return(true);
    f[x]=true;
    for (int y=1;y<=K;y++)
    {
        if (g[y])
            continue;
        int t=dx[x]+dy[y]-w[x][y];
        if (t==0)
        {
            g[y]=true;
            if (hungary(b[y]))
            {
                b[y]=x;
                return(true);
            }
        }
        else
            slack[y]=min(slack[y],t);
    }
    return(false);
}
int KM()
{
    memset(dx,0,sizeof(dx));
    memset(dy,0,sizeof(dy));
    memset(b,0,sizeof(b));
    for (int i=1;i<=K;i++)
        for (int j=1;j<=K;j++)
            dx[i]=max(dx[i],w[i][j]);
    for (int i=1;i<=K;i++)
    {
        memset(slack,63,sizeof(slack));
        while (1)
        {
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
            if (hungary(i))
                break;
            int d=1<<30;
            for (int i=1;i<=K;i++)
                if (!g[i])
                    d=min(d,slack[i]);
            for (int i=1;i<=K;i++)
            {
                if (f[i])
                    dx[i]-=d;
                if (g[i])
                    dy[i]+=d;
            }
        }
    }
    int ans=0;
    for (int i=1;i<=K;i++)
        ans+=w[b[i]][i];
    return(ans);
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n+m;i++)
        {
            scanf("%s",buf);
            name[i]=buf;
            name[i].erase(name[i].size()-1);
            gets(buf);
            s[i]=buf+1;
        }
        clear(tot=1);
        for (int i=1;i<=n+m;i++)
        {
            int x=1;
            for (int j=0;j<name[i].size();j++)
                x=insert(x,name[i][j]);
            a[x].danger=i;
        }
        build();
        memset(w,0,sizeof(w));
        for (int i=1;i<=n+m;i++)
        {
            int x=1;
            memset(pos,0,sizeof(pos));
            memset(cnt,0,sizeof(cnt));
            for (int j=0;j<s[i].size();j++)
            {
                x=child(x,s[i][j]);
                for (int k=x;k!=1;k=a[k].suffix)
                {
                    int y=a[k].danger;
                    if (y==0)
                        continue;
                    if (pos[y]==0)
                        pos[y]=j-name[y].size()+2;
                    cnt[y]++;
                }
            }
            if (i<=n)
                for (int j=n+1;j<=n+m;j++)
                    w[i][j-n]+=pos[j]*cnt[j];
            else
                for (int j=1;j<=n;j++)
                    w[j][i-n]+=pos[j]*cnt[j];
        }
        K=max(n,m);
        printf("%d\n",KM());
    }
    return(0);
}

