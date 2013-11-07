#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      if (!a && !b && !c)
         break;
      if ((c-a)%b)
      {
         printf("No accounting tablet\n");
         continue;
      }
      printf("%d\n",(abs(c-a)/b+2)/3);
   }
   system("pause");
   return(0);
}
