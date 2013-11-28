#include <cstdio>
#include <cstdlib>
int i,j,t,l,x,y,p,q,m,n,tt;
int a[21][21];
int main()
{
   void make();
   int notime();
   scanf("%d%d%d",&m,&n,&tt);
   for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
   make();
   p=0;
   q=y;
   while (t<=tt)
   {
      if (notime())
      {
         printf("%d\n",l);
         break;
      } 
      t+=abs(x-p)+abs(y-q)+1;
      l+=a[x][y];
      a[x][y]=0;
      p=x;
      q=y;
      make();
   }
   system("pause");
   return(0);
}
void make()
{
   int i,j,max;
   max=0;
   for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
         if (a[i][j]>max)
            max=a[i][j],x=i,y=j;
}
int notime()
{
   int s;
   s=abs(x-p)+abs(y-q)+x+1;
   if (s+t>tt)
      return(1);
   else
      return(0);
}
