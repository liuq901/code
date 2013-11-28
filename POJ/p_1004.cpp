#include <cstdio>
#include <cstdlib>
int main()
{
   float s=0;
   for (int i=1;i<=12;i++)
   {
      float x;
      scanf("%f",&x);
      s+=x;
   }
   printf("$%.2f\n",s/12);
   system("pause");
   return(0);
}
