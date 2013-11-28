#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=1061109567;
const int c[9][2]={{0,0},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
char a[20][20];
int n,m,bomb[20][20],f[20][66000];
int main()
{
   void work(int,int),did(int,int);
   bool can(int,int);
   int calc(int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      n=m=10;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            cin>>a[i][j];
      memset(bomb,0,sizeof(bomb));
      int sum=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            if (a[i][j]=='g')
               work(i,j);
            if (a[i][j]=='e')
            {
               did(i,j);
               sum++;
            }
         }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (a[i][j]=='e' && !can(i,j))
            {
               a[i][j]='.';
               sum--;
            }
      int t=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (a[i][j]=='e')
               a[i][j]=t++;
      int limit=1<<t;
      memset(f,63,sizeof(f));
      f[0][0]=0;
      for (int i=1;i<=t;i++)
         for (int j=1;j<=n;j++)
            for (int k=1;k<=m;k++)
               if (bomb[j][k]==1)
               {
                  int p=calc(j,k);
                  for (int l=0;l<limit;l++)
                     f[i][p|l]=min(f[i][p|l],f[i-1][l]+1);
               }
      int ans=inf;
      for (int i=0;i<=t;i++)
         ans=min(ans,f[i][limit-1]);
      printf("%d %d\n",sum,ans);
   }
   system("pause");
   return(0);
}
void work(int x0,int y0)
{
   for (int i=0;i<9;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (x>0 && x<=n && y>0 && y<=m)
         bomb[x][y]=-1;
   }
}
void did(int x0,int y0)
{
   for (int i=0;i<9;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (x>0 && x<=n && y>0 && y<=m && bomb[x][y]!=-1)
         bomb[x][y]=1;
   }
}
bool can(int x0,int y0)
{
   for (int i=0;i<9;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (x>0 && x<=n && y>0 && y<=m && bomb[x][y]==1)
         return(true);
   }
   return(false);
}
int calc(int x0,int y0)
{
   int ans=0;
   for (int i=0;i<9;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (x>0 && x<=n && y>0 && y<=m && a[x][y]<=16)
         ans+=1<<a[x][y];
   }
   return(ans);
}
