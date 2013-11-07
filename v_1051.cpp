#include <cstdio>
#include <cstdlib>
int a[111][111]={0},b[111][111]={0};
int n,m;
int main()
{
   void go(int,int);
   int i,j,ans,lq1,lq2;
   char ch;
   scanf("%d%d%*c",&n,&m);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=m;j++)
      {
         scanf("%c",&ch);
         if (ch=='-')
            a[i][j]=0;
         if (ch=='#')
            a[i][j]=1;
      }
      scanf("%*c");
   }
   ans=0;
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
         if (a[i][j] && !b[i][j])
         {
            go(i,j);
            ans++;
         }
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void go(int x,int y)
{
   if (!a[x][y])
      return;
   b[x][y]=1;
   if (!b[x-1][y] && a[x-1][y])
      go(x-1,y);
   if (!b[x][y-1] && a[x][y-1])
      go(x,y-1);
   if (!b[x+1][y] && a[x+1][y])
      go(x+1,y);
   if (!b[x][y+1] && a[x][y+1])
      go(x,y+1);
   if (!b[x-1][y-1] && a[x-1][y-1])
      go(x-1,y-1);
   if (!b[x-1][y+1] && a[x-1][y+1])
      go(x-1,y+1);
   if (!b[x+1][y-1] && a[x+1][y-1])
      go(x+1,y-1);
   if (!b[x+1][y+1] && a[x+1][y+1])
      go(x+1,y+1);
   if (!b[x-2][y] && a[x-2][y])
      go(x-2,y);
   if (!b[x+2][y] && a[x+2][y])
      go(x+2,y);
   if (!b[x][y-2] && a[x][y-2])
      go(x,y-2);
   if (!b[x][y+2] && a[x][y+2])
      go(x,y+2);
}
