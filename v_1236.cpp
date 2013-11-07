#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[4001],f[4001];
int main()
{
   int search(int,int);
   int i,n,tot,mark;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   mark=1;
   tot=0;
   memset(f,0,sizeof(f));
   for (i=4;i<=n;i++)
      if (search(mark,i))
      {
         tot++;
         mark=i+1;
      }
   printf("%d\n",tot);
   system("pause");
   return(0);
}
int search(int x,int y)
{
   int mark,i,j;
   mark=0;
   for (i=x;i<=y;i++)
      f[i]=1;
   for (i=x;i<=y;i++)
      for (j=x;j<=y;j++)
         if (a[i]==a[j] && i!=j)
            f[i]++;
   for (i=x;i<=y;i++)
      if (f[i]>4)
         return(1);
   for (i=x;i<=y;i++)
   {
      if (f[i]>=2)
         mark++;
      if (mark>=4)
         return(1);
   }
   return(0);
}
