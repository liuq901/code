#include <cstdio>
#include <utility>
using namespace std;
int m,K;
pair <int,int> f[10010][2];
bool vis[10010][2];
void update1(pair <int,int> &a,const pair <int,int> &b)
{
    if (a.first<b.first || a.first==b.first && a.second>b.second)
        a=b;
}
void update2(pair <int,int> &a,const pair <int,int> &b)
{
    if (a.second<b.second || a.second==b.second && a.first>b.first)
        a=b;
}
pair <int,int> dp(int n,bool first)
{
    if (vis[n][first])
        return(f[n][first]);
    vis[n][first]=true;
    pair <int,int> &ret=f[n][first];
    ret=make_pair(-1<<30,-1<<30);
    if (n==0)
        ret=make_pair(0,0);
    else
        for (int i=1;i<=K;i++)
        {
            pair <int,int> now;
            if (first)
            {
                if (n>=i)
                {
                    now=dp(n-i,false);
                    now.first+=i;
                }
                else
                    now=make_pair(m,0);
                update1(ret,now);
            }
            else
            {
                if (n>=i)
                {
                    now=dp(n-i,true);
                    now.second+=i;
                }
                else
                    now=make_pair(0,m);
                update2(ret,now);
            }
        }
    return(ret);
}
int main()
{
    int n;
    scanf("%d%d%d",&n,&m,&K);
    pair <int,int> ans=dp(n,true);
    printf("%d %d\n",ans.first,ans.second);
    return(0);
}

