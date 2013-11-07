#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct point
{
   int x,y;   
   bool operator !=(point a)
   {
      if (x!=a.x || y!=a.y)
         return(true);
      return(false);
   }
};
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
bool flag[301][301],map[310][310],f[2][1001][1001];
int dist[301][301],d[301][301],q[90001][2],pos[301][301][2];
vector <point> a[1001],b[1001];
void work()
{
   int n=0;
   scanf("%d%*c",&n);
   int xa,ya,xb,yb;
   memset(map,false,sizeof(map));
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         char ch;
         scanf("%c",&ch);
         if (ch=='#')
            continue;
         map[i][j]=true;
         if (ch=='A')
            xa=i,ya=j;
         if (ch=='B')
            xb=i,yb=j;
      }
      scanf("%*c");
   }
   int l,r;
   memset(flag,false,sizeof(flag));
   flag[xa][ya]=true;
   l=r=1;
   q[1][0]=xa;
   q[1][1]=ya;
   dist[xa][ya]=0;
   while (l<=r)
   {
      for (int i=0;i<4;i++)
      {
         int x=q[l][0]+c[i][0],y=q[l][1]+c[i][1];
         if (!map[x][y] || flag[x][y])
            continue;
         flag[x][y]=true;
         dist[x][y]=dist[q[l][0]][q[l][1]]+1;
         r++;
         q[r][0]=x;
         q[r][1]=y;
      }
      l++;
   }
   memset(flag,false,sizeof(flag));
   flag[xb][yb]=true;
   l=r=1;
   q[1][0]=xb;
   q[1][1]=yb;
   d[xb][yb]=0;
   while (l<=r)
   {
      for (int i=0;i<4;i++)
      {
         int x=q[l][0]+c[i][0],y=q[l][1]+c[i][1];
         if (!map[x][y] || flag[x][y])
            continue;
         flag[x][y]=true;
         d[x][y]=d[q[l][0]][q[l][1]]+1;
         r++;
         q[r][0]=x;
         q[r][1]=y;
      }
      l++;
   }
   int sum=dist[xb][yb];
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         if (dist[i][j]+d[i][j]!=sum)
            map[i][j]=false;
   if (sum%2==1)
   {
      printf("A\n");
      return;
   }
   sum/=2;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (!map[i][j])
            continue;
         point tmp;
         tmp.x=i;
         tmp.y=j;
         if (dist[i][j]<=sum)
         {
            a[dist[i][j]].push_back(tmp);
            pos[i][j][0]=a[dist[i][j]].size()-1;
         }
         if (d[i][j]<=sum)
         {
            b[d[i][j]].push_back(tmp);
            pos[i][j][1]=b[d[i][j]].size()-1;
         }
      }
   for (int i=0;i<a[sum].size();i++)
      for (int j=0;j<b[sum].size();j++)
         if (a[sum][i]!=b[sum][j])
            f[sum&1][i][j]=true;
         else
            f[sum&1][i][j]=false;
   for (int dep=sum-1;dep>=0;dep--)
      for (int k1=0;k1<a[dep].size();k1++)
         for (int k2=0;k2<b[dep].size();k2++)
         {
            bool flag;
            for (int i=0;i<4;i++)
            {
               int x=a[dep][k1].x+c[i][0],y=a[dep][k1].y+c[i][1];
               if (!map[x][y] || dist[x][y]!=dep+1)
                  continue;
               int aa=pos[x][y][0];
               flag=true;
               for (int j=0;j<4;j++)
               {
                  int x=b[dep][k2].x+c[j][0],y=b[dep][k2].y+c[j][1];
                  if (!map[x][y] || d[x][y]!=dep+1)
                     continue;
                  int bb=pos[x][y][1];
                  if (!f[dep+1&1][aa][bb])
                  {
                     flag=false;
                     break;
                  }
               }
               if (flag)
                  break;
            }
            f[dep&1][k1][k2]=flag;
         }
   if (f[0][0][0])
      printf("A\n");
   else
      printf("B\n");
}
