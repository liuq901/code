#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int c[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char a[10][10];
int main()
{
   bool dfs(int);
   int T;
   bool first=true;
   scanf("%d",&T);
   while (T--)
   {
      for (int i=1;i<=7;i++)
         for (int j=1;j<=7;j++)
            cin>>a[i][j];
      if (!first)
         printf("\n");
      first=false;
      static int id=0;
      printf("Dataset %d:\n",++id);
      if (!dfs(1))
         printf("No solution.\n");
   }
   system("pause");
   return(0);
}
int ans[10000][4];
bool dfs(int dep)
{
   int sum=0;
   bool in=false;
   for (int i=1;i<=7;i++)
      for (int j=1;j<=7;j++)
         if (a[i][j]=='o' || a[i][j]=='O')
         {
            sum++;
            if (a[i][j]=='O')
               in=true;
         }
   if (sum==1 && in)
   {
      for (int i=1;i<dep;i++)
         printf("%d. (%d, %d) to (%d, %d)\n",i,ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
      return(true);
   }
   for (int i=1;i<=7;i++)
      for (int j=1;j<=7;j++)
         if (a[i][j]=='o' || a[i][j]=='O')
            for (int k=0;k<4;k++)
            {
               int x=i+c[k][0],y=j+c[k][1],p=x+c[k][0],q=y+c[k][1];
               if (x<0 || x>7 || y<0 || y>7 || p<0 || p>7 || q<0 || q>7)
                  continue;
               if ((a[x][y]=='o' || a[x][y]=='O') && (a[p][q]=='e' || a[p][q]=='E'))
               {
                  ans[dep][0]=j,ans[dep][1]=i,ans[dep][2]=q,ans[dep][3]=p;
                  a[i][j]+='e'-'o';
                  a[x][y]+='e'-'o';
                  a[p][q]+='o'-'e';
                  if (dfs(dep+1))
                     return(true);
                  a[p][q]+='e'-'o';
                  a[x][y]+='o'-'e';
                  a[i][j]+='o'-'e';
               }
            }
   return(false);
}
