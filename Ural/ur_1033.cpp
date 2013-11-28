#include <cstdio>
#include <cstdlib>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
   char map[35][35];
   int n;
   scanf("%d%*c",&n);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
         scanf("%c",&map[i][j]);
      map[0][i]=map[n+1][i]=map[i][0]=map[i][n+1]='#';
      scanf("%*c");
   }
   int l,r,q[2000][2];
   bool f[35][35]={0};
   l=1,r=2;
   q[1][0]=q[1][1]=1;
   q[2][0]=q[2][1]=n;
   f[1][1]=f[n][n]=true;
   int s=0;
   while (l<=r)
   {
      for (int i=0;i<4;i++)
      {
         int x=q[l][0]+c[i][0],y=q[l][1]+c[i][1];
         if (map[x][y]=='#')
            s++;
         else if (!f[x][y])
         {
            f[x][y]=true;
            q[++r][0]=x,q[r][1]=y;
         }
      }
      l++;
   }
   printf("%d\n",(s-4)*9);
   system("pause");
   return(0);
}
