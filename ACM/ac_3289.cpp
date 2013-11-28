#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int x,y,dir;
    bool ver,hor;
    state(int x,int y,int d,bool v,bool h):x(x),y(y),dir(d),ver(v),hor(h){}
};
queue <state> Q;
int n,m,cx[2][110],cy[2][110],d[110][110][4][2][2];
bool block[110][110],in[110][110][4][2][2];
vector <int> X,Y;
inline bool update(int &a,int b)
{
    if (a==-1 || b<a)
    {
        a=b;
        return(true);
    }
    return(false);
}
int calc(int Sx,int Sy,int Tx,int Ty,bool ver,bool hor)
{
    memset(d,-1,sizeof(d));
    d[Sx][Sy][0][1][0]=0;
    in[Sx][Sy][0][1][0]=true;
    Q.push(state(Sx,Sy,0,1,0));
    d[Sx][Sy][1][1][0]=0;
    in[Sx][Sy][1][1][0]=true;    
    Q.push(state(Sx,Sy,1,1,0));
    d[Sx][Sy][2][0][1]=0;
    in[Sx][Sy][2][0][1]=true;    
    Q.push(state(Sx,Sy,2,0,1));
    d[Sx][Sy][3][0][1]=0;
    in[Sx][Sy][3][0][1]=true;    
    Q.push(state(Sx,Sy,3,0,1));
    while (!Q.empty())
    {
        int x0=Q.front().x,y0=Q.front().y,dir=Q.front().dir,ver=Q.front().ver,hor=Q.front().hor;
        Q.pop();
        in[x0][y0][dir][ver][hor]=false;
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            bool VER=ver || i<=1,HOR=hor || i>=2;
            if (x>0 && x<=n && y>0 && y<=m && !block[x][y] && update(d[x][y][i][VER][HOR],d[x0][y0][dir][ver][hor]+(i!=dir)))
            {
                if (in[x][y][i][VER][HOR])
                    continue;
                in[x][y][i][VER][HOR]=true;
                Q.push(state(x,y,i,VER,HOR));
            }
        }
    }
    int ans=-1;
    for (int i=0;i<4;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
            {
                int now=d[Tx][Ty][i][j][k];
                if (now==-1)
                    continue;
                if (ver && j==0)
                    now++;
                if (hor && k==0)
                    now++;
                update(ans,now);
            }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        n;
        scanf("%d",&n);
        X.clear();
        Y.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&cx[0][i],&cy[0][i],&cx[1][i],&cy[1][i]);
            X.push_back(cx[1][i]);
            X.push_back(cx[0][i]-1);
            Y.push_back(cy[1][i]);
            Y.push_back(cy[0][i]-1);
        }
        X.push_back(0);
        X.push_back(100000001);
        Y.push_back(0);
        Y.push_back(100000001);
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        memset(block,0,sizeof(block));
        for (int i=1;i<=n;i++)
        {
            int x1=lower_bound(X.begin(),X.end(),cx[0][i])-X.begin()+1;
            int x2=lower_bound(X.begin(),X.end(),cx[1][i])-X.begin()+1;
            int y1=lower_bound(Y.begin(),Y.end(),cy[0][i])-Y.begin()+1;
            int y2=lower_bound(Y.begin(),Y.end(),cy[1][i])-Y.begin()+1;
            for (int x=x1;x<=x2;x++)
                for (int y=y1;y<=y2;y++)
                    block[x][y]=true;
        }
        n=X.size(),m=Y.size();
        static int id=0;
        printf("Labyrinth #%d\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int Sx,Sy,Tx,Ty;
            scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
            bool ver=Sx!=Tx,hor=Sy!=Ty;
            Sx=lower_bound(X.begin(),X.end(),Sx)-X.begin()+1;
            Sy=lower_bound(Y.begin(),Y.end(),Sy)-Y.begin()+1;
            Tx=lower_bound(X.begin(),X.end(),Tx)-X.begin()+1;
            Ty=lower_bound(Y.begin(),Y.end(),Ty)-Y.begin()+1;
            int ans=calc(Sx,Sy,Tx,Ty,ver,hor);
            if (ans==-1)
                printf("Impossible.\n");
            else
                printf("%d\n",ans);
        }
    }
    return(0);
}

