#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,s,x,y;
   scanf("%d",&n);
   i=0;
   while (1)
   {
      i++;
      s=i*(i+1)/2;
      if (s>=n)
         break;
   }
   s=(i-1)*i/2;
   if (i%2==0)
   {
      y=n-s;
      x=i+1-y;
   }
   else
   {
      x=n-s;
      y=i+1-x;
   }
   printf("%d/%d\n",y,x);
   system("pause");
   return(0);
}
