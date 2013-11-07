#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
char s[10000],t[10000];
int f[10000],g[10000];
void work(char *s,int *f)
{
    int n=strlen(s);
    for (int i=0;i<n;i++)
        f[i]=0;
    int tot=0;
    for (int i=0;i<n;i++)
    {
        s[i]=toupper(s[i]);
        if ((s[i]=='+' || s[i]=='-') && i!=n-1 && isdigit(s[i+1]) && (i==0 || !isdigit(s[i-1])))
            f[i]=++tot;
        if (isdigit(s[i]))
            f[i]=i==0 || f[i-1]==0?++tot:f[i-1];
    }
}
bool zero(const string &a)
{
    for (int i=0;i<a.size();i++)
        if (isdigit(a[i]) && a[i]!='0')
            return(false);
    return(true);
}
int cmpnum(string a,string b)
{
    if (zero(a) && zero(b))
        return(0);
    bool negaa=a[0]=='-',negab=b[0]=='-';
    if (!isdigit(a[0]))
        a.erase(a.begin());
    if (!isdigit(b[0]))
        b.erase(b.begin());
    if (negaa && !negab)
        return(-1);
    if (!negaa && negab)
        return(1);
    if (negaa && negab)
        swap(a,b);
    int n=max(a.size(),b.size());
    a.insert(0,n-a.size(),'0');
    b.insert(0,n-b.size(),'0');
    for (int i=0;i<n;i++)
        if (a[i]!=b[i])
            return(a[i]<b[i]?-1:1);
    return(0);
}
int cmp()
{
    int n=strlen(s),m=strlen(t);
    int x=0,y=0;
    while (x<n && y<m)
    {
        if (f[x]==0 || g[y]==0)
        {
            if (s[x]!=t[y])
                return(s[x]<t[y]?-1:1);
            x++,y++;
            continue;
        }
        string a,b;
        while (x<n && f[x])
            a+=s[x++];
        while (y<m && g[y])
            b+=t[y++];
        int p=cmpnum(a,b);
        if (p!=0)
            return(p);
    }
    if (x==n && y==m)
        return(0);
    return(x==n?-1:1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",s,t);
        work(s,f);
        work(t,g);
        static int id=0;
        printf("%d %d\n",++id,cmp());
    }
    return(0);
}

