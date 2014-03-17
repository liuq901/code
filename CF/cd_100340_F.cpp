#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
string ans[26];
char a[1000000],b[1000000];
int len;
string s;
vector <string> now;
bool check(const string &s)
{
    for (int i=0;i<now.size();i++)
        if (s.substr(0,now[i].size())==now[i] || now[i].substr(0,s.size())==s)
            return(false);
    return(true);
}
bool dfs(int dep,int pos)
{
    if (dep==len)
    {
        if (pos==s.size())
        {
            for (int i=0;i<26;i++)
                if (!ans[i].empty())
                    printf("%c %s\n",i+'a',ans[i].c_str());
            return(true);
        }
        return(false);
    }
    int x=a[dep]-'a';
    if (ans[x].empty())
    {
        for (int i=1;i<=10;i++)
        {
            if (pos+i>s.size())
                break;
            ans[x]=s.substr(pos,i);
            if (check(ans[x]))
            {
                now.push_back(ans[x]);
                if (dfs(dep+1,pos+i))
                    return(true);
                now.pop_back();
            }
        }
        ans[x].clear();
    }
    else if (ans[x]==s.substr(pos,ans[x].size()) && dfs(dep+1,pos+ans[x].size()))
        return(true);
    return(false);
}
int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    scanf("%s%s",a,b);
    len=strlen(a);
    s=b;
    dfs(0,0);
    return(0);
}

