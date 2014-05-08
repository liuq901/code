#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int x,y,dep;
    state(int x,int y,int dep):x(x),y(y),dep(dep){}
};
int d[20][20][30];
char a[20][20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int Sx,Sy,Tx,Ty,m=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (isalpha(a[i][j]))
                {
                    m=max(m,a[i][j]-'A'+1);
                    if (a[i][j]=='A')
                        Sx=i,Sy=j;
                    if (a[i][j]==m+'A'-1)
                        Tx=i,Ty=j;
                }
        queue <state> Q;
        memset(d,-1,sizeof(d));
        d[Sx][Sy][1]=0;
        Q.push(state(Sx,Sy,1));
        while (!Q.empty())
        {
            int x0=Q.front().x,y0=Q.front().y,dep=Q.front().dep;
            Q.pop();
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x<=0 || x>n || y<=0 || y>n || a[x][y]=='#')
                    continue;
                int now=dep;
                if (isalpha(a[x][y]))
                {
                    int p=a[x][y]-'A'+1;
                    if (p>dep && p!=dep+1)
                        continue;
                    if (p==dep+1)
                        now++;
                }
                if (d[x][y][now]==-1)
                {
                    d[x][y][now]=d[x0][y0][dep]+1;
                    Q.push(state(x,y,now));
                }
            }
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (d[Tx][Ty][m]==-1)
            printf("Impossible\n");
        else
            printf("%d\n",d[Tx][Ty][m]);
    }
    return(0);
}

