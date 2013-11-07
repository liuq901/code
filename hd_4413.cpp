#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
struct state
{
    int a[5];
    ll value;
};
int n,a[40];
state now;
vector <state> ok;
bool check()
{
    now.value=0;
    for (int i=0;i<1<<n;i++)
    {
        bool flag=true;
        for (int j=0;j<n;j++)
            if (now.a[j]!=-1 && (i>>j&1)!=now.a[j])
            {
                flag=false;
                break;
            }
        if (flag && a[i]==0)
            return(false);
        if (flag)
            now.value|=1LL<<i;
    }
    return(true);
}
void dfs(int dep)
{
    if (dep==n)
    {
        if (check())
            ok.push_back(now);
        return;
    }
    for (int i=-1;i<=1;i++)
    {
        now.a[dep]=i;
        dfs(dep+1);
    }
}
bool in(const state &a,const state &b)
{
    for (int i=0;i<n;i++)
        if (b.a[i]!=-1 && a.a[i]!=b.a[i])
            return(false);
    return(true);
}
void unique()
{
    vector <state> tmp(ok);
    ok.clear();
    for (int i=0;i<tmp.size();i++)
    {
        bool flag=true;
        for (int j=0;j<tmp.size();j++)
            if (i!=j && in(tmp[i],tmp[j]))
            {
                flag=false;
                break;
            }
        if (flag)
            ok.push_back(tmp[i]);
    }
}
vector <state> here;
bool d[40];
bool True()
{
    memset(d,0,sizeof(d));
    for (int k=0;k<here.size();k++)
    {
        state now=here[k];
        for (int i=0;i<1<<n;i++)
        {
            bool flag=true;
            for (int j=0;j<n;j++)
                if (now.a[j]!=-1 && (i>>j&1)!=now.a[j])
                {
                    flag=false;
                    break;
                }
            if (flag)
                d[i]=true;
        }
    }
    for (int i=0;i<1<<n;i++)
        if (a[i]!=d[i])
            return(false);
    return(true);
}
string ans,name[40];
inline bool cmp(const string &a,const string &b)
{
    return(a+"+"+b<b+"+"+a);
}
string getname(const state &a)
{
    string ret;
    for (int i=0;i<n;i++)
        if (a.a[i]==0)
            ret+=string("-")+char(i+'A');
    for (int i=0;i<n;i++)
        if (a.a[i]==1)
            ret+=char(i+'A');
    return(ret);
}
void update()
{
    int n=here.size();
    for (int i=0;i<n;i++)
        name[i]=getname(here[i]);
    sort(name,name+n,cmp);
    string ret=name[0];
    for (int i=1;i<n;i++)
        ret+="+"+name[i];
    if (ans=="")
        ans=ret;
    else if (ret.size()<ans.size() || ret.size()==ans.size() && ret<ans)
        ans=ret;
}
void DFS(int dep,ll now)
{
    if (dep==ok.size())
    {
        if (True())
            update();
        return;
    }
    if ((now&ok[dep].value)!=ok[dep].value)
    {
        here.push_back(ok[dep]);
        DFS(dep+1,now|ok[dep].value);
        here.pop_back();
    }
    DFS(dep+1,now);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        int cnt=0;
        for (int i=0;i<1<<n;i++)
        {
            int now=0;
            for (int j=0;j<n;j++)
            {
                int x;
                scanf("%d",&x);
                if (x)
                    now|=1<<j;
            }
            scanf("%d",&a[now]);
            cnt+=a[now];
        }
        if (cnt==1<<n)
            printf("-A+A\n");
        else if (cnt==0)
            printf("-AA\n");
        else
        {
            ok.clear();
            dfs(0);
            unique();
            ans="";
            DFS(0,0LL);
            printf("%s\n",ans.c_str());
        }
    }
}

