#include <cstdio>
#include <cstdlib>
#include <cstring>
int d[110],b[110],c[610][2],a[100000][3];
bool vis[610];
int main()
{
   void floodfill(int,int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      memset(c,0,sizeof(c));
      for (int i=1;i<=m;i++)
      {
         int K;
         scanf("%d",&K);
         for (int j=1;j<=K;j++)
         {
            int x;
            scanf("%d",&x);
            x++;
            if (!c[x][0])
               c[x][0]=i;
            else
               c[x][1]=i;
         }
      }
      for (int i=1;i<=n;i++)
         if (!c[i][1])
            c[i][1]=c[i][0];
      memset(b,0,sizeof(b));
      memset(d,0,sizeof(d));
      for (int i=1;i<=n;i++)
      {
         int x=c[i][0],y=c[i][1];
         d[x]++,d[y]++;
         a[i][0]=y,a[i][1]=i,a[i][2]=b[x],b[x]=i;
         a[i+n][0]=x,a[i+n][1]=i,a[i+n][2]=b[y],b[y]=i+n;
      }
      int tot=0;
      for (int i=1;i<=m;i++)
         if (d[i]&1)
            tot++;
      if (tot==2 || !tot)
      {
         memset(vis,0,sizeof(vis));
         for (int i=1;i<=m;i++)
            if (d[i])
            {
               floodfill(i,0);
               break;
            }
         bool flag=true;
         for (int i=1;i<=m;i++)
            if (d[i] && !vis[i])
            {
               flag=false;
               break;
            }
         if (flag)
            for (int i=1;i<=n;i++)
            {
               bool flag=true;
               int x=c[i][0],y=c[i][1];
               if (tot==2 && !(d[x]&1) && !(d[y]&1))
                  continue;
               memset(vis,0,sizeof(vis));
               d[x]--,d[y]--;
               if (d[x])
                  floodfill(x,i);
               else
                  floodfill(y,i);
               for (int j=1;j<=m;j++)
                  if (d[j] && !vis[j])
                  {
                     flag=false;
                     break;
                  }
               d[x]++,d[y]++;
               if (flag)
               {
                  printf("%d\n",i-1);
                  break;
               }
            }
         else
            printf("-1\n");
      }
      else
         printf("-1\n");
   }
   system("pause");
   return(0);
}
void floodfill(int x,int p)
{
   vis[x]=true;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (!vis[y] && a[i][1]!=p)
         floodfill(y,p);
   }
}
