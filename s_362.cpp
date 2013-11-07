#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,n,m,x,y;
   int f[20][20];
   scanf("%d%d",&n,&m);
   if (n!=1 || m!=1)
   {
      memset(f,0,sizeof(f));
      for (i=1;i<=n;i++)
      {
         f[i][0]=1;
         f[i][m+1]=1;
      }
      for (i=1;i<=m;i++)
      {
         f[0][i]=1;
         f[n+1][i]=1;
      }
      scanf("%d%d",&x,&y);
      while (1)
      {
         f[x][y]=1;
         if (!f[x+1][y])
         {
            x++;
            printf("D");
            continue;
         }
         if (!f[x][y-1])
         {
            y--;
            printf("L");
            continue;
         }
         if (!f[x-1][y])
         {
            x--;
            printf("U");
            continue;
         }
         if (!f[x][y+1])
         {
            y++;
            printf("R");
            continue;
         }
         break;
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
