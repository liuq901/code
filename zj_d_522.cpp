#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct grid
{
   int x,y,value;
};
bool operator <(grid a,grid b)
{
   return(a.value<b.value);
}
grid a[10010];
bool f[110][110];
int b[110][110],d[110][110];
int main()
{
   int n,K;
   scanf("%d%d",&n,&K);
   int t=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         scanf("%d",&a[++t].value);
         b[i][j]=a[t].value;
         a[t].x=i,a[t].y=j;
      }
   sort(a+1,a+n*n+1);
   int ans=b[1][1];
   f[1][1]=true;
   memset(d,-63,sizeof(d));
   d[1][1]=b[1][1];
   for (int i=1;i<=n*n;i++)
   {
      if (!f[a[i].x][a[i].y])
         continue;
      for (int j=0;j<4;j++)
      {
         int x=a[i].x,y=a[i].y;
         for (int k=1;k<=K;k++)
         {
            x+=c[j][0],y+=c[j][1];
            if (x<=0 || x>n || y<=0 || y>n)
               break;
            if (b[x][y]>a[i].value)
            {
               d[x][y]=max(d[x][y],d[a[i].x][a[i].y]+b[x][y]);
               ans=max(ans,d[x][y]);
               f[x][y]=true;
            }
         }
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
