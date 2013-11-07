#include <cstdio>
#include <cstdlib>
long i,n,x,y;
char a[1000001];
int main()
{
   void work(int);
   i=0;
   while (a[i]!='E')
   {
      i++;
      scanf("%c",&a[i]);
   }
   n=i-1;
   if (n==0)
   {
      printf("0:0\n");
      printf("\n");
      printf("0:0\n");
   }
   else
   {
      work(11);
      printf("\n");
      work(21);
   }
   system("pause");
   return(0);
}
void work(int l)
{
   long i;
   x=0;
   y=0;
   for (i=1;i<=n;i++)
   {
      switch (a[i])
      {
      case 'W':
         x++;
         break;
      case 'L':
         y++;
         break;
      }
      if ((x>=l || y>=l) && (abs(x-y)>=2))
      {
         printf("%d:%d\n",x,y);
         x=0;
         y=0;
      }
   }
   printf("%d:%d\n",x,y);
}
