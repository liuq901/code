#include <cstdio>
#include <cstdlib>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
   int n,m;
   while (scanf("%d%d%*c",&n,&m)!=EOF)
   {
      char map[202][202];
      int x0,y0,x1,y1;
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=m;j++)
         {
            scanf("%c",&map[i][j]);
            if (map[i][j]=='S')
               x0=i,y0=j;
            if (map[i][j]=='T')
               x1=i,y1=j;
         }
         scanf("%*c");
      }
      for (int i=1;i<=n;i++)
         map[i][0]=map[i][m+1]='#';
      for (int i=1;i<=m;i++)
         map[0][i]=map[n+1][i]='#';
      int l,r,q[40001][2],d[201][201];
      bool f[201][201]={0};
      memset(d,26,sizeof(d));
      d[x0][y0]=0;
      q[1][0]=x0,q[1][1]=y0;
      f[x0][y0]=true;
      l=0,r=1;
      while (l!=r)
      {
         l++;
         if (l>n*m)
            l=1;
         int x=q[l][0],y=q[l][1];
         for (int i=0;i<4;i++)
         {
            int p;
            if (map[x+c[i][0]][y+c[i][1]]=='#')
               continue;
            else if (map[x+c[i][0]][y+c[i][1]]=='X')
               p=2;
            else
               p=1;
            if (d[x][y]+p<d[x+c[i][0]][y+c[i][1]])
            {
               d[x+c[i][0]][y+c[i][1]]=d[x][y]+p;
               if (!f[x+c[i][0]][y+c[i][1]])
               {
                  f[x+c[i][0]][y+c[i][1]]=true;
                  r++;
                  if (r>n*m)
                     r=1;
                  q[r][0]=x+c[i][0];
                  q[r][1]=y+c[i][1];
               }
            }
         }
         f[x][y]=false;
      }
      if (d[x1][y1]<20000000)
         printf("%d\n",d[x1][y1]);
      else
         printf("impossible\n");
   }
   system("pause");
   return(0);
}
