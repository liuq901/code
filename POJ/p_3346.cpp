#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int x,y,num;
    state(int x,int y,int num):x(x),y(y),num(num){}
};
char a[110][110];
int n,m,Tx,Ty,ans,f[110][110][30];
bool in[110][110][30];
queue <state> Q;
void spfa()
{
    while (!Q.empty())
    {
        int x0=Q.front().x,y0=Q.front().y,num=Q.front().num;
        Q.pop();
        in[x0][y0][num]=false;
        if (x0==Tx && y0==Ty)
            ans=min(ans,f[x0][y0][num]);
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x==0 || x>n || y==0 || y>m)
                continue;
            if (a[x][y]=='.' && f[x0][y0][num]<f[x][y][num])
            {
                f[x][y][num]=f[x0][y0][num];
                if (!in[x][y][num])
                {
                    in[x][y][num]=true;
                    Q.push(state(x,y,num));
                }
            }
            if (isdigit(a[x][y]))
            {
                if (num>0 && f[x0][y0][num]<f[x][y][num-1])
                {
                    f[x][y][num-1]=f[x0][y0][num];
                    if (!in[x][y][num-1])
                    {
                        in[x][y][num-1]=true;
                        Q.push(state(x,y,num-1));
                    }
                }
                if (f[x0][y0][num]+a[x][y]-'0'<f[x][y][num])
                {
                    f[x][y][num]=f[x0][y0][num]+a[x][y]-'0';
                    if (!in[x][y][num])
                    {
                        in[x][y][num]=true;
                        Q.push(state(x,y,num));
                    }
                }
            }
        }
    }
}
int main()
{
    while (1)
    {
        gets(a[1]+1);
        if (a[1][1]=='-')
            break;
        n=1,m=strlen(a[1]+1);
        while (1)
        {
            gets(a[++n]+1);
            if (strlen(a[n]+1)==0)
            {
                n--;
                break;
            }
        }
        memset(f,63,sizeof(f));
        int inf=f[0][0][0];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='#')
                {
                    Q.push(state(i,j,0));
                    in[i][j][0]=true;
                    f[i][j][0]=0;
                }
                if (isalpha(a[i][j]))
                {
                    int num=a[i][j]-'A'+1;
                    Q.push(state(i,j,num));
                    in[i][j][num]=true;
                    f[i][j][num]=0;
                }
                if (a[i][j]=='$')
                {
                    Tx=i,Ty=j;
                    a[i][j]='.';
                }
            }
        ans=inf;
        spfa();
        if (ans==inf)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

