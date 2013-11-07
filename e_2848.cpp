#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
bool a[1010][90],vis[1010][90];
char s[100];
int main()
{
   int floodfill(int,int);
   scanf("%d%d",&m,&n);
   gets(s);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         a[i][j]=ch=='*';
      }
      gets(s);
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (a[i][j] && !vis[i][j])
            ans=max(ans,floodfill(i,j));
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int floodfill(int x0,int y0)
{
   int ret=1;
   vis[x0][y0]=true;
   for (int i=0;i<4;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (a[x][y] && !vis[x][y])
         ret+=floodfill(x,y);
   }
   return(ret);
}
