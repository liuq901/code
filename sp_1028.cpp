#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int x;
      scanf("%*d%d",&x);
      printf("%s\n",x?"Pagfloyd wins.":"Airborne wins.");
   }
   system("pause");
   return(0);
}
