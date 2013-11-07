#include <cstdio>
#include <cstdlib>
int main()
{
   int x,y,i,j,p,max=0,a[7]={0};
   for (i=0;i<7;i++)
   {
      scanf("%d%d",&x,&y);
      if (x+y>8)
         a[i]=x+y-8;
   }
   for (i=0;i<7;i++)
      if (a[i]>max)
      {
         max=a[i];
         p=i+1;
      }
   if (max==0)
      printf("0\n");
   else
      printf("%d\n",p);
   system("pause");
   return(0);
}
