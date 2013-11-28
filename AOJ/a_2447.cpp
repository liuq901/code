#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int x,y,lev,swi;
    state(int a,int b,int c,int d):x(a),y(b),lev(c),swi(d){}
};
char a[60][60],s[20][60][60];
int n,m,S,d[60][60][2][1100];
queue <state> Q;
int level(int x,int y,int swi)
{
    int now=a[x][y]=='^' || isupper(a[x][y]);
    for (int i=0;i<S;i++)
        if (swi>>i&1 && s[i][x][y]=='*')
            now^=1;
    return(now);
}
int bfs()
{
    int Sx,Sy,Tx,Ty;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='%')
                Sx=i,Sy=j;
            if (a[i][j]=='&')
                Tx=i,Ty=j;
        }
    d[Sx][Sy][0][0]=1;
    Q.push(state(Sx,Sy,0,0));
    while (!Q.empty())
    {
        int x0=Q.front().x,y0=Q.front().y,lev0=Q.front().lev,swi0=Q.front().swi,value=d[x0][y0][lev0][swi0];
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=m && a[x][y]!='#' && d[x][y][lev0][swi0]==0 && (a[x][y]=='|' || lev0==level(x,y,swi0)))
            {
                d[x][y][lev0][swi0]=value+1;
                Q.push(state(x,y,lev0,swi0));
            }
        }
        if (a[x0][y0]=='|')
        {
            int lev=lev0^1;
            if (d[x0][y0][lev][swi0]==0)
            {
                d[x0][y0][lev][swi0]=value+1;
                Q.push(state(x0,y0,lev,swi0));
            }
        }
        if (isalpha(a[x0][y0]))
        {
            int id=tolower(a[x0][y0])-'a',swi=swi0^1<<id,lev=level(x0,y0,swi);
            if (d[x0][y0][lev][swi]==0)
            {
                d[x0][y0][lev][swi]=value+1;
                Q.push(state(x0,y0,lev,swi));
            }
        }
    }
    int ans=1<<30;
    for (int i=0;i<1<<S;i++)
    {
        int lev=level(Tx,Ty,i);
        if (d[Tx][Ty][lev][i]!=0 && d[Tx][Ty][lev][i]<ans)
            ans=d[Tx][Ty][lev][i];
    }
    if (ans==1<<30)
        return(-1);
    return(ans-1);
}
int main()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    scanf("%d",&S);
    for (int i=0;i<S;i++)
        for (int j=1;j<=n;j++)
            scanf("%s",s[i][j]+1);
    printf("%d\n",bfs());
    return(0);
}

