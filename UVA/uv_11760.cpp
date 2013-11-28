#include <cstdio>
#include <cstdlib>
#include <cstring>
bool f[10010],g[10010];
int r,c;
int main()
{
   bool check(int,int);
   while (1)
   {
      int n;
      scanf("%d%d%d",&r,&c,&n);
      if (!r && !c && !n)
         break;
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         f[x]=true,g[y]=true;
      }
      int x0,y0;
      bool flag=false;
      scanf("%d%d",&x0,&y0);
      for (int i=-1;i<=1;i++)
         for (int j=-1;j<=1;j++)
         {
            if (abs(i)+abs(j)==2)
               continue;
            if (check(x0+i,y0+j))
               flag=true;
         }
      static int id=0;
      printf("Case %d: %s\n",++id,flag?"Escaped again! More 2D grid problems!":"Party time! Let's find a restaurant!");
   }
   system("pause");
   return(0);
}
bool check(int x,int y)
{
   if (x<0 || x==r || y<0 || y==c)
      return(false);
   return(!f[x] && !g[y]);
}
