#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int a,b,c,d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      if (!a || !b || !c || !d)
         break;
      double p=a*d-b*c;
      if (p)
         printf("%.5f %.5f\n%.5f %.5f\n",d/p,-b/p,-c/p,a/p);
      else
         printf("cheat!\n");
   }
   system("pause");
   return(0);
}
