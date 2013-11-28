#include <cstdio>
#include <cstdlib>
#include <cstring>
const int mod=100000;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool map[60][60];
int dis[60][60],num[60][60],q[4000][2];
int main()
{
   int n,m;
   while (scanf("%d%d",&n,&m)==2)
   {
      memset(dis,63,sizeof(dis));
      for (int i=0;i<n;i++)
         for (int j=0;j<m;j++)
            scanf("%d",&map[i][j]);
      int Sx,Sy,Tx,Ty;
      scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
      num[Tx][Ty]=0;
      int l,r;
      l=r=1,q[1][0]=Sx,q[1][1]=Sy;
      dis[Sx][Sy]=num[Sx][Sy]=1;
      while (l<=r)
      {
         int x0=q[l][0],y0=q[l][1];
         for (int i=0;i<4;i++)
         {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x<0 || x>=n || y<0 || y>=m || map[x][y])
               continue;
            if (dis[x0][y0]+1<dis[x][y])
            {
               q[++r][0]=x,q[r][1]=y;
               dis[x][y]=dis[x0][y0]+1;
               num[x][y]=num[x0][y0];
            }
            else if (dis[x0][y0]+1==dis[x][y])
               num[x][y]=(num[x][y]+num[x0][y0])%mod;
         }
         l++;
      }
      printf("%d\n",num[Tx][Ty]);
   }
   system("pause");
   return(0);
}
