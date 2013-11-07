#include <cstdio>
#include <cstdlib>
int n,m,a[1001][1001];
int main()
{
   int search(int,int);
   int i,j,max;
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         scanf("%d",&a[i][j]);
   max=0;
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         if (max<search(i,j))
            max=search(i,j);
   printf("%d\n",max);
   system("pause");
   return(0);
}
int search(int x,int y)
{
   int i,j,k,l,flag;
   k=-1;
   while (1)
   {
      k++;
      if (x+k>n && y+k>m)
         break;
      flag=0;
      for (i=x;i<=x+k;i++)
         for (j=y;j<=y+k;j++)
            if (!a[i][j])
            {
               flag=1;
               break;
            }
      if (flag)
         break;
   }
   return(k);
}
