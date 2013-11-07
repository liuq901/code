#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const char bridge[]="||--";
map <string,int> hash[15][15];
int n,m,now,ans;
char a[15][15];
string Hash()
{
    string ret;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            ret+=a[i][j];
    return(ret);
}
void go(int x0,int y0,int dir,int &x,int &y)
{
    while (1)
    {
        x0+=c[dir][0];
        y0+=c[dir][1];
        if (x0<0 || x0==n || y0<0 || y0==m)
        {
            x=y=-1;
            return;
        }
        if (isalpha(a[x0][y0]))
        {
            x=x0,y=y0;
            return;
        }
        if (a[x0][y0]!=bridge[dir])
        {
            x=y=-1;
            return;
        }
    }
}
int pick(int x,int y,int dir)
{
    int ret=0;
    while (1)
    {
        x+=c[dir][0],y+=c[dir][1];
        if (x<0 || x==n || y<0 || y==m || a[x][y]!=bridge[dir])
            return(ret);
        ret++;
    }
}
int put(int x,int y,int dir)
{
    int ret=0;
    while (1)
    {
        x+=c[dir][0],y+=c[dir][1];
        if (x<0 || x==n || y<0 || y==m || a[x][y]!='.')
        {
            if (x>=0 && x<n && y>=0 && y<m && isalpha(a[x][y]))
                return(ret);
            return(-1);
        }        
        ret++;
    }
}
void dfs(int hand,int x0,int y0)
{
    string here=Hash();
    if (ans!=-1 && now==ans || hash[x0][y0].count(here) && hash[x0][y0][here]<=now)
        return;
    hash[x0][y0][here]=now;
    if (a[x0][y0]=='E')
    {
        ans=now;
        return;
    }
    for (int i=0;i<4;i++)
    {
        int x,y;
        go(x0,y0,i,x,y);
        if (x!=-1)
        {
            now++;
            dfs(hand,x,y);
            now--;
        }
    }
    if (hand==-1)
        for (int i=0;i<4;i++)
        {
            int len=pick(x0,y0,i);
            if (len!=0)
            {
                now++;
                int x=x0,y=y0;
                for (int j=1;j<=len;j++)
                {
                    x+=c[i][0],y+=c[i][1];
                    a[x][y]='.';
                }
                dfs(len,x0,y0);
                now--;
                x=x0,y=y0;
                for (int j=1;j<=len;j++)
                {
                    x+=c[i][0],y+=c[i][1];
                    a[x][y]=bridge[i];
                }
            }
        }
    else
        for (int i=0;i<4;i++)
        {
            int len=put(x0,y0,i);
            if (len==hand)
            {
                now++;
                int x=x0,y=y0;
                for (int j=1;j<=len;j++)
                {
                    x+=c[i][0],y+=c[i][1];
                    a[x][y]=bridge[i];
                }
                dfs(-1,x0,y0);
                now--;
                x=x0,y=y0;
                for (int j=1;j<=len;j++)
                {
                    x+=c[i][0],y+=c[i][1];
                    a[x][y]='.';
                }
            }
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                scanf(" %c",&a[i][j]);
                hash[i][j].clear();
            }
        int Sx,Sy;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (a[i][j]=='B')
                    Sx=i,Sy=j;
        ans=-1;
        now=0;
        dfs(-1,Sx,Sy);
        if (ans==-1)
            ans=0;
        printf("%d\n",ans);
    }
    return(0);
}

