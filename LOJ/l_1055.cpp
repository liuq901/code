#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int u,v,w;
    state(int u,int v,int w):u(u),v(v),w(w){}
};
char a[20][20];
int d[110][110][110];
int encode(int n,int x,int y)
{
    return((x-1)*n+y-1);
}
void decode(int p,int n,int &x,int &y)
{
    x=p/n+1;
    y=p%n+1;
}
bool check(int n,int x,int y,int dx,int dy)
{
    x+=dx,y+=dy;
    if (x<=0 || x>n || y<=0 || y>n)
        return(false);
    if (a[x][y]=='?')
        return(check(n,x,y,dx,dy));
    return(a[x][y]=='.');
}
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
        int A,B,C;
        vector <int> end;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (a[i][j]=='A')
                {
                    A=encode(n,i,j);
                    a[i][j]='.';
                }
                if (a[i][j]=='B')
                {
                    B=encode(n,i,j);
                    a[i][j]='.';
                }
                if (a[i][j]=='C')
                {
                    C=encode(n,i,j);
                    a[i][j]='.';
                }
                if (a[i][j]=='X')
                {
                    end.push_back(encode(n,i,j));
                    a[i][j]='.';
                }
            }
        queue <state> Q;
        memset(d,-1,sizeof(d));
        d[A][B][C]=0;
        Q.push(state(A,B,C));
        while (!Q.empty())
        {
            int s[3];
            s[0]=Q.front().u,s[1]=Q.front().v,s[2]=Q.front().w;
            Q.pop();
            for (int i=0;i<3;i++)
            {
                int x,y;
                decode(s[i],n,x,y);
                a[x][y]='?';
            }
            for (int i=0;i<4;i++)
            {
                int now[3];
                for (int j=0;j<3;j++)
                {
                    int x,y;
                    decode(s[j],n,x,y);
                    if (check(n,x,y,c[i][0],c[i][1]))
                        x+=c[i][0],y+=c[i][1];
                    now[j]=encode(n,x,y);
                }
                if (d[now[0]][now[1]][now[2]]==-1)
                {
                    d[now[0]][now[1]][now[2]]=d[s[0]][s[1]][s[2]]+1;
                    Q.push(state(now[0],now[1],now[2]));
                }
            }
            for (int i=0;i<3;i++)
            {
                int x,y;
                decode(s[i],n,x,y);
                a[x][y]='.';
            }            
        }
        int ans=-1;
        while (1)
        {
            int x=end[0],y=end[1],z=end[2];
            if (d[x][y][z]!=-1 && (ans==-1 || d[x][y][z]<ans))
                ans=d[x][y][z];
            if (!next_permutation(end.begin(),end.end()))
                break;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("trapped\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

