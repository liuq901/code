#include <cstdio>
#include <cstdlib>
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
bool map[2][110][110];
int main()
{
   int n,m,t;
   scanf("%d%d%d%*c",&m,&n,&t);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         map[1][i][j]=ch=='1';
      }
      scanf("%*c");
   }
   for (int p=2;p<=t;p++)
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            int s=0;
            for (int k=0;k<8;k++)
            {
               int x=c[k][0]+i,y=c[k][1]+j;
               s+=map[p-1&1][x][y];
            }
            if (map[p-1&1][i][j] && (s<2 || s>3))
               map[p&1][i][j]=false;
            else if (!map[p-1&1][i][j] && s!=3)
               map[p&1][i][j]=false;
            else
               map[p&1][i][j]=true;
         }
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
         printf("%d",map[t&1][i][j]);
      printf("\n");
   }
   system("pause");
   return(0);
}
