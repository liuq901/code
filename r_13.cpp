#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,l,m,x,y,a[10001]={0};
   scanf("%d%d",&l,&m);
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      for (j=x;j<=y;j++)
         a[j]=1;
   }
   x=0;
   for (i=0;i<=l;i++)
      if (a[i]==0)
         x++;
   printf("%d\n",x);
   system("pause");
   return(0);
}
