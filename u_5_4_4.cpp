/*
ID: liuq9011
LANG: C++
TASK: betsy
*/
#include <cstdio>
FILE *in,*out;
const int m[5][2]={{0},{1,0},{0,1},{-1,0},{0,-1}};
int n,ans,a[10][10],f[10][10];
int main()
{
   in=fopen("betsy.in","r");
   out=fopen("betsy.out","w");
   void search(int,int,int);
   int i,j;
   fscanf(in,"%d",&n);
   if (n==1)
      fprintf(out,"1\n");
   else
   {
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
            f[i][j]=1;
      for (i=0;i<=n+1;i++)
         for (j=0;j<=n+1;j++)
            a[i][j]=5;
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
         {
            a[i][j]=4;
            if (i==1 || i==n)
               a[i][j]--;
            if (j==1 || j==n)
               a[i][j]--;
         }
      search(1,1,n*n-1);
      fprintf(out,"%d\n",ans);
   }
   fclose(in),fclose(out);
   return(0);
}
void search(int x,int y,int dep)
{
   int check(int,int);
   int i,j,k,x1,y1;
   if (x==n && y==1)
      return;
   if (n-x+y-1>dep)
      return;
   if (dep==1)
   {
      ans++;
      return;
   }
   f[x][y]=0;
   j=1,k=4;
   for (i=1;i<=4;i++)
   {
      x1=x+m[i][0];
      y1=y+m[i][1];
      a[x1][y1]--;
      if (f[x1][y1])
      {
         if (x1!=n || y1!=1) 
         {
            if (a[x1][y1]<=1) 
            {
               j=i;
               k=i;
            }
         } 
         else
            if (a[x1][y1]==0) 
            { 
               j=i;
               k=i;
            }
      }
   }
   for (i=j;i<=k;i++)
      if (f[x+m[i][0]][y+m[i][1]] && check(x+m[i][0],y+m[i][1]))
         search(x+m[i][0],y+m[i][1],dep-1);
   for (i=1;i<=4;i++)
      a[x+m[i][0]][y+m[i][1]]++;
   f[x][y]=1;
}
int check(int x,int y)
{
   if (f[x-1][y] && f[x+1][y] && !f[x][y-1] && !f[x][y+1])
      return(0);
   if (!f[x-1][y] && !f[x+1][y] && f[x][y-1] && f[x][y+1])
      return(0);
   if (!f[x-1][y] && !f[x][y-1] && f[x-1][y-1])
      return(0);
   if (!f[x+1][y] && !f[x][y-1] && f[x+1][y-1])
      return(0);
   if (!f[x-1][y] && !f[x][y+1] && f[x-1][y+1])
      return(0);
   if (!f[x+1][y] && !f[x][y+1] && f[x+1][y+1])
      return(0);
   return(1);
}
