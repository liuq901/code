#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int x,y,key;
    state(int x,int y,int key):x(x),y(y),key(key){}
};
char a[110][110];
map <char,int> to;
queue <state> q;
int d[110][110][20];
int main()
{
    to['b']=0,to['y']=1,to['r']=2,to['g']=3;
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int Sx,Sy;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]=='*')
                    Sx=i,Sy=j;
        memset(d,63,sizeof(d));
        int inf=d[0][0][0];
        d[Sx][Sy][0]=0;
        q.push(state(Sx,Sy,0));
        while (!q.empty())
        {
            int x0=q.front().x,y0=q.front().y,key=q.front().key;
            q.pop();
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x<=0 || x>n || y<=0 || y>m || a[x][y]=='#' || isupper(a[x][y]) && a[x][y]!='X' && (key>>to[tolower(a[x][y])]&1)==0)
                    continue;
                int now=key;
                if (islower(a[x][y]))
                    now|=1<<to[a[x][y]];
                if (d[x][y][now]==inf)
                {
                    d[x][y][now]=d[x0][y0][key]+1;
                    q.push(state(x,y,now));
                }
            }
        }
        int ans=inf;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]!='X')
                    continue;
                for (int k=0;k<1<<4;k++)
                    ans=min(ans,d[i][j][k]);
            }
        if (ans==inf)
            printf("The poor student is trapped!\n");
        else
            printf("Escape possible in %d steps.\n",ans);
    }
    return(0);
}

