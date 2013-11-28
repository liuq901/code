#include <cstdio>
#include <cstring>
#include <set>
#include <utility>
#include <stack>
using namespace std;
set <pair <int,int> > S;
int l[600010],r[600010],c[600010];
char s[1200010];
void dfs()
{
    stack <pair <int,int> > S;
    S.push(make_pair(1,0));
    int tot=0;
    while (!S.empty())
    {
        int x=S.top().first,step=S.top().second;
        s[++tot]='0'+(c[x]&1);
        if (step==2 || step==1 && r[x]==0 || step==0 && l[x]==0 && r[x]==0)
            S.pop();
        else if (step==1)
        {
            S.top().second=2;
            S.push(make_pair(r[x],0));
        }
        else if (l[x]==0)
        {
            S.top().second=2;
            S.push(make_pair(r[x],0));
        }
        else
        {
            S.top().second=1;
            S.push(make_pair(l[x],0));
        }
    }
}
struct trie
{
    char ch;
    int suffix,son[2];
    bool danger;
};
trie a[7010];
char b[7010];
void build()
{
    scanf("%s",b+1);
    int len=strlen(b+1);
    a[0].son[0]=a[0].son[1]=0;
    a[0].danger=false;
    for (int i=1;i<=len;i++)
    {
        a[i].son[0]=a[i].son[1]=0;
        a[i].ch=b[i];
        a[i].danger=false;
        a[i-1].son[b[i]-'0']=i;
    }
    a[len].danger=true;
    for (int i=0;i<=len;i++)
    {
        if (i<=1)
            a[i].suffix=0;
        else
            a[i].suffix=a[a[i-1].suffix].son[a[i].ch-'0'];
        if (a[i].son[0]==0)
            a[i].son[0]=a[a[i].suffix].son[0];
        if (a[i].son[1]==0)
            a[i].son[1]=a[a[i].suffix].son[1];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        S.clear();
        for (int i=1;i<=n;i++)
        {
            l[i]=r[i]=0;
            scanf("%d",&c[i]);
            if (i!=1)
            {
                set <pair <int,int> >::iterator k=S.upper_bound(make_pair(c[i],i));
                if (k!=S.end() && l[k->second]==0)
                    l[k->second]=i;
                else
                    r[(--k)->second]=i;
            }
            S.insert(make_pair(c[i],i));
        }
        dfs();
        build();
        int now=0,ans=0;
        for (int i=1;i<2*n;i++)
        {
            now=a[now].son[s[i]-'0'];
            ans+=a[now].danger;
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,ans);
    }
    return(0);
}

