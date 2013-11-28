#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
string s[5010];
bool f[5010];
char buf[20];
int c[5010];
bool check(const string &a,const string &b,int x,int y,int t)
{
    if (t==-1 || x>a.size() || y>b.size())
        return(false);
    int p=a.size()-x,q=b.size()-y;
    if (abs(p-q)>t)
        return(false);
    while (x<a.size() && y<b.size() && a[x]==b[y])
        x++,y++;
    if (x==a.size() && y==b.size())
        return(true);
    if (check(a,b,x+1,y+1,t-1))
        return(true);
    if (check(a,b,x,y+1,t-1))
        return(true);
    if (check(a,b,x+1,y,t-1))
        return(true);
    return(false);
}
inline bool cmp(int x,int y)
{
    return(s[x].size()<s[y].size());
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        c[i]=i;
        s[i]=buf;
    }
    sort(s+1,s+n+1);
    sort(c+1,c+n+1,cmp);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            int x=c[i],y=c[j],l1=s[x].size(),l2=s[y].size();
            if (abs(l1-l2)>2)
                break;
            if (check(s[x],s[y],0,0,2))
                f[x]=f[y]=true;
        }
    printf("%d\n",count(f+1,f+n+1,true));
    for (int i=1;i<=n;i++)
        if (f[i])
            printf("%s\n",s[i].c_str());
    return(0);
}

