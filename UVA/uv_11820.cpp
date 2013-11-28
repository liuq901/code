#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct trie
{
    int son,next,fa,suffix;
    char ch;
    vector <int> danger;
};
trie a[100010];
char s[10000];
int m=1;
int node(int fa,char ch)
{
    m++;
    a[m].son=a[m].next=0;
    a[m].fa=fa;
    a[m].ch=ch;
    a[m].danger.clear();
    return(m);
}
int insert(int x,char ch)
{
    if (a[x].son==0)
    {
        a[x].son=node(x,ch);
        return(a[x].son);
    }
    int p=a[x].son;
    while (a[p].ch!=ch && a[p].next)
        p=a[p].next;
    if (a[p].ch==ch)
        return(p);
    a[p].next=node(x,ch);
    return(a[p].next);
}
int q[100010];
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
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=a[x].son;i;i=a[i].next)
            q[++r]=i;
    }
    for (int i=1;i<=m;i++)
    {
        int x=q[i];
        if (x==1 || a[x].fa==1)
            a[x].suffix=1;
        else
            a[x].suffix=child(a[a[x].fa].suffix,a[x].ch);
        for (int j=0;j<a[a[x].suffix].danger.size();j++)
            a[x].danger.push_back(a[a[x].suffix].danger[j]);
    }
}
string name[10010];
int f[510],pos[510];
vector <string> ans,now;
vector <int> c;
inline bool cmp(int x,int y)
{
    return(ans[x]<ans[y]);
}
void getans(int len)
{
    if (len==0)
    {
        string tmp;
        for (int i=now.size()-1;i>=0;i--)
        {
            tmp+=now[i];
            if (i>0)
                tmp+=" ";
        }
        ans.push_back(tmp);
    }
    if (f[len]==f[len-1]+1)
    {
        now.push_back(string(s+len,s+len+1));
        getans(len-1);
        now.pop_back();
    }
    for (int i=0;i<a[pos[len]].danger.size();i++)
    {
        int id=a[pos[len]].danger[i];
        if (f[len]==f[len-name[id].size()]+1)
        {
            now.push_back(name[id]);
            getans(len-name[id].size());
            now.pop_back();
        }
    }
}
int main()
{
    int n=0;
    while (1)
    {
        gets(s);
        int len=strlen(s);
        if (len==0)
            break;
        name[++n]=s;
        int now=1;
        for (int i=0;i<len;i++)
            now=insert(now,s[i]);
        a[now].danger.push_back(n);
    }
    build_trie();
    while (1)
    {
        gets(s+1);
        int len=strlen(s+1);
        if (len==0)
            break;
        f[0]=0;
        int now=1;
        for (int i=1;i<=len;i++)
        {
            now=child(now,s[i]);
            f[i]=f[i-1]+1;
            pos[i]=now;
            for (int j=0;j<a[now].danger.size();j++)
            {
                int id=a[now].danger[j];
                f[i]=min(f[i],f[i-name[id].size()]+1);
            }
        }
        ans.clear();
        getans(len);
        printf("%d %d\n",ans.size(),f[len]);
        c.clear();
        for (int i=0;i<ans.size();i++)
            c.push_back(i);
        sort(c.begin(),c.end(),cmp);
        for (int i=0;i<ans.size();i++)
            printf("%s\n",ans[c[i]].c_str());
    }
    return(0);
}

