#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      char s[100];
      scanf("%s",s);
      switch (s[0])
      {
      case 'E':
         printf("Excellent\n");
         break;
      case 'C':
         printf("Cheer\n");
         break;
      case 'N':
         printf("Nice\n");
         break;
      case 'U':
         printf("Ultimate\n");
         break;
      case 'I':
         printf("I'm possible\n");
         break;
      case 'A':
         printf("Accept More\n");
         break;
      }
   }
   system("pause");
   return(0);
}
