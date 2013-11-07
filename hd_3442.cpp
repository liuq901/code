#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int damage[]={1,2,3,4,5};
const int range[]={2,3,0,2,1};
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
   int x,y,heat;
   state(){}
   state(int _x,int _y,int _heat):x(_x),y(_y),heat(_heat){}
};
char a[60][60];
bool attack[5][60][60],f[60][60][35];
int n,m;
state q[100000];
int main()
{
   void calc(int,int,int);
   int count(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            cin>>a[i][j];
      int Sx,Sy,Tx,Ty;
      memset(attack,0,sizeof(attack));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            if (isalpha(a[i][j]))
               calc(i,j,a[i][j]-'A');
            if (a[i][j]=='$')
               Sx=i,Sy=j;
            if (a[i][j]=='!')
               Tx=i,Ty=j;
         }
      int l,r;
      l=r=1;
      memset(f,0,sizeof(f));
      q[1]=state(Sx,Sy,0);
      f[Sx][Sy][0]=true;
      while (l<=r)
      {
         int x0=q[l].x,y0=q[l].y,P=q[l].heat;
         for (int i=0;i<4;i++)
         {
            int x=x0+c[i][0],y=y0+c[i][1],p=P;
            if (!x || x>n || !y || y>m || isalpha(a[x][y]) && a[x][y]!='C' || a[x][y]=='#')
               continue;
            for (int j=0;j<5;j++)
               if (attack[j][x][y])
                  p|=1<<j;
            if (!f[x][y][p])
            {
               f[x][y][p]=true;
               q[++r]=state(x,y,p);
            }
         }
         l++;
      }
      int ans=1<<30;
      for (int i=0;i<32;i++)
         if (f[Tx][Ty][i])
            ans=min(ans,count(i));
      static int id=0;
      printf("Case %d: ",++id);
      if (ans==1<<30)
         printf("-1\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool vis[60][60];
void calc(int x,int y,int num)
{
   int l,r,q[30][3];
   l=r=1;
   q[1][0]=x,q[1][1]=y,q[1][2]=0;
   vis[x][y]=true;
   while (l<=r)
   {
      int x0=q[l][0],y0=q[l][1];
      if (q[l][2]==range[num])
         break;
      for (int i=0;i<4;i++)
      {
         int x=x0+c[i][0],y=y0+c[i][1];
         if (!x || x>n || !y || y>m || vis[x][y])
            continue;
         q[++r][0]=x,q[r][1]=y,q[r][2]=q[l][2]+1;
         vis[x][y]=true;
      }
      l++;
   }
   for (int i=1;i<=r;i++)
   {
      int x=q[i][0],y=q[i][1];
      attack[num][x][y]=true;
      vis[x][y]=false;
   }
}
int count(int x)
{
   int ans=0;
   for (int i=0;i<5;i++)
      if (x>>i&1)
         ans+=damage[i];
   return(ans);
}
