#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int inf=1<<30;
int p,n,m,pos[20][3],d[20][20],f[140000][20],a[260][260];
int main()
{
   void bfs(int);
   int check(int,int);
   while (scanf("%d%d",&n,&m)==2)
   {
      p=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            scanf("%d",&a[i][j]);
            if (a[i][j]>0)
               pos[++p][0]=i,pos[p][1]=j,pos[p][2]=a[i][j];
         }
      if (n==1 && m==1)
      {
         printf("%d\n",a[1][1]);
         continue;
      }
      if (!a[1][1])
      {
         printf("you loss!\n");
         continue;
      }
      for (int i=1;i<=p;i++)
         bfs(i);
      memset(f,-63,sizeof(f));
      f[1][1]=a[1][1];
      int ans=check(f[1][1],d[1][p+1]);
      for (int i=2;i<1<<p;i++)
      {
         int b[20];
         b[0]=0;
         for (int j=1;j<=p;j++)
            if (i&1<<j-1)
               b[++b[0]]=j;
         for (int j=1;j<=b[0];j++)
         {
            int now=i-(1<<b[j]-1);
            for (int k=1;k<=b[0];k++)
            {
               if (j==k)
                  continue;
               f[i][b[j]]=max(f[i][b[j]],check(f[now][b[k]],d[b[k]][b[j]])+pos[b[j]][2]);
            }
            ans=max(ans,check(f[i][b[j]],d[b[j]][p+1]));
         }
      }
      if (ans<0)
         printf("you loss!\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int dist[260][260],q[70000][2];
bool vis[260][260];
void bfs(int id)
{
   memset(dist,63,sizeof(dist));
   memset(vis,0,sizeof(vis));
   int l,r;
   l=r=1,q[1][0]=pos[id][0],q[1][1]=pos[id][1];
   dist[q[1][0]][q[1][1]]=0,vis[q[1][0]][q[1][1]]=true;
   while (l<=r)
   {
      int x0=q[l][0],y0=q[l++][1];
      for (int i=0;i<4;i++)
      {
         int x=x0+c[i][0],y=y0+c[i][1];
         if (x>0 && x<=n && y>0 && y<=m && a[x][y]>=0 && !vis[x][y])
         {
            dist[x][y]=dist[x0][y0]+1;
            q[++r][0]=x,q[r][1]=y;
            vis[x][y]=true;
         }
      }
   }
   for (int i=1;i<=p;i++)
      d[id][i]=dist[pos[i][0]][pos[i][1]];
   d[id][p+1]=dist[n][m];
}
int check(int power,int dist)
{
   if (power<dist)
      return(-inf);
   return(power-dist);
}
