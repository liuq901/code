#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef set <int>::iterator iter;
char buf[10000];
string s[100010];
int a[100010],b[100010],c[100010],p[100010];
map <string,int> hash;
multiset <int> f;
int getmin(int n,int m,int me)
{
    int now=a[me];
    if (n==m)
    {
        now+=b[n];
        m--;
    }
    f.clear();
    for (int i=1;i<=m;i++)
        f.insert(b[i]);
    int ret=p[me];
    for (int i=p[me]+1;i<=n;i++)
    {
        int x=c[i];
        iter k=f.lower_bound(now-a[x]);
        if (k!=f.end())
        {
            ret++;
            f.erase(k);
        }
    }
    return(ret);
}
int getmax(int n,int m,int me)
{
    int now=a[me]+b[1];
    f.clear();
    for (int i=2;i<=m;i++)
        f.insert(b[i]);
    int ret=p[me],tot=n-m;
    for (int i=p[me]-1;i;i--)
    {
        int x=c[i];
        if (f.empty())
        {
            ret-=now>a[x];
            continue;
        }
        iter k=f.lower_bound(now-a[x]);
        if (k!=f.begin())
        {
            ret--;
            f.erase(--k);
        }
        else if (tot>0 && now>a[x])
        {
            ret--;
            tot--;
        }
        else
        {
            k=f.end();
            f.erase(--k);
        }
    }
    return(ret);
}
inline bool cmp(int x,int y)
{
    return(a[x]>a[y]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s%d",buf,&a[i]);
        a[i]*=10;
        hash[buf]=i;
        c[i]=i;
        s[i]=buf;
    }
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        b[i]*=10;
    }
    sort(b+1,b+m+1);
    reverse(b+1,b+m+1);
    scanf("%s",buf);
    int me=hash[buf];
    for (int i=1;i<=n;i++)
    {
        if (s[i]<s[me])
            a[i]+=5;
        if (s[i]>s[me])
            a[i]-=5;
    }
    sort(c+1,c+n+1,cmp);
    for (int i=1;i<=n;i++)
        p[c[i]]=i;
    printf("%d %d\n",getmax(n,m,me),getmin(n,m,me));
    return(0);
}

