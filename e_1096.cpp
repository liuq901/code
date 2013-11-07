#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int n,s[10][10],d[10][10][10][10],w[20][10][10][10][10];
int main()
{
   int f(int,int,int,int,int);
   double ans;
   int i,j,k,l,t,sum;
   int a[10][10];
   scanf("%d",&n);
   sum=0;
   for (i=1;i<=8;i++)
      for (j=1;j<=8;j++)
      {
         scanf("%d",&a[i][j]);
         sum+=a[i][j];
      }
   memset(s,0,sizeof(s));
   for (i=1;i<=8;i++)
      for (j=1;j<=8;j++)
         s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
   for (i=1;i<=8;i++)
      for (j=1;j<=8;j++)
         for (k=i;k<=8;k++)
            for (l=j;l<=8;l++)
            {
               t=s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1];
               d[i][j][k][l]=t*t;
            }
   memset(w,0,sizeof(w));
   ans=f(n,1,1,8,8)/(double)n-(sum/(double)n)*(sum/(double)n);
   printf("%.3lf\n",sqrt(ans));
   system("pause");
   return(0);
}
int f(int k,int x1,int y1,int x2,int y2)
{
   int min(int,int);
   int ans,a,b,s1,s2;
   if (w[k][x1][y1][x2][y2]!=0)
      return(w[k][x1][y1][x2][y2]);
   ans=20000000;
   if (k==1)
      ans=d[x1][y1][x2][y2];
   else
   {
      for (a=x1;a<x2;a++)
      {
         s1=f(k-1,x1,y1,a,y2)+d[a+1][y1][x2][y2];
         s2=f(k-1,a+1,y1,x2,y2)+d[x1][y1][a][y2];
         if (s1<ans)
            ans=s1;
         if (s2<ans)
            ans=s2;
      }
      for (b=y1;b<y2;b++)
      {
         s1=f(k-1,x1,y1,x2,b)+d[x1][b+1][x2][y2];
         s2=f(k-1,x1,b+1,x2,y2)+d[x1][y1][x2][b];
         if (s1<ans)
            ans=s1;
         if (s2<ans)
            ans=s2;
      }
   }
   w[k][x1][y1][x2][y2]=ans;
   return(ans);
}
