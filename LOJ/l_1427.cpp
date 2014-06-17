#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct trie
{
    char ch;
    int son,next,father,suffix;
    vector <int> danger;
};
trie a[250010];
int m,now;
void clear(int x)
{
    a[x].son=a[x].next=0;
    a[x].danger.clear();
}
void insert(char s[],int l,int t,int x)
{
    if (!a[x].son)
    {
        a[x].son=++m;
        clear(m);
        a[m].father=x;
        a[m].ch=s[t];
        if (t+1==l)
            a[m].danger.push_back(now);
        else
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
    if (a[i].ch==s[t] && t+1==l)
        a[i].danger.push_back(now);
    else if (a[i].ch==s[t])
        insert(s,l,t+1,i);
    else
    {
        a[i].next=++m;
        clear(m);
        a[m].father=x;
        a[m].ch=s[t];
        if (t+1==l)
            a[m].danger.push_back(now);
        else
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
int q[250010];
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
        a[x].danger.insert(a[x].danger.end(),a[a[x].suffix].danger.begin(),a[a[x].suffix].danger.end());
    }
}
char s[510],buf[1000010];
int cnt[510];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%s",&n,&buf);
        clear(m=1);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            now=i;
            insert(s,strlen(s),0,1);
        }
        build();
        memset(cnt,0,sizeof(cnt));
        int len=strlen(buf),now=1;
        for (int i=0;i<len;i++)
        {
            now=child(now,buf[i]);
            for (int j=0;j<a[now].danger.size();j++)
                cnt[a[now].danger[j]]++;
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            printf("%d\n",cnt[i]);
    }
    return(0);
}

