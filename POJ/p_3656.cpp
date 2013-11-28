#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct data
{
    int count,length,pos,delta;
    data(){}
    data(int c,int l,int p,int d):count(c),length(l),pos(p),delta(d){}
};
inline bool operator <(const data &a,const data &b)
{
    if (a.count!=b.count)
        return(a.count<b.count);
    if (a.length!=b.length)
        return(a.length<b.length);
    if (a.pos!=b.pos)
        return(a.pos<b.pos);
    if (a.delta!=b.delta)
        return(a.delta>b.delta);
    return(false);
}
char s[100];
int n;
bool vis[100][100];
data f[100][100];
data calc(int x,int d)
{
    if (vis[x][d])
        return(f[x][d]);
    vis[x][d]=true;
    data &ret=f[x][d];
    if (s[x]!='.')
        ret=data(0,x,x,d);
    else if (x+d>=n)
        ret=data(1,x,x,d);
    else
    {
        data tmp=calc(x+d,d);
        ret=tmp;
        ret.count++;
        ret.pos=x;
    }
    return(ret);
}
int main()
{
    while (1)
    {
        scanf("%s",s);
        n=strlen(s);
        if (s[0]=='E' && s[1]=='N' && s[2]=='D' && n==3)
            break;
        data ans;
        ans.count=-1;
        memset(vis,0,sizeof(vis));
        for (int i=0;i<n;i++)
            for (int j=1;j<=n;j++)
            {
                f[i][j]=calc(i,j);
                ans=max(ans,f[i][j]);
            }
        printf("%d %d\n",ans.pos,ans.delta);
    }
    return(0);
}

