#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int lq=10007;
struct data
{
    char a[26];
    data()
    {
        memset(a,0,sizeof(a));
    }
    char &operator [](int x)
    {
        return(a[x]);
    }
    char operator [](int x) const
    {
        return(a[x]);
    }
    ull hash() const
    {
        ull ret=0;
        for (int i=0;i<26;i++)
            ret=ret*lq+a[i];
        return(ret);
    }
};
inline bool operator <(const data &a,const data &b)
{
    return(false);
}
data a[1010];
char buf[1000000];
data calc(const string &s)
{
    data ret;
    for (int i=0;i<s.size();i++)
        ret[s[i]-'A']++;
    return(ret);
}
set <string> S;
int n,m,tot;
bool ans(const data &a)
{
    string s;
    for (int i=0;i<26;i++)
        for (int j=0;j<a[i];j++)
            s+=char(i+'A');
    while (1)
    {
        if (!S.count(s))
        {
            S.insert(s);
            printf("%s\n",s.c_str());
            if (++tot==n)
                return(true);
        }
        if (!next_permutation(s.begin(),s.end()))
            break;
    }
    return(false);
}
int get(const data &b)
{
    int ret=0;
    for (int i=1;i<=m;i++)
    {
        bool flag=true;
        for (int j=0;j<26;j++)
            if (a[i][j]<b[j])
            {
                flag=false;
                break;
            }
        ret+=flag;
    }
    return(ret);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%s",buf);
        string tmp=buf;
        S.insert(tmp);
        a[i]=calc(tmp);
    }
    S.insert("");
    priority_queue <pair <int,data> > Q;
    Q.push(make_pair(m,data()));
    set <ull> lq;
    while (!Q.empty())
    {
        data tmp=Q.top().second;
        Q.pop();
        if (ans(tmp))
            break;
        for (int i=0;i<26;i++)
        {
            tmp[i]++;
            if (!lq.count(tmp.hash()))
            {
                lq.insert(tmp.hash());
                Q.push(make_pair(get(tmp),tmp));
            }
            tmp[i]--;
        }
    }
    return(0);
}

