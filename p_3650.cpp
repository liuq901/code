#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      char ch;
      scanf("%c",&ch);
      if (ch=='#')
         break;
      switch (ch)
      {
      case ' ':
         printf("%%20");
         break;
      case '!':
         printf("%%21");
         break;
      case '$':
         printf("%%24");
         break;
      case '%':
         printf("%%25");
         break;
      case '(':
         printf("%%28");
         break;
      case ')':
         printf("%%29");
         break;
      case '*':
         printf("%%2a");
         break;
      default:
         printf("%c",ch);
         break;
      }
   }
   system("pause");
   return(0);
}
