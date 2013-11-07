#include <cstdio>
#include <cstdlib>
int main()
{
   long flag=1,i,j,x,y=0,s=0;
   for (i=1;i<=12;i++)
   {
      s+=300;
      scanf("%ld",&x);
      if (s-x<0)
      {
         printf("%ld\n",-i);
         flag=0;
         break;
      }
      s-=x;
      y+=s/100*100;
      s%=100;
   }
   if (flag==1)
      printf("%ld\n",s+y+y/5);
   system("pause");
   return(0);
}
