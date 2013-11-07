#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
struct trie
{
    char ch;
    int son,next,father,suffix;
    vector <int> danger;
};
trie a[110];
int m,now,q[110];
ll f[30][110][1100];
vector <string> ans,s[30][110][1100];
char buf[20];
void clear(int x)
{
    a[x].son=a[x].next=0;
    a[x].danger.clear();
}
void insert(char *s,int l,int t,int x)
{
    if (t==l)
    {
        a[x].danger.push_back(now);
        return;
    }
    if (!a[x].son)
    {
        a[x].son=++m;
        clear(m);
        a[m].father=x;
        a[m].ch=s[t];
        insert(s,l,t+1,m);
        return;
    }
    int i=a[x].son;
    while (1)
    {
        if (!a[i].next || a[i].ch==s[t])
            break;
        i=a[i].next;
    }
    if (a[i].ch==s[t])
        insert(s,l,t+1,i);
    else
    {
        a[i].next=++m;
        clear(m);
        a[m].father=x;
        a[m].ch=s[t];
        insert(s,l,t+1,m);
    }
}
int child(int x,char ch)
{
    for (int i=a[x].son;i;i=a[i].next)
        if (a[i].ch==ch)
            return(i);
    if (x==1)
        return(1);
    return(child(a[x].suffix,ch));
}
void build_trie()
{
    int l,r;
    l=r=1;
    q[1]=1;
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
        a[x].danger.insert(a[x].danger.end(),a[a[x].suffix].danger.begin(),a[a[x].suffix].danger.end());
    }
}
int main()
{
    while (1)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        if (n==0 && K==0)
            break;
        clear(m=1);
        for (int i=1;i<=K;i++)
        {
            scanf("%s",buf);
            now=i-1;
            insert(buf,strlen(buf),0,1);
        }
        build_trie();
        int limit=(1<<K)-1;
        for (int i=0;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int k=0;k<=limit;k++)
                {
                    f[i][j][k]=0;
                    s[i][j][k].clear();
                }
        f[0][1][0]=1;
        s[0][1][0].push_back("");
        for (int i=0;i<n;i++)
            for (int j=1;j<=m;j++)
                for (int k=0;k<=limit;k++)
                {
                    if (f[i][j][k]==0)
                        continue;
                    for (char ch='a';ch<='z';ch++)
                    {
                        int x=child(j,ch),opt=k;
                        for (int p=0;p<a[x].danger.size();p++)
                            opt|=1<<a[x].danger[p];
                        f[i+1][x][opt]+=f[i][j][k];
                        if (f[i+1][x][opt]<=42)
                            for (int p=0;p<s[i][j][k].size();p++)
                                s[i+1][x][opt].push_back(s[i][j][k][p]+ch);
                    }
                }
        ll sum=0;
        ans.clear();
        for (int i=1;i<=m;i++)
        {
            sum+=f[n][i][limit];
            if (sum<=42)
                ans.insert(ans.end(),s[n][i][limit].begin(),s[n][i][limit].end());
        }
        static int id=0;
        printf("Case %d: %lld suspects\n",++id,sum);
        if (sum<=42)
        {
            sort(ans.begin(),ans.end());
            for (int i=0;i<ans.size();i++)
                printf("%s\n",ans[i].c_str());
        }
    }
    return(0);
}

