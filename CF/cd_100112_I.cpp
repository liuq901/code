#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;
const string word[]={"be","our","rum","will","dead","hook","ship","blood","sable","avenge","parrot","captain"};
set <vector <int> > S[30];
string s[210];
vector <int> from,to,ans;
int n,cnt;
char buf[210];
bool f[30],have[210][30];
bool check(const string &s,const string &t)
{
    string now;
    for (int i=0;i<s.size();i++)
    {
        int x=s[i]-'a',y=t[i]-'a';
        if (from[x]!=-1 && from[x]!=y || to[y]!=-1 && to[y]!=x)
            return(false);
        from[x]=y;
        to[y]=x;
        now+=char(from[x]+'a');
    }
    return(t==now);
}
void dfs(int dep)
{
    if (S[dep].count(from))
        return;
    S[dep].insert(from);
    if (dep==26)
    {
        cnt++;
        ans=to;
        return;
    }
    if (!f[dep])
    {
        dfs(dep+1);
        return;
    }
    vector <int> t1,t2;
    for (int i=1;i<=n;i++)
    {
        if (!have[i][dep])
            continue;
        for (int j=0;j<12;j++)
        {
            if (s[i].size()!=word[j].size())
                continue;
            t1=from;
            t2=to;
            if (check(word[j],s[i]))
            {
                dfs(dep+1);
                if (cnt==2)
                    return;
            }
            from=t1;
            to=t2;
        }
    }
}
int main()
{
    while (scanf("%s",buf)==1)
        s[++n]=buf;
    for (int i=1;i<=n;i++)
        for (int j=0;j<s[i].size();j++)
        {
            f[s[i][j]-'a']=true;
            have[i][s[i][j]-'a']=true;
        }
    for (int i=0;i<26;i++)
    {
        from.push_back(-1);
        to.push_back(-1);
    }
    dfs(0);
    if (cnt!=1)
        printf("Impossible\n");
    else
        for (int i=1;i<=n;i++)
        {
            string tmp;
            for (int j=0;j<s[i].size();j++)
                tmp+=char(ans[s[i][j]-'a'])+'a';
            printf("%s%c",tmp.c_str(),i==n?'\n':' ');
        }
    return(0);
}

