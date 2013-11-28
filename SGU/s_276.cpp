#include <cstdio>
#include <cstdlib>
int main()
{
   int s,p;
   scanf("%d%d",&s,&p);
   if (s>=p)
      printf("0\n");
   else if (p-s<300)
      printf("1\n");
   else if (p-s<900)
      printf("2\n");
   else if (p-s<1800)
      printf("3\n");
   else
      printf("4\n");
   system("pause");
   return(0);
}
