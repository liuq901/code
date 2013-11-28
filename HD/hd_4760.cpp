#include <cstdio>
#include <utility>
#include <vector>
#include <string>
using namespace std;
struct trie
{
    int son[2];
    vector <pair <short,int> > a;
};
trie a[1000000];
int idx,tot=1,ok[1100];
bool able[1100];
inline string ip(int x)
{
    string ret;
    for (int i=7;i>=0;i--)
    {
        int p=x>>i&1;
        ret+=char(p+'0');
    }
    return(ret);
}
void insert(const string &s,int len,int id)
{
    int now=1;
    for (int i=0;i<len;i++)
    {
        int x=s[i]-'0';
        if (!a[now].son[x])
            a[now].son[x]=++tot;
        now=a[now].son[x];
    }
    int value=0;
    for (int i=len;i<s.size();i++)
        value=value<<1|s[i]-'0';
    a[now].a.push_back(make_pair(id,value));
}
void fill(const string &s)
{
    int v[40];
    v[s.size()]=0;
    for (int i=s.size()-1;i>=0;i--)
        v[i]=s[i]-'0'<<s.size()-i-1|v[i+1];
    int now=1;
    for (int i=0;i<s.size();i++)
    {
        int x=s[i]-'0';
        if (!a[now].son[x])
            return;
        now=a[now].son[x];
        for (int j=0;j<a[now].a.size();j++)
            if (v[i+1]>=a[now].a[j].second && able[a[now].a[j].first])
                ok[a[now].a[j].first]=idx;
    }
}
bool query(const string &s)
{
    int v[40];
    v[s.size()]=0;
    for (int i=s.size()-1;i>=0;i--)
        v[i]=s[i]-'0'<<s.size()-i-1|v[i+1];
    int now=1;
    for (int i=0;i<s.size();i++)
    {
        int x=s[i]-'0';
        if (!a[now].son[x])
            return(false);
        now=a[now].son[x];
        for (int j=0;j<a[now].a.size();j++)
            if (v[i+1]>=a[now].a[j].second && ok[a[now].a[j].first]==idx)
                return(true);
    }
    return(false);
}
int main()
{
    char op[10];
    while (scanf("%s",op)==1)
        if (op[0]=='E')
        {
            int id,n;
            scanf("%d%d",&id,&n);
            able[id]=true;
            for (int i=1;i<=n;i++)
            {
                int u,v,w,x,y;
                scanf("%d.%d.%d.%d/%d",&u,&v,&w,&x,&y);
                string s=ip(u)+ip(v)+ip(w)+ip(x);
                insert(s,y,id);
            }
        }
        else if (op[0]=='D')
        {
            int id;
            scanf("%d",&id);
            able[id]=false;
        }
        else
        {
            int u,v,w,x;
            idx++;
            scanf("%d.%d.%d.%d",&u,&v,&w,&x);
            string s=ip(u)+ip(v)+ip(w)+ip(x);
            fill(s);
            scanf("%d.%d.%d.%d",&u,&v,&w,&x);
            s=ip(u)+ip(v)+ip(w)+ip(x);
            printf("%s\n",query(s)?"F":"D");
        }
    return(0);
}

