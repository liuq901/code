#include <cstdio>
#include <cstdlib>
int main()
{
   int a,b,c;
   while (scanf("%d%d",&a,&b)!=EOF)
   {
      c=(a*2+b)%3;
      if (c==0)
         printf("ÆÕÍ¨\n");
      else if (c==1)
         printf("¼ª\n");
      else
         printf("´ó¼ª\n");
   }
   system("pause");
   return(0);
}
