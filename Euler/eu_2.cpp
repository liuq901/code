#include <cstdio>
#include <cstdlib>
int main()
{
   int a=0,b=1,ans=0;
   while (a+b<=4000000)
   {
      int c=a+b;
      a=b,b=c;
      if (c&1)
         continue;
      ans+=c;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
