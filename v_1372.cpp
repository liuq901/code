#include <cstdio>
#include <cstdlib>
int main()
{
   int i,bo,a[101];
   long long x,y,z;
   scanf("%I64d%I64d",&x,&y);
   if (x>=y)
      bo=1;
   else
   {
      bo=0;
      z=x;
      x=y;
      y=z;
   }
   a[0]=0;
   while (x>=1000)
   {
      a[0]++;
      a[a[0]]=x%1000-y%1000;
      x/=1000;
      y/=1000;
      if (a[a[0]]<0)
      {
         a[a[0]]+=1000;
         x--;
      }
      if (a[a[0]]>1000)
      {
         a[a[0]]-=1000;
         x++;
      }
   }
   if (!bo)
      printf("-");
   printf("%I64d",x-y);
   for (i=a[0];i>=1;i--)
   {
      printf(",");
      if (a[i]>=1 && a[i]<=9)
         printf("00%d",a[i]);
      if (a[i]>=10 && a[i]<=99)
         printf("0%d",a[i]);
      if (a[i]>=100 && a[i]<=999)
         printf("%d",a[i]);
   }
   printf("\n");
   system("pause");
   return(0);
}
