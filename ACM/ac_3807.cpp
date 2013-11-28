#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int a[4][4];
    static bool f[4][4][4];
    static int n;
    state()
    {
        memset(a,0,sizeof(a));
    }
    bool final()
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (a[i][j]!=0)
                    return(false);
        return(true);
    }
    bool move(int op)
    {
        int beginx,beginy,endx,endy,dx,dy;
        beginx=beginy=0;
        endx=endy=n;
        dx=dy=1;
        if (c[op][0]==1)
            beginx=n-1,endx=-1,dx=-1;
        if (c[op][1]==1)
            beginy=n-1,endy=-1,dy=-1;
        for (int i=beginx;i!=endx;i+=dx)
            for (int j=beginy;j!=endy;j+=dy)
            {
                if (a[i][j]<=0)
                    continue;
                int x=i,y=j,ball=a[i][j];
                bool flag=true;
                while (1)
                {
                    if (a[x][y]<0)
                    {
                        if (a[x][y]!=-ball)
                            return(false);
                        a[x][y]=0;
                        flag=false;
                        break;
                    }
                    if (f[x][y][op] || a[x+c[op][0]][y+c[op][1]]>0)
                        break;
                    x+=c[op][0],y+=c[op][1];
                }
                a[i][j]=0;
                if (flag)
                    a[x][y]=ball;
            }
        return(true);
    }
};
inline bool operator <(const state &a,const state &b)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (a.a[i][j]!=b.a[i][j])
                return(a.a[i][j]<b.a[i][j]);
    return(false);
}
bool state::f[4][4][4];
int state::n;
queue <state> Q;
map <state,int> M;
int main()
{
    while (1)
    {
        int n,m,W;
        scanf("%d%d%d",&n,&m,&W);
        if (n==0 && m==0 && W==0)
            break;
        state::n=n;
        state begin;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            begin.a[x][y]=i;
        }
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            begin.a[x][y]=-i;
        }
        memset(state::f,0,sizeof(state::f));
        for (int i=1;i<=W;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if (x1>x2)
                swap(x1,x2);
            if (y1>y2)
                swap(y1,y2);
            if (x1==x2)
                state::f[x1][y1][3]=state::f[x2][y2][2]=true;
            else
                state::f[x1][y1][1]=state::f[x2][y2][0]=true;
        }
        for (int i=0;i<n;i++)
            state::f[0][i][0]=state::f[n-1][i][1]=state::f[i][0][2]=state::f[i][n-1][3]=true;
        static int id=0;
        printf("Case %d: ",++id);
        while (!Q.empty())
            Q.pop();
        Q.push(begin);
        M.clear();
        M[begin]=0;
        while (!Q.empty())
        {
            state x=Q.front();
            int value=M[x];
            if (x.final())
            {
                printf("%d moves\n",value);
                break;
            }
            Q.pop();
            for (int i=0;i<4;i++)
            {
                state y=x;
                if (y.move(i) && !M.count(y))
                {
                    Q.push(y);
                    M[y]=value+1;
                }
            }
        }
        if (Q.empty())
            printf("impossible\n");
        printf("\n");
    }
    return(0);
}

