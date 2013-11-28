#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
bool f[30];
char buf[100000];
string a[30];
vector <string> word;
int n,cnt,use[30],ans[30];
bool same(const string &s,const string &t)
{
    if (s.size()!=t.size())
        return(false);
    for (int i=0;i<s.size();i++)
    {
        int x=s[i]-'A',y=t[i]-'A';
        if (use[x]==-1 && use[y]==-1)
            continue;
        if (use[x]==-1 || use[y]==-1)
            return(false);
        if (use[x]!=y || use[y]!=x)
            return(false);
    }
    return(true);
}
bool check()
{
    for (int i=0;i<word.size();i++)
    {
        bool flag=false;
        for (int j=1;j<=n;j++)
            if (same(word[i],a[j]))
            {
                flag=true;
                break;
            }
        if (!flag)
            return(false);
    }
    return(true);
}
void dfs(int dep)
{
    if (dep==word.size())
    {
        cnt++;
        memcpy(ans,use,sizeof(ans));
        return;
    }
    for (int i=1;i<=n;i++)
    {
        int tmp[30];
        if (same(word[dep],a[i]))
        {
            memcpy(tmp,use,sizeof(use));
            for (int j=0;j<a[i].size();j++)
            {
                int x=word[dep][j]-'A',y=a[i][j]-'A';
                use[x]=y,use[y]=x;
            }
            if (check())
            {
                dfs(dep+1);
                if (cnt==2)
                    return;
            }
            memcpy(use,tmp,sizeof(tmp));
        }
    }
}
string change(const string &s)
{
    string ret;
    for (int i=0;i<s.size();i++)
        ret+=char(ans[s[i]-'A']+'A');
    return(ret);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            a[i]=buf;
            for (int j=0;j<a[i].size();j++)
                f[a[i][j]-'A']=true;
        }
        fgets(buf,100000,stdin);
        fgets(buf,100000,stdin);
        string last;
        word.clear();
        for (int i=0;;i++)
        {
            if (!isalpha(buf[i]))
            {
                for (int j=0;j<last.size();j++)
                    f[last[j]-'A']=true;
                word.push_back(last);
                last="";
                if (buf[i]=='.')
                    break;
                continue;
            }
            last+=buf[i];
        }
        cnt=0;
        memset(use,-1,sizeof(use));
        dfs(0);
        if (cnt!=1)
            printf("-.\n");
        else
        {
            for (int i=0;i<word.size();i++)
                printf("%s%c",change(word[i]).c_str(),i==word.size()-1?'.':' ');
            printf("\n");
        }
    }
    return(0);
}

