#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map <string,int> hash;
vector <int> change[1010],a[1010];
vector <string> code[1010];
int n,len,c[10010],year[10010],op[10010],city[10010],pos[10010];
string S[10010];
char buf[10000],buf1[10000];
inline bool cmp(int x,int y)
{
    return(year[x]<year[y]);
}
bool check(const string &a,const string &b)
{
    if (b.size()<a.size())
        return(false);
    for (int i=0;i<a.size();i++)
        if (a[i]!=b[i])
            return(false);
    return(true);
}
int getcity(int year,const string &number)
{
    for (int i=1;i<=n;i++)
    {
        int x=upper_bound(change[i].begin(),change[i].end(),year)-change[i].begin()-1;
        if (check(code[i][x],number))
        {
            len=code[i][x].size();
            return(i);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s%s",buf,buf1);
        hash[buf1]=i;
        change[i].push_back(-1);
        code[i].push_back(buf);
    }
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%s",&year[i],&op[i],buf);
        c[i]=i;
        city[i]=hash[buf];
        if (op[i]==3)
        {
            scanf("%s",buf1);
            S[i]=buf1;
        }
        else
            scanf("%d",&pos[i]);
    }
    sort(c+1,c+m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        int x=c[i];
        a[city[x]].push_back(x);
        if (op[x]==3)
        {
            change[city[x]].push_back(year[x]);
            code[city[x]].push_back(S[x]);
        }
    }
    while (1)
    {
        int begin,end;
        scanf("%d%d%s",&begin,&end,buf);
        string s=buf;
        if (begin==0 && end==0 && s=="0")
            break;
        int city=getcity(begin,s);
        string u=s.substr(0,len),v=s.substr(len);
        year[0]=begin;
        int now=upper_bound(a[city].begin(),a[city].end(),0,cmp)-a[city].begin();
        for (int i=now;i<a[city].size();i++)
        {
            int x=a[city][i];
            if (year[x]>end)
                break;
            if (op[x]==1)
            {
                char ch=v[pos[x]-1];
                v.insert(pos[x],1,ch);
            }
            else if (op[x]==2)
                swap(v[pos[x]-1],v[pos[x]]);
            else
                u=S[x];
        }
        printf("%s\n",(u+v).c_str());
    }
    return(0);
}

