#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
char buf[100000];
vector <int> calc(const string &s)
{
    vector <int> a(26,0);
    for (int i=0;i<s.size();i++)
        a[s[i]-'A']++;
    return(a);
}
map <char,int> M;
int get(const string &s)
{
    int ret=0;
    for (int i=0;i<s.size();i++)
        ret=ret*10+M[s[i]];
    return(ret);
}
bool check(int x)
{
    int y=int(sqrt(x+1e-8));
    return(y*y==x);
}
bool vis[10];
int ans;
void dfs(int dep,const string &a,const string &b)
{
    if (dep==a.size())
    {
        int x=get(a),y=get(b);
        if (M[a[0]]!=0 && M[b[0]]!=0 && check(x) && check(y))
            ans=max(ans,max(x,y));
        return;
    }
    if (M.count(a[dep]))
    {
        dfs(dep+1,a,b);
        return;
    }
    for (int i=0;i<10;i++)
    {
        if (vis[i])
            continue;
        vis[i]=true;
        M[a[dep]]=i;
        dfs(dep+1,a,b);
        vis[i]=false;
        M.erase(a[dep]);
    }
}
int main()
{
    scanf("%s",buf);
    int len=strlen(buf);
    for (int i=0;i<len;i++)
        if (buf[i]=='"' || buf[i]==',')
            buf[i]=' ';
    stringstream sin(buf);
    string tmp;
    vector <string> a;
    while (sin>>tmp)
        a.push_back(tmp);
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
        {
            if (calc(a[i])!=calc(a[j]))
                continue;
            dfs(0,a[i],a[j]);
        }
    printf("%d\n",ans);
    return(0);
}

