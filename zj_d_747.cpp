#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
   int x,y,v;
   state(int x,int y,int v):x(x),y(y),v(v){}
};
bool operator <(state a,state b)
{
   return(a.v>b.v);
}
priority_queue <state> q;
int vis[1010][1010],dis[1010][1010];
char map[1010][1010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=0;i<n;i++)
      scanf("%s",map[i]);
   for (int id=1;id<=m;id++)
   {
      int Sx,Sy,Tx,Ty;
      scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
      if (map[Sx][Sy]=='X' || map[Tx][Ty]=='X')
      {
         printf("ERROR\n");
         continue;
      }
      if (Tx==Sx && Ty==Sy)
      {
         printf("0\n");
         continue;
      }
      while (!q.empty())
         q.pop();
      int ans=-1;
      q.push(state(Sx,Sy,abs(Sx-Tx)+abs(Sy-Ty)));
      dis[Sx][Sy]=0;
      vis[Sx][Sy]=id;
      while (!q.empty())
      {
         int x0=q.top().x,y0=q.top().y,d=dis[x0][y0];
         for (int i=0;i<4;i++)
         {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x==-1 || x==n || y==-1 || y==n || map[x][y]=='X')
               continue;
            if (x==Tx && y==Ty)
            {
               ans=d+1;
               break;
            }
            if (vis[x][y]!=id || d+1<dis[x][y])
            {
               vis[x][y]=id;
               dis[x][y]=d+1;
               q.push(state(x,y,dis[x][y]+abs(x-Tx)+abs(y-Ty)));
            }
         }
         if (ans!=-1)
            break;
         q.pop();
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
