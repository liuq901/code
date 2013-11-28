#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
const int inf=100000000;
int n,a[40][4],f[110][110][30];
char s[110];
bool vis[110][110][30];
int solve(int l,int r,int ch)
{
    if (vis[l][r][ch])
        return(f[l][r][ch]);
    vis[l][r][ch]=true;
    int &ret=f[l][r][ch];
    if (l==r)
        ret=ch+'A'==s[l]?0:inf;
    else
    {
        ret=inf;
        for (int i=l;i<r;i++)
            for (int j=1;j<=n;j++)
            {
                if (a[j][0]!=ch)
                    continue;
                ret=min(ret,solve(l,i,a[j][1])+solve(i+1,r,a[j][2])+a[j][3]);
            }
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
        {
            char x[10],y[10],z[10];
            int d;
            scanf("%s%s%s%d",x,y,z,&d);
            a[i][0]=x[0]-'A',a[i][1]=y[0]-'A',a[i][2]=z[0]-'A',a[i][3]=d;
        }
        static int id=0;
        printf("CASE #%d\n",++id);
        while (Q--)
        {
            int len,sum=0;
            scanf("%d%s",&len,s);
            for (int i=0;i<len;i++)
                if (islower(s[i]))
                {
                    sum++;
                    s[i]=toupper(s[i]);
                }
            memset(vis,0,sizeof(vis));
            int ans=solve(0,len-1,0);
            if (ans==inf)
                printf("IMPOSSIBLE\n");
            else
                printf("POSSIBLE WITH %d DIAMONDS\n",ans+sum);
        }
    }
    return(0);
}

